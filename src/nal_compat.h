#pragma once
#include <ntddk.h>
#include <stdarg.h>
#include <intrin.h>
#include "nal_globals.h"
// FindWDK force-includes warning.h, which promotes C4700 to an error.
// Keep the original uninitialized-value paths; report them as warnings.
#pragma warning(3:4700)
int __cdecl vsprintf(char *, const char *, va_list);

typedef unsigned char _BYTE;
typedef unsigned short _WORD;
typedef unsigned int _DWORD;
typedef unsigned __int64 _QWORD;
#define nullptr NULL
typedef struct NAL_LIST { PVOID head; ULONG count; ULONG reserved; } NAL_LIST;
C_ASSERT(FIELD_OFFSET(NAL_LIST, count) == 8);
C_ASSERT(FIELD_OFFSET(IO_STACK_LOCATION, Parameters.DeviceIoControl.IoControlCode) == 0x18);
C_ASSERT(FIELD_OFFSET(IO_STACK_LOCATION, Parameters.DeviceIoControl.Type3InputBuffer) == 0x20);
C_ASSERT(FIELD_OFFSET(MDL, ByteOffset) == 44);

static __forceinline PHYSICAL_ADDRESS nal_pa(LONGLONG n)
{ PHYSICAL_ADDRESS a; a.QuadPart = n; return a; }
static __forceinline LONGLONG nal_get_physical(PVOID p)
{ return MmGetPhysicalAddress(p).QuadPart; }
static __forceinline LONGLONG nal_counter(PLARGE_INTEGER f)
{ return KeQueryPerformanceCounter(f).QuadPart; }
static __forceinline PVOID nal_map(LONGLONG p, SIZE_T n, MEMORY_CACHING_TYPE c)
{ return MmMapIoSpace(nal_pa(p), n, c); }
static __forceinline PVOID nal_alloc(ULONG n, LONGLONG high)
{ return MmAllocateContiguousMemory(n, nal_pa(high)); }
#define MmGetPhysicalAddress nal_get_physical
#define KeQueryPerformanceCounter nal_counter
#define MmMapIoSpace nal_map
#define MmAllocateContiguousMemory nal_alloc
#ifndef BYTE1
#define BYTE1(x) ((UCHAR)((ULONG)(x) >> 8))
#define BYTE2(x) ((UCHAR)((ULONG)(x) >> 16))
#define HIBYTE(x) ((UCHAR)((ULONG)(x) >> 24))
#endif
#ifndef HIWORD
#define HIWORD(x) ((USHORT)((ULONG)(x) >> 16))
#endif

