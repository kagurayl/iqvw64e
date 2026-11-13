"""Run both actual instruction streams under Unicorn with identical kernel stubs.

This does not load either driver and cannot certify real kernel equivalence.
"""
from pathlib import Path
import json, re, struct, hashlib
import pefile
from unicorn import Uc, UC_ARCH_X86, UC_MODE_64, UC_HOOK_CODE, UC_HOOK_INSN
from unicorn.x86_const import *

ROOT=Path(__file__).resolve().parent.parent
ORIGINAL=ROOT.parent/'iqvw64e.sys'
BUILT=ROOT/'build/Release/iqvw64e.sys'
MAP=(ROOT/'build/Release/iqvw64e.map').read_text()
symbols={m[1]:int(m[2],16) for m in re.finditer(r'^\s+\w+:\w+\s+(\S+)\s+([0-9A-Fa-f]{16})\s',MAP,re.M)}
original_symbols={r['name']:int(r['address'],16) for r in json.loads((ROOT/'dev/original_functions.json').read_text())}
assert symbols['nal_data_tail']-symbols['nal_data']==0x200, 'Global backing storage lost contiguity'

BUF=0x2000000
STACK=0x1000000
HEAP=0x3000000
STUB=0x5000000
STOP=STUB+0xf000
MASK=(1<<64)-1
REGS=[UC_X86_REG_RCX,UC_X86_REG_RDX,UC_X86_REG_R8,UC_X86_REG_R9]
def q(n): return struct.pack('<Q',n&MASK)
def d(n): return struct.pack('<I',n&0xffffffff)

class Runner:
    def __init__(self,path,names,data):
        self.names=names; self.data=data
        self.pe=pefile.PE(str(path)); self.base=self.pe.OPTIONAL_HEADER.ImageBase
        self.uc=Uc(UC_ARCH_X86,UC_MODE_64)
        size=(self.pe.OPTIONAL_HEADER.SizeOfImage+0xfff)&~0xfff
        self.uc.mem_map(self.base,size)
        self.image=self.pe.get_memory_mapped_image().ljust(size,b'\0')
        self.uc.mem_write(self.base,self.image)
        self.uc.mem_map(STACK,0x20000)
        self.uc.mem_map(BUF,0x20000)
        self.uc.mem_map(HEAP,0x800000)
        self.uc.mem_map(STUB,0x10000)
        self.uc.mem_write(STUB,b'\xc3'*0x10000)
        self.stubs={}
        for desc in self.pe.DIRECTORY_ENTRY_IMPORT:
            for imp in desc.imports:
                at=STUB+len(self.stubs)*0x10
                self.stubs[at]=imp.name.decode()
                self.uc.mem_write(imp.address,q(at))
        self.uc.hook_add(UC_HOOK_CODE,self.hook)
        self.uc.hook_add(UC_HOOK_INSN,self.port_in,None,1,0,UC_X86_INS_IN)
        self.uc.hook_add(UC_HOOK_INSN,self.port_out,None,1,0,UC_X86_INS_OUT)
        self.initial=bytes(self.uc.mem_read(self.data,0x5ca000))
        self.reset()
    def reset(self):
        self.uc.mem_write(self.data,self.initial)
        self.uc.mem_write(STACK,bytes(0x20000))
        self.uc.mem_write(BUF,bytes(0x20000))
        self.uc.mem_write(HEAP,bytes(0x800000))
        self.next_heap=HEAP; self.trace=[]; self.ticks=1000000
        self.fail=set()
    def getq(self,at): return struct.unpack('<Q',self.uc.mem_read(at,8))[0]
    def alloc(self,n):
        p=self.next_heap; self.next_heap+=(n+0xfff)&~0xfff
        if self.next_heap>HEAP+0x800000: raise RuntimeError('Mock heap exhausted')
        return p
    def port_in(self,uc,port,size,user):
        self.trace.append(['in',port,size]); return (0x12345678^port)&((1<<(size*8))-1)
    def port_out(self,uc,port,size,value,user): self.trace.append(['out',port,size,value])
    def hook(self,uc,at,size,user):
        if at==STOP: uc.emu_stop(); return
        if at not in self.stubs: return
        name=self.stubs[at]
        a=[uc.reg_read(r) for r in REGS]
        rsp=uc.reg_read(UC_X86_REG_RSP)
        a.extend(self.getq(rsp+0x28+i*8) for i in range(5))
        ret=0
        if name in self.fail: ret=0
        elif name=='MmGetPhysicalAddress': ret=a[0]+0x10000000
        elif name=='KeQueryPerformanceCounter':
            self.ticks+=10000; ret=self.ticks
            if a[0]: uc.mem_write(a[0],q(10000000))
        elif name in ['MmAllocateContiguousMemory','ExAllocatePoolWithTag']:
            n=a[0] if name.startswith('Mm') else a[1]
            ret=self.alloc(n)
            self.trace.append([name,n])
        elif name=='MmMapIoSpace':
            ret=self.alloc(a[1]); self.trace.append([name,a[0],a[1],a[2]])
        elif name=='IoAllocateMdl':
            ret=self.alloc(0x100); uc.mem_write(ret+44,d(a[0]&0xfff))
            self.trace.append([name,a[0],a[1]])
        elif name=='MmMapLockedPagesSpecifyCache': ret=self.alloc(0x4000)
        elif name in ['MmFreeContiguousMemory','MmUnmapIoSpace','MmUnmapLockedPages','IoFreeMdl','ExFreePoolWithTag','IofCompleteRequest','KeStallExecutionProcessor']:
            count={'MmUnmapIoSpace':2,'MmUnmapLockedPages':2,'ExFreePoolWithTag':2,'IofCompleteRequest':2}.get(name,1)
            self.trace.append([name,*a[:count]])
        elif name in ['memmove','memcpy']:
            uc.mem_write(a[0],bytes(uc.mem_read(a[1],a[2]))); ret=a[0]
        elif name=='memset': uc.mem_write(a[0],bytes([a[1]&255])*a[2]); ret=a[0]
        elif name=='MmBuildMdlForNonPagedPool': pass
        elif name=='IoGetDeviceInterfaces':
            p=self.alloc(0x1000); uc.mem_write(a[3],q(p))
        elif name=='RtlInitUnicodeString':
            n=0
            if a[1]:
                while bytes(uc.mem_read(a[1]+n,2))!=b'\0\0': n+=2
            uc.mem_write(a[0],struct.pack('<HHIQ',n,n+2 if a[1] else 0,0,a[1]))
        elif name=='KeInitializeEvent': uc.mem_write(a[0],bytes(24))
        elif name=='KeGetCurrentIrql': ret=0
        elif name in ['DbgPrint','ObfDereferenceObject']: pass
        else: raise RuntimeError('Unimplemented import: '+name)
        uc.reg_write(UC_X86_REG_RAX,ret&MASK)
    def call(self,name,args=()):
        rsp=STACK+0x18008
        self.uc.mem_write(rsp,q(STOP)+bytes(0x100))
        for r in [UC_X86_REG_RAX,UC_X86_REG_RBX,UC_X86_REG_RBP,UC_X86_REG_RSI,UC_X86_REG_RDI,UC_X86_REG_R10,UC_X86_REG_R11,UC_X86_REG_R12,UC_X86_REG_R13,UC_X86_REG_R14,UC_X86_REG_R15]:
            self.uc.reg_write(r,0)
        for i,r in enumerate(REGS): self.uc.reg_write(r,args[i]&MASK if i<len(args) else 0)
        for i,a in enumerate(args[4:]): self.uc.mem_write(rsp+0x28+8*i,q(a))
        self.uc.reg_write(UC_X86_REG_RSP,rsp)
        self.uc.emu_start(self.names[name],STOP,count=10000000)
        if self.uc.reg_read(UC_X86_REG_RIP)!=STOP: raise RuntimeError('Instruction budget exceeded: '+name)
        return self.uc.reg_read(UC_X86_REG_RAX)
    def snapshot(self):
        # Cookie globals depend on image address; the three runtime tables do not.
        return [bytes(self.uc.mem_read(BUF,0x20000)),bytes(self.uc.mem_read(self.data+0x120,0x5ca000-0x120)),self.trace]

old=Runner(ORIGINAL,original_symbols,0x17000)
new=Runner(BUILT,symbols,symbols['nal_data'])
results=[]
def case(label,setup,steps):
    snapshots=[]
    try:
        for r in [old,new]:
            r.reset(); setup(r)
            returns=[]
            for name,args,mask in steps:
                v=r.call(name,args); returns.append(None if mask is None else v&mask)
            snapshots.append([returns,r.snapshot()])
        ok=snapshots[0]==snapshots[1]
        reason=''
        if not ok:
            reason='; '.join(k for k,a,b in zip(['returns','memory/trace'],snapshots[0],snapshots[1]) if a!=b)
        results.append({'case':label,'passed':ok,'difference':reason})
    except Exception as e: results.append({'case':label,'passed':False,'error':str(e)})
def writebuf(r): r.uc.mem_write(BUF,bytes(range(256))*16)

U32=0xffffffff
for name,args,mask in [
    ('sub_11210',[],U32),('sub_13DF0',[],U32),('sub_13100',[],U32),
    ('sub_11C20',[0x1234],255),('sub_11C30',[0x1234],65535),('sub_11C40',[0x1234],U32),
    ('sub_11C50',[0x1234,0xa5],255),('sub_11C60',[0x1234,0xa55a],255),('sub_11C80',[0x1234,0xfedcba98],255),
    ('sub_11C90',[BUF],255),('sub_11CB0',[BUF],65535),('sub_11CD0',[BUF],U32),
    ('sub_11CF0',[BUF,0x76],255),('sub_11D10',[BUF,0x7654],255),('sub_11D30',[BUF,0x76543210],255),
    ('sub_11C90',[0],255),('sub_11CB0',[0],65535),('sub_11CD0',[0],U32),
    ('sub_11ED0',[BUF],U32),('sub_11EF0',[BUF],U32),('sub_11F10',[BUF,0x03020100,42],U32),
    ('sub_12010',[BUF],MASK),('sub_12010',[0],MASK),('sub_11DE0',[BUF,0],MASK),
    ('sub_11E70',[BUF,0x76,123],MASK),('sub_11EA0',[BUF,BUF+16,123],MASK),
    ('sub_11EA0',[BUF+16,BUF,123],MASK),('sub_11D50',[123],None),('sub_123C0',[2],None),
    ('sub_13E00',[BUF],255),('sub_13E00',[0],255),('sub_11330',[0],U32),
    ('sub_113C0',[0],U32),('sub_11A60',[0],U32),('sub_13FA0',[0],U32),
    ('sub_13740',[],65535),('sub_13540',[BUF],MASK),('sub_13640',[BUF,BUF+0x1000],U32),
]: case(name+str(args),writebuf,[(name,args,mask)])

# Adapter membership lifecycle, including table aliasing and duplicate handling.
case('adapter membership lifecycle',writebuf,[('sub_11220',[BUF,1],255),('sub_11220',[BUF,1],255),('sub_112F0',[BUF],255),('sub_11220',[BUF,0],255),('sub_112F0',[BUF],255)])
for user in [0,42]:
    case('contiguous allocation '+str(user),lambda r:None,[('sub_12520',[1024,256,user,BUF],MASK),('sub_12770',[HEAP if not user else HEAP+0x2000,user],None)])
case('allocation wrapper',lambda r:None,[('sub_128B0',[123,64,BUF],MASK),('sub_128E0',[HEAP],None)])
case('physical mapping',lambda r:r.uc.mem_write(BUF+16,d(4096)),[('sub_12AC0',[BUF,0x12345000,BUF+16],U32),('sub_121C0',[HEAP,0,4096],U32)])
case('user physical mapping',lambda r:r.uc.mem_write(BUF+16,d(4096)),[('sub_129C0',[BUF,0x12345000,BUF+16,42],U32),('sub_11DE0',[HEAP+0x2000,42],MASK),('sub_12220',[HEAP+0x2000,0,4096,42],U32)])

# Drive actual request dispatch for deterministic memory, atomic, and stub cases.
for func in [1,2,3,7,8,9,13,14,15,19,20,21,25,26,27,35,36,37,38,39,40,41,42,48,49,50,51,54,55,56,57,58,59,0xffff]:
    def setup(r,func=func):
        r.uc.mem_write(BUF,q(func)+q(0)+q(BUF+0x2000)+q(BUF+0x1000)+q(16)+q(0)+q(0))
        r.uc.mem_write(BUF+0x1000,bytes(range(256))*4)
        if func in [25,57]: r.uc.mem_write(BUF+40,d(4096))
        if func==38: r.uc.mem_write(BUF+24,d(128)+d(16))
        if func==55: r.uc.mem_write(BUF+24,d(128)+d(16)+q(0)+q(0))
        if func in [40,41,42]: r.uc.mem_write(BUF+24,q(BUF+0x1000))
        if func in [35,36]: r.uc.mem_write(BUF+16,d(2))
        if func==54: r.uc.mem_write(BUF+16,b'\0')
        if func==48: r.uc.mem_write(BUF+16,d(0x76))
    case('general dispatcher function '+str(func),setup,[('sub_113C0',[BUF],U32)])

for code in [0x80862007,0x8086200b,0x8086200f,0x80862013,0xdeadbeef]:
    for nullbuf in [False,True]:
        def setup(r,code=code,nullbuf=nullbuf):
            r.uc.mem_write(BUF+0xb8,q(BUF+0x1000))
            r.uc.mem_write(BUF+0x1000+0x18,d(code))
            r.uc.mem_write(BUF+0x1000+0x20,q(0 if nullbuf else BUF+0x2000))
            r.uc.mem_write(BUF+0x2000,q(0xffff))
        case('IRP dispatch '+hex(code)+' null='+str(nullbuf),setup,[('sub_11150',[0,BUF],U32)])

report={'original_bytes':ORIGINAL.stat().st_size,'reconstructed_bytes':BUILT.stat().st_size,
        'original_sha256':hashlib.sha256(ORIGINAL.read_bytes()).hexdigest(),
        'reconstructed_sha256':hashlib.sha256(BUILT.read_bytes()).hexdigest(),
        'scope':'Unicorn execution with deterministic mocked kernel imports. No real driver was loaded.',
        'passed':sum(r['passed'] for r in results),'total':len(results),'cases':results}
(ROOT/'build/verification.json').write_text(json.dumps(report,indent=2))
print(json.dumps({k:v for k,v in report.items() if k!='cases'},indent=2))
for r in results:
    if not r['passed']: print(r)
raise SystemExit(0 if report['passed']==report['total'] else 1)

