/* Reconstructed from the original IDB. See RECONSTRUCTION.md. */
#include "nal_compat.h"

__int64 __fastcall sub_11010(__int64 a1);
__int64 __fastcall sub_11090(__int64 a1, IRP *a2);
__int64 __fastcall sub_110F0(__int64 a1, IRP *a2);
__int64 __fastcall sub_11150(__int64 a1, IRP *a2);
__int64 sub_11210();
char __fastcall sub_11220(__int64 *a1, char a2);
char __fastcall sub_112F0(__int64 *a1);
__int64 __fastcall sub_11330(__int64 a1);
__int64 __fastcall sub_113C0(__int64 a1);
__int64 __fastcall sub_11A60(__int64 a1);
unsigned __int8 __fastcall sub_11C20(unsigned __int16 a1);
unsigned __int16 __fastcall sub_11C30(unsigned __int16 a1);
unsigned __int32 __fastcall sub_11C40(unsigned __int16 a1);
char __fastcall sub_11C50(unsigned __int16 a1, unsigned __int8 a2);
char __fastcall sub_11C60(unsigned __int16 a1, unsigned __int16 a2);
char __fastcall sub_11C80(unsigned __int16 a1, unsigned int a2);
char __fastcall sub_11C90(__int64 a1);
__int16 __fastcall sub_11CB0(__int64 a1);
__int64 __fastcall sub_11CD0(unsigned int *a1);
char __fastcall sub_11CF0(_BYTE *a1, char a2);
char __fastcall sub_11D10(_WORD *a1, __int16 a2);
char __fastcall sub_11D30(_DWORD *a1, int a2);
void __fastcall sub_11D50(ULONG MicroSeconds);
LONGLONG sub_11DB0();
void __fastcall sub_11DC0(void *a1);
LONGLONG __fastcall sub_11DE0(void *a1, void *a2);
void *__fastcall sub_11E70(void *a1, unsigned __int8 a2, size_t a3);
void *__fastcall sub_11EA0(void *a1, const void *a2, size_t a3);
__int64 __fastcall sub_11ED0(volatile signed __int32 *a1);
__int64 __fastcall sub_11EF0(volatile signed __int32 *a1);
__int64 __fastcall sub_11F10(volatile signed __int32 *a1, signed __int32 a2, signed __int32 a3);
__int64 sub_11F30(char *Format, ...);
void __fastcall sub_12000(char a1);
LONGLONG __fastcall sub_12010(void *a1);
unsigned __int64 __fastcall sub_12030(PVOID VirtualAddress, ULONG Length, __int64 a3);
__int64 __fastcall sub_121C0(PVOID BaseAddress, __int64 a2, unsigned int a3);
__int64 __fastcall sub_12220(const void *a1, __int64 a2, unsigned int a3, const void *a4);
void __fastcall sub_123C0(ULONG MicroSeconds);
__int64 sub_12450();
void *__fastcall sub_12520(ULONG Length, unsigned int a2, __int64 a3, LONGLONG *a4);
void __fastcall sub_12770(const void *a1, __int64 a2);
void *__fastcall sub_128B0(ULONG a1, unsigned int a2, LONGLONG *a3);
void __fastcall sub_128E0(const void *a1);
__int64 __fastcall sub_129C0(_QWORD *a1, LONGLONG a2, ULONG *a3, __int64 a4);
__int64 __fastcall sub_12AC0(_QWORD *a1, LONGLONG a2, unsigned int *a3);
__int64 __fastcall sub_12B70(PDEVICE_OBJECT DeviceObject, _WORD *Dst);
NTSTATUS __fastcall sub_12C60(PDEVICE_OBJECT DeviceObject, __int64 a2, char a3, int a4, int a5);
__int64 __fastcall sub_12D70(__int64 a1);
__int64 sub_13100();
__int64 __fastcall sub_13110(__int64 a1);
void __fastcall sub_132B0(__int64 *a1);
__int64 __fastcall sub_13540(int *a1);
__int64 __fastcall sub_13640(int *a1, PVOID *a2);
__int16 sub_13740();
__int64 __fastcall sub_137D0(__int64 a1, unsigned __int16 *a2);
__int64 __fastcall sub_138B0(int *a1, void *a2, unsigned int a3);
__int64 __fastcall sub_13980(int *a1, int a2, __int64 a3);
__int64 __fastcall sub_13A00(int *a1, int a2, int a3);
__int64 __fastcall sub_13B20(int *Src, int a2, char a3, unsigned int a4);
__int64 __fastcall sub_13D00(__int64 a1, __int64 a2);
__int64 sub_13DF0();
char __fastcall sub_13E00(__int64 a1);
PVOID sub_13E60();
void __fastcall sub_13EA0(PVOID *P);
void __fastcall sub_13EF0(__int64 a1, __int64 a2);
__int64 __fastcall sub_13FA0(_QWORD *a1);
__declspec(noreturn) void __fastcall sub_14270(ULONG_PTR BugCheckParameter1);
__int64 __fastcall sub_5E2010(PDRIVER_OBJECT DriverObject);
NTSTATUS __stdcall DriverEntry(PDRIVER_OBJECT DriverObject, PUNICODE_STRING RegistryPath);
void nal_check_cookie(ULONG_PTR cookie);


/* Original function: sub_11010 */
__int64 __fastcall sub_11010(__int64 a1)
{
  struct _DEVICE_OBJECT *v2; // rcx
  struct _UNICODE_STRING DestinationString; // [rsp+20h] [rbp-18h] BYREF

  sub_11F30((char *)("Nal Windows Driver Unload: Starting\n"));
  RtlInitUnicodeString(&DestinationString, L"\\??\\Nal");
  IoDeleteSymbolicLink(&DestinationString);
  v2 = *(struct _DEVICE_OBJECT **)(a1 + 8);
  if ( v2 != nullptr )
    IoDeleteDevice(v2);
  else
    sub_11F30((char *)("Nal Windows Driver Unload: IoDeleteDevice NOT called: NULL DeviceObject\n"));
  return sub_11F30((char *)("Nal Windows Driver Unload: Leaving... \n"));
}



/* Original function: sub_11090 */
__int64 __fastcall sub_11090(__int64 a1, IRP *a2)
{
  sub_11F30((char *)("Nal Windows DriverCreate: Starting\n"));
  sub_11ED0((volatile signed __int32 *)(&dword_17120));
  a2->IoStatus.Information = 0;
  a2->IoStatus.Status = 0;
  IofCompleteRequest(a2, 0);
  sub_11F30((char *)("Nal Windows DriverCreate: Leaving\n"));
  return 0;
}



/* Original function: sub_110F0 */
__int64 __fastcall sub_110F0(__int64 a1, IRP *a2)
{
  sub_11F30((char *)("Nal Windows DriverClose: Starting\n"));
  a2->IoStatus.Information = 0;
  a2->IoStatus.Status = 0;
  IofCompleteRequest(a2, 0);
  sub_11EF0((volatile signed __int32 *)(&dword_17120));
  sub_11F30((char *)("Nal Windows DriverClose: Leaving\n"));
  return 0;
}



/* Original function: sub_11150 */
__int64 __fastcall sub_11150(__int64 a1, IRP *a2)
{
  struct _IO_STACK_LOCATION *CurrentStackLocation; // rax
  __int64 LowPart; // rdx
  unsigned int v5; // ebx

  CurrentStackLocation = a2->Tail.Overlay.CurrentStackLocation;
  LowPart = CurrentStackLocation->Parameters.DeviceIoControl.IoControlCode;
  if ( CurrentStackLocation->Parameters.DeviceIoControl.Type3InputBuffer != nullptr )
  {
    switch ( (_DWORD)LowPart )
    {
      case 0x80862007:
        v5 = sub_113C0((__int64)((__int64)CurrentStackLocation->Parameters.DeviceIoControl.Type3InputBuffer));
        break;
      case 0x8086200B:
        v5 = sub_11A60((__int64)((__int64)CurrentStackLocation->Parameters.DeviceIoControl.Type3InputBuffer));
        break;
      case 0x8086200F:
        v5 = sub_11330((__int64)((__int64)CurrentStackLocation->Parameters.DeviceIoControl.Type3InputBuffer));
        break;
      case 0x80862013:
        v5 = sub_13FA0((_QWORD *)((_QWORD *)CurrentStackLocation->Parameters.DeviceIoControl.Type3InputBuffer));
        break;
      default:
        v5 = -1073741811;
        sub_11F30((char *)("Nal Windows DriverDeviceControl: Invalid IOCTL code 0x%0x\n"), LowPart);
        break;
    }
  }
  else
  {
    sub_11F30((char *)("NalDeviceControl: InputBuffer was NULL\n"), LowPart);
    v5 = -1073741811;
  }
  a2->IoStatus.Information = 0;
  a2->IoStatus.Status = v5;
  IofCompleteRequest(a2, 0);
  return v5;
}



/* Original function: sub_11210 */
__int64 sub_11210()
{
  return (unsigned int)dword_17120;
}



/* Original function: sub_11220 */
char __fastcall sub_11220(__int64 *a1, char a2)
{
  __int64 v2; // r11
  char v3; // r10
  unsigned __int64 v4; // r8
  __int64 v5; // r9
  unsigned __int64 v6; // rax
  __int64 v7; // rax
  unsigned __int64 v8; // rcx
  char result; // al
  __int64 v10; // r8

  v2 = *a1;
  v3 = 0;
  v4 = 0;
  v5 = 0;
  v6 = 0;
  while ( *(_QWORD *)&byte_5CFEC0[v6] != v2 || byte_5CFEC0[v6 + 264] != 1 )
  {
    v6 += 272LL;
    ++v5;
    if ( v6 >= 0x11000 )
      goto LABEL_9;
  }
  if ( a2 != 0 )
  {
    v3 = 0;
  }
  else
  {
    v3 = 1;
    v7 = 272 * v5;
    byte_5CFEC0[v7 + 264] = 0;
    *(_QWORD *)&byte_5CFEC0[v7] = 0;
  }
LABEL_9:
  if ( v5 != 256 )
    return v3;
  if ( a2 == 1 )
  {
    v8 = 0;
    while ( *(_QWORD *)&byte_5CFEC0[v8] != 0 )
    {
      v8 += 272LL;
      ++v4;
      if ( v8 >= 0x11000 )
        return v3;
    }
    if ( v4 < 0x100 )
    {
      v10 = 272 * v4;
      *(_QWORD *)&byte_5CFEC0[v10] = v2;
      byte_5CFEC0[v10 + 264] = 1;
      return 1;
    }
    return v3;
  }
  result = v3;
  if ( a2 == 0 )
    return 1;
  return result;
}



/* Original function: sub_112F0 */
char __fastcall sub_112F0(__int64 *a1)
{
  __int64 v1; // rdx
  unsigned __int64 v2; // rcx

  v1 = *a1;
  v2 = 0;
  while ( *(_QWORD *)&byte_5CFEC0[v2] != v1 || byte_5CFEC0[v2 + 264] != 1 )
  {
    v2 += 272LL;
    if ( v2 >= 0x11000 )
      return 0;
  }
  return 1;
}



/* Original function: sub_11330 */
__int64 __fastcall sub_11330(__int64 a1)
{
  if ( a1 == 0 )
    return 1;
  if ( *(_QWORD *)a1 == 1 )
  {
    if ( a1 != -16 )
      *(_DWORD *)(a1 + 16) = sub_13DF0(*(_QWORD *)(a1 + 24));
    return 0;
  }
  if ( *(_QWORD *)a1 != 2 )
  {
    if ( *(_QWORD *)a1 != 3 )
      return 3362398232LL;
    if ( a1 != -16 )
    {
      *(_DWORD *)(a1 + 16) = sub_13DF0(*(_QWORD *)(a1 + 24));
      return 0;
    }
    return 0;
  }
  if ( a1 != -16 )
    *(_BYTE *)(a1 + 20) = sub_13E00((__int64)(*(_QWORD *)(a1 + 24)));
  return 0;
}



/* Original function: sub_113C0 */
__int64 __fastcall sub_113C0(__int64 a1)
{
  unsigned int v2; // ebx
  __int64 result; // rax
  __int64 v4; // rcx
  __int64 v5; // rcx
  __int64 v6; // rdx

  v2 = 1;
  if ( a1 == 0 )
    return v2;
  switch ( *(_QWORD *)a1 )
  {
    case 1LL:
      *(_BYTE *)(a1 + 16) = sub_11C20((unsigned __int16)(*(_QWORD *)(a1 + 24)));
      return 0;
    case 2LL:
      *(_WORD *)(a1 + 16) = sub_11C30((unsigned __int16)(*(_QWORD *)(a1 + 24)));
      return 0;
    case 3LL:
      *(_DWORD *)(a1 + 16) = sub_11C40((unsigned __int16)(*(_QWORD *)(a1 + 24)));
      return 0;
    case 7LL:
      *(_BYTE *)(a1 + 16) = sub_11C50((unsigned __int16)(*(_QWORD *)(a1 + 24)),(unsigned __int8)(*(unsigned __int8 *)(a1 + 32)));
      return 0;
    case 8LL:
      *(_BYTE *)(a1 + 16) = sub_11C60((unsigned __int16)(*(_QWORD *)(a1 + 24)),(unsigned __int16)(*(unsigned __int16 *)(a1 + 32)));
      return 0;
    case 9LL:
      *(_BYTE *)(a1 + 16) = sub_11C80((unsigned __int16)(*(_QWORD *)(a1 + 24)),(unsigned int)(*(unsigned int *)(a1 + 32)));
      return 0;
    case 0xDLL:
      *(_BYTE *)(a1 + 16) = sub_11C90((__int64)(*(_QWORD *)(a1 + 24)));
      return 0;
    case 0xELL:
      *(_WORD *)(a1 + 16) = sub_11CB0((__int64)(*(_QWORD *)(a1 + 24)));
      return 0;
    case 0xFLL:
      *(_DWORD *)(a1 + 16) = sub_11CD0((unsigned int *)(*(_QWORD *)(a1 + 24)));
      return 0;
    case 0x13LL:
      *(_BYTE *)(a1 + 16) = sub_11CF0((_BYTE *)(*(_QWORD *)(a1 + 24)),(char)(*(unsigned __int8 *)(a1 + 32)));
      return 0;
    case 0x14LL:
      *(_BYTE *)(a1 + 16) = sub_11D10((_WORD *)(*(_QWORD *)(a1 + 24)),(__int16)(*(unsigned __int16 *)(a1 + 32)));
      return 0;
    case 0x15LL:
      *(_BYTE *)(a1 + 16) = sub_11D30((_DWORD *)(*(_QWORD *)(a1 + 24)),(int)(*(unsigned int *)(a1 + 32)));
      return 0;
    case 0x19LL:
      *(_DWORD *)(a1 + 16) = sub_12AC0((_QWORD *)(a1 + 24),(LONGLONG)(*(_QWORD *)(a1 + 32)),(unsigned int *)(a1 + 40));
      return 0;
    case 0x1ALL:
      *(_DWORD *)(a1 + 16) = sub_121C0((PVOID)(*(PVOID *)(a1 + 24)),(__int64)(*(_QWORD *)(a1 + 32)),(unsigned int)(*(_DWORD *)(a1 + 40)));
      return 0;
    case 0x1BLL:
      *(_QWORD *)(a1 + 16) = sub_11DB0();
      return 0;
    case 0x1CLL:
      *(_QWORD *)(a1 + 16) = sub_12450();
      return 0;
    case 0x23LL:
      sub_123C0((ULONG)(*(_DWORD *)(a1 + 16)));
      return 0;
    case 0x24LL:
      sub_11D50((ULONG)(*(_DWORD *)(a1 + 16)));
      return 0;
    case 0x25LL:
      *(_QWORD *)(a1 + 16) = sub_12010((void *)(*(_QWORD *)(a1 + 24)));
      return 0;
    case 0x26LL:
      *(_QWORD *)(a1 + 16) = sub_128B0((ULONG)(*(_DWORD *)(a1 + 24)),(unsigned int)(*(_DWORD *)(a1 + 28)),(LONGLONG *)((LONGLONG *)(a1 + 32)));
      return 0;
    case 0x27LL:
      sub_128E0((const void *)((const void *)*(_QWORD *)(a1 + 16)));
      return 0;
    case 0x28LL:
      *(_DWORD *)(a1 + 16) = sub_11ED0((volatile signed __int32 *)(*(_QWORD *)(a1 + 24)));
      return 0;
    case 0x29LL:
      *(_DWORD *)(a1 + 16) = sub_11EF0((volatile signed __int32 *)(*(_QWORD *)(a1 + 24)));
      return 0;
    case 0x2ALL:
      *(_DWORD *)(a1 + 16) = sub_11F10((volatile signed __int32 *)(*(_QWORD *)(a1 + 24)),(signed __int32)(*(unsigned int *)(a1 + 32)),(signed __int32)(*(unsigned int *)(a1 + 36)));
      return 0;
    case 0x2FLL:
      if ( a1 == -16 )
        goto LABEL_42;
      *(_DWORD *)(a1 + 16) = sub_11F30((char *)((char *)(a1 + 20)));
      result = 0;
      break;
    case 0x30LL:
      v4 = *(_QWORD *)(a1 + 24);
      if ( v4 != 0 )
      {
        sub_11E70((void *)(v4),(unsigned __int8)(*(unsigned int *)(a1 + 16)),(size_t)(*(_QWORD *)(a1 + 32)));
        return 0;
      }
      else
      {
        sub_11F30((char *)("NAL_KMEMSET_FUNCID: One of the buffers was NULL\n"));
        return 1;
      }
    case 0x31LL:
      v5 = *(_QWORD *)(a1 + 24);
      if ( v5 != 0 )
      {
        v6 = *(_QWORD *)(a1 + 16);
        if ( v6 != 0 )
          goto LABEL_29;
      }
      sub_11F30((char *)("NAL_KUMEMCPY_FUNCID: One of the buffers was NULL\n"));
      result = 1;
      break;
    case 0x32LL:
      v5 = *(_QWORD *)(a1 + 24);
      if ( v5 != 0 && (v6 = *(_QWORD *)(a1 + 16)) != 0 )
      {
LABEL_29:
        sub_11EA0((void *)(v5),(const void *)(v6),(size_t)(*(_QWORD *)(a1 + 32)));
        result = 0;
      }
      else
      {
        sub_11F30((char *)("NAL_KKMEMCPY_FUNCID: One of the buffers was NULL\n"));
        result = 1;
      }
      break;
    case 0x33LL:
      sub_11EA0((void *)(*(_QWORD *)(a1 + 24)),(const void *)(*(_QWORD *)(a1 + 16)),(size_t)(*(_QWORD *)(a1 + 32)));
      result = 0;
      break;
    case 0x36LL:
      if ( a1 == -16 )
      {
LABEL_42:
        sub_11F30((char *)("NAL_ENABLE_DEBUG_PRINT_FUNCID: FunctionData is NULL\n"));
        result = 1;
      }
      else
      {
        sub_12000((char)(*(unsigned __int8 *)(a1 + 16)));
        result = 0;
      }
      break;
    case 0x37LL:
      *(_QWORD *)(a1 + 16) = sub_12520((ULONG)(*(_DWORD *)(a1 + 24)),(unsigned int)(*(_DWORD *)(a1 + 28)),(__int64)(*(_QWORD *)(a1 + 40)),(LONGLONG *)((LONGLONG *)(a1 + 32)));
      result = 0;
      break;
    case 0x38LL:
      sub_12770((const void *)((const void *)*(_QWORD *)(a1 + 16)),(__int64)(*(_QWORD *)(a1 + 24)));
      result = 0;
      break;
    case 0x39LL:
      *(_DWORD *)(a1 + 16) = sub_129C0((_QWORD *)(a1 + 24),(LONGLONG)(*(_QWORD *)(a1 + 32)),(ULONG *)(a1 + 40),(__int64)(*(_QWORD *)(a1 + 48)));
      result = 0;
      break;
    case 0x3ALL:
      *(_DWORD *)(a1 + 16) = sub_12220((const void *)(*(_QWORD *)(a1 + 24)),(__int64)(*(_QWORD *)(a1 + 32)),(unsigned int)(*(unsigned int *)(a1 + 40)),(const void *)(*(_QWORD *)(a1 + 48)));
      result = 0;
      break;
    case 0x3BLL:
      *(_QWORD *)(a1 + 16) = sub_11DE0((void *)(*(_QWORD *)(a1 + 24)),(void *)(*(_QWORD *)(a1 + 32)));
      result = 0;
      break;
    default:
      return (unsigned int)-932569064;
  }
  return result;
}



/* Original function: sub_11A60 */
__int64 __fastcall sub_11A60(__int64 a1)
{
  __int64 result; // rax
  _BYTE Dst[280]; // [rsp+20h] [rbp-118h] BYREF

  result = 1;
  if ( a1 != 0 )
  {
    switch ( *(_QWORD *)a1 )
    {
      case 1LL:
        *(_WORD *)(a1 + 16) = sub_13740();
        result = 0;
        break;
      case 2LL:
        *(_DWORD *)(a1 + 16) = sub_137D0((__int64)(a1 + 24),(unsigned __int16 *)(a1 + 20));
        result = 0;
        break;
      case 3LL:
        memmove(Dst, (const void *)(a1 + 24), 0x108u);
        *(_DWORD *)(a1 + 16) = sub_138B0((int *)(Dst),(void *)(a1 + 292),(unsigned int)(*(unsigned int *)(a1 + 288)));
        result = 0;
        break;
      case 4LL:
        memmove(Dst, (const void *)(a1 + 24), 0x108u);
        *(_DWORD *)(a1 + 16) = sub_13980((int *)(Dst),(int)(*(unsigned int *)(a1 + 288)),(__int64)(a1 + 292));
        result = 0;
        break;
      case 5LL:
        memmove(Dst, (const void *)(a1 + 24), 0x108u);
        *(_DWORD *)(a1 + 16) = sub_13A00((int *)(Dst),(int)(*(unsigned int *)(a1 + 288)),(int)(*(unsigned int *)(a1 + 292)));
        result = 0;
        break;
      case 6LL:
        memmove(Dst, (const void *)(a1 + 24), 0x108u);
        *(_DWORD *)(a1 + 16) = sub_13B20((int *)((int *)Dst),(int)(*(_DWORD *)(a1 + 288)),(char)(*(_BYTE *)(a1 + 292)),(unsigned int)(*(_DWORD *)(a1 + 296)));
        result = 0;
        break;
      case 7LL:
        memmove(Dst, (const void *)(a1 + 24), 0x108u);
        *(_DWORD *)(a1 + 16) = sub_13100(Dst);
        result = 0;
        break;
      default:
        result = 3362398232LL;
        break;
    }
  }
  return result;
}



/* Original function: sub_11C20 */
unsigned __int8 __fastcall sub_11C20(unsigned __int16 a1)
{
  return __inbyte(a1);
}



/* Original function: sub_11C30 */
unsigned __int16 __fastcall sub_11C30(unsigned __int16 a1)
{
  return __inword(a1);
}



/* Original function: sub_11C40 */
unsigned __int32 __fastcall sub_11C40(unsigned __int16 a1)
{
  return __indword(a1);
}



/* Original function: sub_11C50 */
char __fastcall sub_11C50(unsigned __int16 a1, unsigned __int8 a2)
{
  __outbyte(a1, a2);
  return 1;
}



/* Original function: sub_11C60 */
char __fastcall sub_11C60(unsigned __int16 a1, unsigned __int16 a2)
{
  __outword(a1, a2);
  return 1;
}



/* Original function: sub_11C80 */
char __fastcall sub_11C80(unsigned __int16 a1, unsigned int a2)
{
  __outdword(a1, a2);
  return 1;
}



/* Original function: sub_11C90 */
char __fastcall sub_11C90(__int64 a1)
{
  if ( a1 != 0 )
    return *(_BYTE *)a1;
  else
    return 0;
}



/* Original function: sub_11CB0 */
__int16 __fastcall sub_11CB0(__int64 a1)
{
  if ( a1 != 0 )
    return *(_WORD *)a1;
  else
    return 0;
}



/* Original function: sub_11CD0 */
__int64 __fastcall sub_11CD0(unsigned int *a1)
{
  if ( a1 != nullptr )
    return *a1;
  else
    return 0;
}



/* Original function: sub_11CF0 */
char __fastcall sub_11CF0(_BYTE *a1, char a2)
{

  if ( a1 == nullptr )
    return 0;
  *a1 = a2;
  KeMemoryBarrier();
  return 1;
}



/* Original function: sub_11D10 */
char __fastcall sub_11D10(_WORD *a1, __int16 a2)
{

  if ( a1 == nullptr )
    return 0;
  *a1 = a2;
  KeMemoryBarrier();
  return 1;
}



/* Original function: sub_11D30 */
char __fastcall sub_11D30(_DWORD *a1, int a2)
{

  if ( a1 == nullptr )
    return 0;
  *a1 = a2;
  KeMemoryBarrier();
  return 1;
}



/* Original function: sub_11D50 */
void __fastcall sub_11D50(ULONG MicroSeconds)
{
  ULONG v1; // ebx
  __int64 v2; // rdi

  v1 = MicroSeconds;
  if ( MicroSeconds / 0x32 != 0 )
  {
    v2 = MicroSeconds / 0x32;
    do
    {
      KeStallExecutionProcessor(0x32u);
      v1 -= 50;
      --v2;
    }
    while ( v2 != 0 );
  }
  if ( v1 != 0 )
    KeStallExecutionProcessor(v1);
}



/* Original function: sub_11DB0 */
LONGLONG sub_11DB0()
{
  return KeQueryPerformanceCounter(nullptr);
}



/* Original function: sub_11DC0 */
void __fastcall sub_11DC0(void *a1)
{
  if ( a1 != nullptr )
    ExFreePoolWithTag(a1, 0);
}



/* Original function: sub_11DE0 */
LONGLONG __fastcall sub_11DE0(void *a1, void *a2)
{
  __int64 v2; // r9
  void **v3; // rax
  unsigned __int64 v4; // r8

  if ( a2 != nullptr )
  {
    v2 = 0;
    v3 = (void **)&unk_17180;
    v4 = 0;
    while ( 1 )
    {
      if ( *(void **)(v4 + NAL_ADDR(0x3E7A60)) == a2 && a1 == *(void **)(v4 + NAL_ADDR(0x3E7A40)) )
      {
        a1 = *(void **)(40 * v2 + NAL_ADDR(0x3E7A48));
        goto LABEL_11;
      }
      if ( v3[1] == a2 && a1 == *v3 )
        break;
      v4 += 40LL;
      ++v2;
      v3 += 10;
      if ( v4 >= 0x1E8480 )
        goto LABEL_11;
    }
    a1 = *(void **)(80 * v2 + NAL_ADDR(0x17150));
  }
LABEL_11:
  if ( a1 != nullptr )
    return MmGetPhysicalAddress(a1);
  return 0;
}



/* Original function: sub_11E70 */
void *__fastcall sub_11E70(void *a1, unsigned __int8 a2, size_t a3)
{
  if ( KeGetCurrentIrql() <= 2u )
    memset(a1, a2, a3);
  return a1;
}



/* Original function: sub_11EA0 */
void *__fastcall sub_11EA0(void *a1, const void *a2, size_t a3)
{
  if ( KeGetCurrentIrql() <= 2u )
    memmove(a1, a2, a3);
  return a1;
}



/* Original function: sub_11ED0 */
__int64 __fastcall sub_11ED0(volatile signed __int32 *a1)
{
  if ( a1 != nullptr )
    return (unsigned int)_InterlockedIncrement(a1);
  else
    return 0;
}



/* Original function: sub_11EF0 */
__int64 __fastcall sub_11EF0(volatile signed __int32 *a1)
{
  if ( a1 != nullptr )
    return (unsigned int)_InterlockedDecrement(a1);
  else
    return 0;
}



/* Original function: sub_11F10 */
__int64 __fastcall sub_11F10(volatile signed __int32 *a1, signed __int32 a2, signed __int32 a3)
{
  if ( a1 != nullptr )
    return (unsigned int)_InterlockedCompareExchange(a1, a3, a2);
  else
    return 0;
}



/* Original function: sub_11F30 */
__int64 sub_11F30(char *Format, ...)
{
  CHAR Formata[512]; // [rsp+20h] [rbp-418h] BYREF
  char Dest[512]; // [rsp+220h] [rbp-218h] BYREF
  volatile uintptr_t StackCookie; // [rsp+420h] [rbp-18h]
  va_list Args; // [rsp+448h] [rbp+10h] BYREF

  va_start(Args, Format);
  StackCookie = BugCheckParameter2;
  if ( byte_17128 != 1 || Format == nullptr )
    { nal_check_cookie(StackCookie); return 3362422795LL; }
  vsprintf(Dest, Format, Args);
  strcpy(Formata, "Kernel: ");
  strncpy(&Formata[8], Dest, 0x1F3u);
  DbgPrint(Formata);
  { nal_check_cookie(StackCookie); return 0; }
}



/* Original function: sub_12000 */
void __fastcall sub_12000(char a1)
{
  byte_17128 = a1;
}



/* Original function: sub_12010 */
LONGLONG __fastcall sub_12010(void *a1)
{
  if ( a1 != nullptr )
    return MmGetPhysicalAddress(a1);
  return 0;
}



/* Original function: sub_12030 */
unsigned __int64 __fastcall sub_12030(PVOID VirtualAddress, ULONG Length, __int64 a3)
{
  unsigned int v5; // ebx
  struct _MDL *Mdl; // rax
  struct _MDL *v8; // rdi
  PVOID v9; // rax
  unsigned __int64 v10; // rsi
  __int64 v11; // rcx
  unsigned __int64 result; // rax
  unsigned int v13[6]; // [rsp+30h] [rbp-28h] BYREF

  v5 = 0;
  v13[0] = 0;
  while ( _InterlockedCompareExchange64((volatile signed __int64 *)&unk_3E7A40 + 5 * v5 + 3, (signed __int64)v13, 0) != 0 )
  {
    v5 = ++v13[0];
    if ( v13[0] >= 0xC350 )
      goto LABEL_6;
  }
  v5 = v13[0];
LABEL_6:
  sub_11F30((char *)("_NalWinGetUserAddress: Using memory map table slot %d - Length %d\n"), v5, Length);
  sub_11F30((char *)("PAGE_SIZE * (65535 - sizeof(MDL)) / sizeof(ULONG_PTR) = %d\n"), 33529344);
  if ( v5 < 0xC350 )
  {
    sub_11F30((char *)("_NalWinGetUserAddress: KernelLevelAddress = 0x%p\n"), VirtualAddress);
    Mdl = IoAllocateMdl(VirtualAddress, Length, 0, 0, nullptr);
    v8 = Mdl;
    if ( Mdl != nullptr )
    {
      MmBuildMdlForNonPagedPool(Mdl);
      v9 = MmMapLockedPagesSpecifyCache(v8, 1, MmCached, nullptr, 0, 0x10u);
      v10 = (unsigned __int64)v9;
      if ( v9 != nullptr )
      {
        sub_11F30((char *)("_NalWinGetUserAddress: Address To Free = 0x%p\n"), v9);
        v11 = 5LL * v5;
        *((_QWORD *)&unk_3E7A40 + v11 + 3) = (_QWORD)v10;
        *((_QWORD *)&unk_3E7A40 + v11 + 2) = (_QWORD)v8;
        *((_QWORD *)&unk_3E7A40 + v11 + 1) = (_QWORD)VirtualAddress;
        *((_QWORD *)&unk_3E7A40 + v11 + 4) = a3;
        result = (v10 & 0xFFFFFFFFFFFFF000uLL) + v8->ByteOffset;
        *((_QWORD *)&unk_3E7A40 + v11) = result;
        return result;
      }
      sub_11F30((char *)("_NalWinGetUserAddress: MmMapLockedPages failed. Freeing MDL\n"));
      IoFreeMdl(v8);
    }
    else
    {
      sub_11F30((char *)("_NalWinGetUserAddress: Unable to allocate MDL\n"));
    }
  }
  return 0;
}



/* Original function: sub_121C0 */
__int64 __fastcall sub_121C0(PVOID BaseAddress, __int64 a2, unsigned int a3)
{
  SIZE_T v4; // rbx

  v4 = a3;
  if ( BaseAddress != nullptr && a3 != 0 )
  {
    sub_11F30((char *)("NalUnmapAddress: Unmapping non-usermode mapped address 0x%p, Length %d\n"), BaseAddress, a3);
    MmUnmapIoSpace(BaseAddress, v4);
  }
  return 0;
}



/* Original function: sub_12220 */
__int64 __fastcall sub_12220(const void *a1, __int64 a2, unsigned int a3, const void *a4)
{
  SIZE_T v6; // r12
  const void **v7; // rbx
  unsigned int v8; // edi
  signed __int64 v9; // rax

  v6 = a3;
  if ( a1 == nullptr || a3 == 0 )
    return 1;
  sub_11F30((char *)("NalUnmapAddressEx: Looking to unmap 0x%p, Length %d, ProcessId %d\n"), a1, a3, a4);
  v7 = (const void **)&unk_3E7A40;
  v8 = 0;
  while ( 1 )
  {
    sub_11F30((char *)("NalUnmapAddressEx: Global_WinMemoryMapTable[%d].MappedAddress = 0x%p == 0x%p\n"), v8, *v7, a1);
    if ( a4 == v7[4] && a1 == *v7 )
      break;
    ++v8;
    v7 += 5;
    if ( v8 >= 0xC350 )
      goto LABEL_15;
  }
  sub_11F30((char *)("NalUnmapAddressEx: Slot %d matched\n"), v8);
  if ( *((_QWORD *)&unk_3E7A40 + 5 * v8 + 2) != 0 && *((_QWORD *)&unk_3E7A40 + 5 * v8 + 3) != 0 )
  {
    sub_11F30((char *)("NalUnmapAddressEx: Calling MmUnmapLockedPages\n"));
    MmUnmapLockedPages(*((PVOID *)&unk_3E7A40 + 5 * v8 + 3), *((PMDL *)&unk_3E7A40 + 5 * v8 + 2));
    IoFreeMdl(*((PMDL *)&unk_3E7A40 + 5 * v8 + 2));
  }
  else
  {
    sub_11F30((char *)("NalUnmapAddressEx: Skipped MmUnmapLockedPages - AddressToFree or Mdl was NULL\n"));
  }
  if ( *((_QWORD *)&unk_3E7A40 + 5 * v8 + 1) != 0 )
  {
    sub_11F30((char *)("NalUnmapAddressEx: Unmapping OriginalMemoryMapped\n"));
    MmUnmapIoSpace(*((PVOID *)&unk_3E7A40 + 5 * v8 + 1), v6);
  }
  v9 = *((_QWORD *)&unk_3E7A40 + 5 * v8 + 3);
  *((_QWORD *)&unk_3E7A40 + 5 * v8 + 2) = 0;
  *((_QWORD *)&unk_3E7A40 + 5 * v8 + 1) = 0;
  *((_QWORD *)&unk_3E7A40 + 5 * v8) = 0;
  *((_QWORD *)&unk_3E7A40 + 5 * v8 + 4) = 0;
  _InterlockedCompareExchange64((volatile signed __int64 *)&unk_3E7A40 + 5 * v8 + 3, 0, v9);
  sub_11F30((char *)("NalUnmapAddressEx: Global_WinMemoryMapTable[i].AddressToFree = %p\n"),
    *((const void **)&unk_3E7A40 + 5 * v8 + 3));
LABEL_15:
  if ( v8 == 50000 )
    sub_11F30((char *)("NalUnmapAddressEx: Address not found in table - not unmapping 0x%p, Length %d\n"), a1, v6);
  return 0;
}



/* Original function: sub_123C0 */
void __fastcall sub_123C0(ULONG MicroSeconds)
{
  __int64 v2; // rsi
  ULONG v3; // ebp
  ULONG v4; // ebx
  __int64 i; // rdi

  v2 = 1000;
  v3 = MicroSeconds / 0x32;
  do
  {
    v4 = MicroSeconds;
    if ( v3 != 0 )
    {
      for ( i = v3; i != 0; --i )
      {
        KeStallExecutionProcessor(0x32u);
        v4 -= 50;
      }
    }
    if ( v4 != 0 )
      KeStallExecutionProcessor(v4);
    --v2;
  }
  while ( v2 != 0 );
}



/* Original function: sub_12450 */
__int64 sub_12450()
{
  __int64 result; // rax
  __int64 v1; // rsi
  LONGLONG PerformanceCounter; // rbp
  ULONG v3; // ebx
  __int64 i; // rdi

  result = qword_17130;
  if ( qword_17130 == 0 )
  {
    KeQueryPerformanceCounter(nullptr);
    v1 = 1000;
    PerformanceCounter = KeQueryPerformanceCounter(nullptr);
    do
    {
      v3 = 100;
      for ( i = 2; i != 0; --i )
      {
        KeStallExecutionProcessor(0x32u);
        v3 -= 50;
      }
      if ( v3 != 0 )
        KeStallExecutionProcessor(v3);
      --v1;
    }
    while ( v1 != 0 );
    qword_17130 = (unsigned __int64)(KeQueryPerformanceCounter(nullptr) - PerformanceCounter)
                / 0x186A0;
    return qword_17130;
  }
  return result;
}



/* Original function: sub_12520 */
void *__fastcall sub_12520(ULONG Length, unsigned int a2, __int64 a3, LONGLONG *a4)
{
  unsigned __int64 v5; // rbp
  unsigned int v8; // ebx
  PVOID ContiguousMemory; // rax
  void *v11; // rsi
  __int64 v12; // rdi
  LONGLONG PhysicalAddress; // rax
  LONGLONG v14; // r11
  __int64 v15; // rbp
  LONGLONG *v16; // rdx
  PVOID *v17; // rcx
  void *v18; // rax
  struct _MDL *Mdl; // rax
  unsigned __int64 v20; // r11
  __int64 v21; // rax
  const void *v22; // rbx

  v5 = a2;
  v8 = 0;
  while ( _InterlockedCompareExchange((volatile signed __int32 *)&unk_17140 + 20 * v8, 1, 0) != 0 )
  {
    if ( ++v8 >= 0xC350 )
      return nullptr;
  }
  ContiguousMemory = MmAllocateContiguousMemory(Length + a2, (LONGLONG)0xFFFFFFFFLL);
  v11 = ContiguousMemory;
  if ( ContiguousMemory != nullptr )
  {
    memset(ContiguousMemory, 0, Length + (unsigned int)v5);
    v12 = 10LL * v8;
    *((_QWORD *)&unk_17140 + v12 + 1) = (_QWORD)v11;
    *((_DWORD *)&unk_17140 + 2 * v12 + 11) = Length + v5;
    *((_DWORD *)&unk_17140 + 2 * v12 + 10) = v5;
    PhysicalAddress = MmGetPhysicalAddress(v11);
    v14 = PhysicalAddress;
    *((LONGLONG *)&unk_17140 + v12 + 4) = PhysicalAddress;
    if ( (_DWORD)v5 != 0 && (unsigned int)(PhysicalAddress % v5) != 0 )
    {
      v15 = (unsigned int)v5 - (unsigned int)(PhysicalAddress % v5);
      v16 = (LONGLONG *)((char *)&unk_17140 + 80 * v8 + 24);
      v11 = (void *)((unsigned int)v15 + *((_QWORD *)&unk_17140 + 10 * v8 + 1));
      v17 = (PVOID *)((char *)&unk_17140 + 80 * v8 + 16);
      (*v16) = v15 + PhysicalAddress;
      *v17 = v11;
    }
    else
    {
      v18 = *((void **)&unk_17140 + 10 * v8 + 1);
      v16 = (LONGLONG *)((char *)&unk_17140 + 80 * v8 + 24);
      v17 = (PVOID *)((char *)&unk_17140 + 80 * v8 + 16);
      *v16 = v14;
      *v17 = v18;
    }
    if ( a4 != nullptr )
      *a4 = (*v16);
    if ( a3 != 0 )
    {
      Mdl = IoAllocateMdl(*v17, Length, 0, 0, nullptr);
      *((_QWORD *)&unk_17140 + 10 * v8 + 6) = Mdl;
      if ( Mdl != nullptr )
      {
        MmBuildMdlForNonPagedPool(Mdl);
        v20 = (unsigned __int64)MmMapLockedPagesSpecifyCache(
                                  *((PMDL *)&unk_17140 + 10 * v8 + 6),
                                  1,
                                  MmCached,
                                  nullptr,
                                  0,
                                  0x10u);
        *((_QWORD *)&unk_17140 + 10 * v8 + 7) = (_QWORD)v20;
        if ( v20 != 0 )
        {
          v21 = *((_QWORD *)&unk_17140 + 10 * v8 + 6);
          *((_QWORD *)&unk_17140 + 10 * v8 + 9) = a3;
          v22 = (const void *)((v20 & 0xFFFFFFFFFFFFF000uLL) + *(unsigned int *)(v21 + 44));
          *((_QWORD *)&unk_17140 + v12 + 8) = (_QWORD)v22;
          sub_11F30((char *)("_NalAllocateMemoryNonPaged - VirtualAddress = 0x%p\n"), v22);
          return (void *)v22;
        }
        sub_11F30((char *)("_NalAllocateMemoryNonPaged - MmMapLockedPages failed. Freeing MDL\n"));
        IoFreeMdl(*((PMDL *)&unk_17140 + 10 * v8 + 6));
        *((_QWORD *)&unk_17140 + 10 * v8 + 6) = 0;
      }
    }
  }
  else
  {
    sub_11F30((char *)("_NalAllocateMemoryNonPaged - MmAllocateContiguousMemory failed\n"));
    _InterlockedCompareExchange((volatile signed __int32 *)&unk_17140 + 20 * v8, 0, 1);
  }
  return v11;
}



/* Original function: sub_12770 */
void __fastcall sub_12770(const void *a1, __int64 a2)
{
  __int64 *v4; // r8
  __int64 v5; // rax
  const char *v6; // rcx
  __int64 v7; // rbx
  struct _MDL *v8; // rdx

  if ( a1 != nullptr )
  {
    if ( a2 != 0 )
    {
      v6 = (const char *)&unk_17188;
      v5 = 0;
      while ( 1 )
      {
        _mm_prefetch(v6 + 960, 1);
        if ( a2 == *(_QWORD *)v6 && a1 == *((const void **)v6 - 1) )
          break;
        v5 = (unsigned int)(v5 + 1);
        v6 += 80;
        if ( (unsigned int)v5 >= 0xC350 )
        {
LABEL_6:
          sub_11F30((char *)("_NalFreeMemoryNonPagedEx: Memory entry 0x%p is not entered into the table. Not freeing anything.\n"),
            a1);
          return;
        }
      }
    }
    else
    {
      v4 = &qword_17150;
      v5 = 0;
      while ( 1 )
      {
        _mm_prefetch((const char *)v4 + 960, 1);
        if ( a1 == (const void *)*v4 )
          break;
        v5 = (unsigned int)(v5 + 1);
        v4 += 10;
        if ( (unsigned int)v5 >= 0xC350 )
          goto LABEL_6;
      }
    }
    v7 = 10 * v5;
    if ( *((_QWORD *)&unk_17140 + 10 * v5 + 1) != 0 )
    {
      if ( a2 != 0 )
      {
        v8 = *((struct _MDL **)&unk_17140 + 10 * v5 + 6);
        if ( v8 != nullptr )
        {
          MmUnmapLockedPages(*((PVOID *)&unk_17140 + 10 * v5 + 7), v8);
          IoFreeMdl(*((PMDL *)&unk_17140 + v7 + 6));
        }
      }
      MmFreeContiguousMemory(*((PVOID *)&unk_17140 + v7 + 1));
    }
    *((_QWORD *)&unk_17140 + v7 + 3) = 0;
    *((_QWORD *)&unk_17140 + v7 + 2) = 0;
    *((_DWORD *)&unk_17140 + 2 * v7 + 10) = 0;
    *((_DWORD *)&unk_17140 + 2 * v7 + 11) = 0;
    *((_QWORD *)&unk_17140 + v7 + 4) = 0;
    *((_QWORD *)&unk_17140 + v7 + 1) = 0;
    *((_QWORD *)&unk_17140 + v7 + 6) = 0;
    *((_QWORD *)&unk_17140 + v7 + 7) = 0;
    *((_QWORD *)&unk_17140 + v7 + 8) = 0;
    *((_QWORD *)&unk_17140 + v7 + 9) = 0;
    _InterlockedCompareExchange((volatile signed __int32 *)&unk_17140 + 2 * v7, 0, 1);
  }
}



/* Original function: sub_128B0 */
void *__fastcall sub_128B0(ULONG a1, unsigned int a2, LONGLONG *a3)
{
  return sub_12520((ULONG)(a1),(unsigned int)(a2),(__int64)(0),(LONGLONG *)(a3));
}



/* Original function: sub_128E0 */
void __fastcall sub_128E0(const void *a1)
{
  __int64 *v1; // rax
  unsigned int v2; // edx
  __int64 v3; // rbx
  void *v4; // rcx

  if ( a1 != nullptr )
  {
    v1 = &qword_17150;
    v2 = 0;
    while ( 1 )
    {
      _mm_prefetch((const char *)v1 + 960, 1);
      if ( a1 == (const void *)*v1 )
        break;
      ++v2;
      v1 += 10;
      if ( v2 >= 0xC350 )
      {
        sub_11F30((char *)("_NalFreeMemoryNonPagedEx: Memory entry 0x%p is not entered into the table. Not freeing anything.\n"),
          a1);
        return;
      }
    }
    v3 = 10LL * v2;
    v4 = *((void **)&unk_17140 + 10 * v2 + 1);
    if ( v4 != nullptr )
      MmFreeContiguousMemory(v4);
    *((_QWORD *)&unk_17140 + v3 + 3) = 0;
    *((_QWORD *)&unk_17140 + v3 + 2) = 0;
    *((_DWORD *)&unk_17140 + 2 * v3 + 10) = 0;
    *((_DWORD *)&unk_17140 + 2 * v3 + 11) = 0;
    *((_QWORD *)&unk_17140 + v3 + 4) = 0;
    *((_QWORD *)&unk_17140 + v3 + 1) = 0;
    *((_QWORD *)&unk_17140 + v3 + 6) = 0;
    *((_QWORD *)&unk_17140 + v3 + 7) = 0;
    *((_QWORD *)&unk_17140 + v3 + 8) = 0;
    *((_QWORD *)&unk_17140 + v3 + 9) = 0;
    _InterlockedCompareExchange((volatile signed __int32 *)&unk_17140 + 2 * v3, 0, 1);
  }
}



/* Original function: sub_129C0 */
__int64 __fastcall sub_129C0(_QWORD *a1, LONGLONG a2, ULONG *a3, __int64 a4)
{
  SIZE_T v7; // rax
  unsigned int v8; // ebx
  PVOID v9; // rsi
  const void *v10; // rax

  if ( a1 == nullptr || a3 == nullptr )
    return 1;
  v7 = *a3;
  v8 = -932544508;
  if ( (_DWORD)v7 == 0 )
    return 3362422788LL;
  v9 = MmMapIoSpace(a2, v7, MmNonCached);
  sub_11F30((char *)("NalMmapAddressEx: Vaddress = 0x%p\n"), v9);
  if ( v9 != nullptr )
  {
    if ( a4 != 0 )
    {
      v10 = (const void *)sub_12030((PVOID)(v9),(ULONG)(*a3),(__int64)(a4));
      *a1 = v10;
      sub_11F30((char *)("NalMmapAddressEx: *VirtualAddress = 0x%p (mapped to user)\n"), v10);
    }
    else
    {
      *a1 = v9;
      sub_11F30((char *)("NalMmapAddressEx: *VirtualAddress = 0x%p (not mapped to user)\n"), v9);
    }
    if ( *a1 != 0 )
      return 0;
  }
  return v8;
}



/* Original function: sub_12AC0 */
__int64 __fastcall sub_12AC0(_QWORD *a1, LONGLONG a2, unsigned int *a3)
{
  SIZE_T v4; // rax
  unsigned int v5; // ebx
  PVOID v6; // rsi

  if ( a1 == nullptr || a3 == nullptr )
    return 1;
  v4 = *a3;
  v5 = -932544508;
  if ( (_DWORD)v4 == 0 )
    return 3362422788LL;
  v6 = MmMapIoSpace(a2, v4, MmNonCached);
  sub_11F30((char *)("NalMmapAddressEx: Vaddress = 0x%p\n"), v6);
  if ( v6 != nullptr )
  {
    *a1 = v6;
    sub_11F30((char *)("NalMmapAddressEx: *VirtualAddress = 0x%p (not mapped to user)\n"), v6);
    if ( *a1 != 0 )
      return 0;
  }
  return v5;
}



/* Original function: sub_12B70 */
__int64 __fastcall sub_12B70(PDEVICE_OBJECT DeviceObject, _WORD *Dst)
{
  PIRP v4; // rax
  struct _IO_STACK_LOCATION *CurrentStackLocation; // rcx
  struct _IO_STATUS_BLOCK IoStatusBlock; // [rsp+40h] [rbp-38h] BYREF
  struct _KEVENT Event; // [rsp+50h] [rbp-28h] BYREF

  memset(Dst, 0, 0x40u);
  *Dst = 64;
  Dst[1] = 1;
  *((_DWORD *)Dst + 2) = -1;
  *((_DWORD *)Dst + 3) = -1;
  KeInitializeEvent(&Event, NotificationEvent, 0);
  v4 = IoBuildSynchronousFsdRequest(0x1Bu, DeviceObject, nullptr, 0, nullptr, &Event, &IoStatusBlock);
  if ( v4 == nullptr )
    return 3221225626LL;
  CurrentStackLocation = v4->Tail.Overlay.CurrentStackLocation;
  v4->IoStatus.Status = -1073741637;
  CurrentStackLocation[-1].MajorFunction = 27;
  CurrentStackLocation[-1].MinorFunction = 9;
  CurrentStackLocation[-1].Parameters.WMI.ProviderId = (ULONG_PTR)Dst;
  if ( IofCallDriver(DeviceObject, v4) == 259 )
    KeWaitForSingleObject(&Event, Executive, 0, 0, nullptr);
  return (unsigned int)IoStatusBlock.Status;
}



/* Original function: sub_12C60 */
NTSTATUS __fastcall sub_12C60(PDEVICE_OBJECT DeviceObject, __int64 a2, char a3, int a4, int a5)
{
  PIRP v9; // rax
  __int64 v10; // rdx
  NTSTATUS result; // eax
  int v12; // [rsp+40h] [rbp-58h]
  struct _IO_STATUS_BLOCK IoStatusBlock; // [rsp+48h] [rbp-50h] BYREF
  struct _KEVENT Object; // [rsp+58h] [rbp-40h] BYREF

  KeInitializeEvent(&Object, NotificationEvent, 0);
  v9 = IoBuildSynchronousFsdRequest(0x1Bu, DeviceObject, nullptr, 0, nullptr, &Object, &IoStatusBlock);
  if ( v9 == nullptr )
    return v12;
  v10 = (__int64)&v9->Tail.Overlay.CurrentStackLocation[-1];
  if ( v9->Tail.Overlay.CurrentStackLocation == (struct _IO_STACK_LOCATION *)72 )
    return v12;
  v9->IoStatus.Status = -1073741637;
  *(_BYTE *)v10 = 27;
  *(_DWORD *)(v10 + 32) = a5;
  *(_BYTE *)(v10 + 1) = a3;
  *(_QWORD *)(v10 + 16) = a2;
  *(_DWORD *)(v10 + 8) = 0;
  *(_DWORD *)(v10 + 24) = a4;
  result = IofCallDriver(DeviceObject, v9);
  if ( result == 259 )
  {
    KeWaitForSingleObject(&Object, Executive, 0, 0, nullptr);
    return IoStatusBlock.Status;
  }
  return result;
}



/* Original function: sub_12D70 */
__int64 __fastcall sub_12D70(__int64 a1)
{
  struct _DEVICE_OBJECT *v1; // rdi
  char v3; // bp
  ULONG v4; // r12d
  PIRP v5; // rax
  __int64 v6; // rdx
  NTSTATUS v7; // r13d
  char v8; // di
  WCHAR *PoolWithTag; // rsi
  char *v10; // r8
  char *v11; // rcx
  __int64 v12; // rdx
  char v13; // al
  unsigned int v14; // edx
  char *v15; // rcx
  __int64 v16; // rax
  ULONG ResultLength; // [rsp+40h] [rbp-1D8h] BYREF
  void *KeyHandle; // [rsp+48h] [rbp-1D0h] BYREF
  struct _STRING AnsiString; // [rsp+50h] [rbp-1C8h] BYREF
  struct _OBJECT_ATTRIBUTES ObjectAttributes; // [rsp+60h] [rbp-1B8h] BYREF
  UNICODE_STRING SourceString; // [rsp+90h] [rbp-188h] BYREF
  struct _KEVENT Object; // [rsp+A0h] [rbp-178h] BYREF
  struct _UNICODE_STRING DestinationString; // [rsp+B8h] [rbp-160h] BYREF
  struct _IO_STATUS_BLOCK IoStatusBlock; // [rsp+C8h] [rbp-150h] BYREF
  unsigned char v26[256]; // [rsp+E0h] [rbp-138h] BYREF
  volatile uintptr_t StackCookie; // [rsp+1E0h] [rbp-38h]

  StackCookie = BugCheckParameter2;
  v1 = *(struct _DEVICE_OBJECT **)(a1 + 56);
  v3 = 0;
  v4 = 0;
  (*(_DWORD *)(v26 + 16)) = 0;
  KeInitializeEvent(&Object, NotificationEvent, 0);
  v5 = IoBuildSynchronousFsdRequest(0x1Bu, v1, nullptr, 0, nullptr, &Object, &IoStatusBlock);
  if ( v5 != nullptr )
  {
    v6 = (__int64)&v5->Tail.Overlay.CurrentStackLocation[-1];
    if ( v5->Tail.Overlay.CurrentStackLocation != (struct _IO_STACK_LOCATION *)72 )
    {
      v5->IoStatus.Status = -1073741637;
      *(_BYTE *)v6 = 27;
      *(_QWORD *)(v6 + 16) = (_QWORD)&v26;
      *(_BYTE *)(v6 + 1) = 15;
      *(_DWORD *)(v6 + 32) = 64;
      *(_DWORD *)(v6 + 8) = 0;
      *(_DWORD *)(v6 + 24) = 0;
      if ( IofCallDriver(v1, v5) == 259 )
        KeWaitForSingleObject(&Object, Executive, 0, 0, nullptr);
    }
  }
  RtlInitUnicodeString(&DestinationString, L"\\REGISTRY\\MACHINE\\HARDWARE\\RESOURCEMAP\\PnP Manager\\PnpManager");
  ObjectAttributes.ObjectName = &DestinationString;
  ObjectAttributes.Length = 48;
  ObjectAttributes.RootDirectory = nullptr;
  ObjectAttributes.Attributes = 64;
  ObjectAttributes.SecurityDescriptor = nullptr;
  ObjectAttributes.SecurityQualityOfService = nullptr;
  v7 = ZwOpenKey(&KeyHandle, (ACCESS_MASK)0x20019, &ObjectAttributes);
  if ( v7 >= 0 )
  {
    do
    {
      v8 = 0;
      ZwEnumerateValueKey(KeyHandle, v4, KeyValueFullInformation, nullptr, 0, &ResultLength);
      PoolWithTag = (WCHAR *)ExAllocatePoolWithTag(PagedPool, ResultLength + 8LL, 0x206B6444u);
      v7 = ZwEnumerateValueKey(KeyHandle, v4, KeyValueFullInformation, PoolWithTag, ResultLength, &ResultLength);
      if ( v7 >= 0 )
      {
        if ( *((_DWORD *)PoolWithTag + 1) == 8 )
        {
          RtlInitUnicodeString(&SourceString, PoolWithTag + 10);
          RtlUnicodeStringToAnsiString(&AnsiString, &SourceString, 1u);
          if ( strstr(AnsiString.Buffer, "Translated") != nullptr && strstr(AnsiString.Buffer, "NTPNP") != nullptr )
          {
            v10 = (char *)PoolWithTag + *((unsigned int *)PoolWithTag + 2);
            if ( *((_DWORD *)v10 + 1) == 5 && *((_DWORD *)v10 + 4) != 0 )
            {
              v11 = v10 + 20;
              v12 = *((unsigned int *)v10 + 4);
              do
              {
                if ( *v11 == 3 && *((_DWORD *)v11 + 1) == (*(_DWORD *)(v26 + 16)) )
                {
                  v13 = v8;
                  if ( v8 == 0 )
                    v13 = 1;
                  v8 = v13;
                }
                v11 += 20;
                --v12;
              }
              while ( v12 != 0 );
              if ( v8 == 1 )
              {
                v14 = 0;
                v15 = v10 + 24;
                do
                {
                  if ( *(v15 - 4) == 2 )
                  {
                    *(_DWORD *)(a1 + 12) = *((_DWORD *)v15 + 1);
                    *(_BYTE *)(a1 + 8) = *v15;
                    v16 = *((_QWORD *)v15 + 1);
                    *(_DWORD *)(a1 + 24) = 0;
                    *(_QWORD *)(a1 + 16) = (_QWORD)v16;
                  }
                  ++v14;
                  v15 += 20;
                }
                while ( v14 < *((_DWORD *)v10 + 4) );
                v3 = 1;
              }
            }
          }
          RtlFreeAnsiString(&AnsiString);
          ++v4;
        }
      }
      else
      {
        v3 = 1;
      }
      if ( PoolWithTag != nullptr )
        ExFreePoolWithTag(PoolWithTag, 0);
    }
    while ( v3 == 0 );
  }
  if ( KeyHandle != nullptr )
    ZwClose(KeyHandle);
  { nal_check_cookie(StackCookie); return (unsigned int)v7; }
}



/* Original function: sub_13100 */
__int64 sub_13100()
{
  return 0;
}



/* Original function: sub_13110 */
__int64 __fastcall sub_13110(__int64 a1)
{
  struct _DEVICE_OBJECT *v1; // rbx
  PIRP v3; // rax
  struct _IO_STACK_LOCATION *CurrentStackLocation; // rdx
  NTSTATUS Status; // eax
  _QWORD *PoolWithTag; // rbx
  struct _IO_STATUS_BLOCK IoStatusBlock; // [rsp+40h] [rbp-58h] BYREF
  struct _KEVENT Object; // [rsp+50h] [rbp-48h] BYREF
  int v10; // [rsp+68h] [rbp-30h]
  int v11; // [rsp+6Ch] [rbp-2Ch]
  int v12; // [rsp+70h] [rbp-28h]
  int v13; // [rsp+74h] [rbp-24h]
  int v14; // [rsp+78h] [rbp-20h]
  int v15; // [rsp+7Ch] [rbp-1Ch]
  volatile uintptr_t StackCookie; // [rsp+80h] [rbp-18h]

  StackCookie = BugCheckParameter2;
  v1 = *(struct _DEVICE_OBJECT **)(a1 + 56);
  v10 = 0;
  v11 = 0;
  v12 = 0;
  v13 = 0;
  v14 = 0;
  v15 = 0;
  KeInitializeEvent(&Object, NotificationEvent, 0);
  v3 = IoBuildSynchronousFsdRequest(0x1Bu, v1, nullptr, 0, nullptr, &Object, &IoStatusBlock);
  if ( v3 != nullptr )
  {
    CurrentStackLocation = v3->Tail.Overlay.CurrentStackLocation;
    v3->IoStatus.Status = -1073741637;
    CurrentStackLocation[-1].MajorFunction = 27;
    CurrentStackLocation[-1].MinorFunction = 21;
    Status = IofCallDriver(v1, v3);
    if ( Status == 259 )
    {
      KeWaitForSingleObject(&Object, Executive, 0, 0, nullptr);
      Status = IoStatusBlock.Status;
    }
    else if ( Status == 0 )
    {
      Status = IoStatusBlock.Status;
    }
    if ( Status >= 0 )
    {
      v15 = *(_DWORD *)(IoStatusBlock.Information + 20);
      ExFreePoolWithTag((PVOID)IoStatusBlock.Information, 0);
    }
  }
  PoolWithTag = ExAllocatePoolWithTag(PagedPool, 0x40u, 0x206B6444u);
  if ( PoolWithTag != nullptr )
  {
    *PoolWithTag = 0;
    PoolWithTag[1] = 0;
    PoolWithTag[2] = 0;
    PoolWithTag[3] = 0;
    PoolWithTag[4] = 0;
    PoolWithTag[5] = 0;
    PoolWithTag[6] = 0;
    PoolWithTag[7] = 0;
    sub_12B70((PDEVICE_OBJECT)(*(PDEVICE_OBJECT *)(a1 + 56)),(_WORD *)(PoolWithTag));
    *(_BYTE *)a1 = v15;
    *(_DWORD *)a1 ^= (*(_DWORD *)a1 ^ (*((_DWORD *)PoolWithTag + 2) >> 8)) & 0x1F00;
    *(_DWORD *)a1 ^= ((unsigned __int16)*(_DWORD *)a1
                    ^ (unsigned __int16)((unsigned __int16)*((_DWORD *)PoolWithTag + 2) << 13))
                   & 0xE000;
    ExFreePoolWithTag(PoolWithTag, 0);
  }
  { nal_check_cookie(StackCookie); return 0; }
}



/* Original function: sub_132B0 */
void __fastcall sub_132B0(__int64 *a1)
{
  const WCHAR *v2; // rbx
  USHORT Length; // r11
  unsigned __int16 v4; // cx
  PFILE_OBJECT v5; // rbp
  __int64 v6; // rdi
  PDEVICE_OBJECT v7; // r12
  PVOID v8; // rax
  PVOID PoolWithTag; // rsi
  _QWORD *i; // rax
  PFILE_OBJECT FileObject; // [rsp+20h] [rbp-68h] BYREF
  PCWSTR SourceString; // [rsp+28h] [rbp-60h] BYREF
  PDEVICE_OBJECT DeviceObject; // [rsp+30h] [rbp-58h] BYREF
  struct _UNICODE_STRING DestinationString; // [rsp+38h] [rbp-50h] BYREF
  GUID v15; // [rsp+48h] [rbp-40h] BYREF
  volatile uintptr_t StackCookie; // [rsp+58h] [rbp-30h]

  StackCookie = BugCheckParameter2;
  v15.Data1 = -1387689660;
  v15.Data2 = 30255;
  v15.Data3 = 4560;
  v15.Data4[0] = -115;
  v15.Data4[1] = -53;
  v15.Data4[2] = 0;
  v15.Data4[3] = -64;
  v15.Data4[4] = 79;
  v15.Data4[5] = -61;
  v15.Data4[6] = 53;
  v15.Data4[7] = -116;
  FileObject = nullptr;
  DeviceObject = nullptr;
  SourceString = nullptr;
  if ( IoGetDeviceInterfaces(&v15, nullptr, 1u, (PZZWSTR *)&SourceString) >= 0 )
  {
    v2 = SourceString;
    RtlInitUnicodeString(&DestinationString, SourceString);
    Length = DestinationString.Length;
    if ( DestinationString.Length != 0 )
    {
      while ( 1 )
      {
        if ( Length > 4u )
        {
          v4 = 0;
          if ( Length > 4u )
            break;
        }
LABEL_22:
        v2 += (unsigned __int64)DestinationString.MaximumLength >> 1;
        RtlInitUnicodeString(&DestinationString, v2);
        Length = DestinationString.Length;
        if ( DestinationString.Length == 0 )
          goto LABEL_23;
      }
      while ( 1 )
      {
        if ( v4 >= 0x14u )
          goto LABEL_22;
        if ( v2[v4] == 86 && v2[v4 + 1] == 69 && v2[v4 + 2] == 78 && v2[v4 + 3] == 95 )
          break;
        if ( ++v4 >= Length - 4 )
          goto LABEL_22;
      }
      if ( IoGetDeviceObjectPointer(&DestinationString, (ACCESS_MASK)0x1F01FF, &FileObject, &DeviceObject) >= 0 )
      {
        v5 = FileObject;
        v6 = *a1;
        v7 = FileObject->DeviceObject;
        if ( *a1 != 0 )
        {
          PoolWithTag = ExAllocatePoolWithTag(NonPagedPool, 0x250u, 0x206B6444u);
          for ( i = (_QWORD *)(v6 + 584); *i != 0; i = (_QWORD *)(*i + 584LL) )
            v6 = *i;
          *(_QWORD *)(v6 + 584) = PoolWithTag;
          goto LABEL_19;
        }
        v8 = ExAllocatePoolWithTag(NonPagedPool, 0x250u, 0x206B6444u);
        PoolWithTag = v8;
        if ( v8 != nullptr )
        {
          *a1 = (__int64)v8;
LABEL_19:
          if ( PoolWithTag != nullptr )
          {
            *((_QWORD *)PoolWithTag + 7) = (_QWORD)v7;
            *((_QWORD *)PoolWithTag + 6) = (_QWORD)v5;
            *((_QWORD *)PoolWithTag + 73) = 0;
            sub_13110((__int64)((__int64)PoolWithTag));
            ++*((_DWORD *)a1 + 2);
            sub_12D70((__int64)((__int64)PoolWithTag));
            wcsncpy((wchar_t *)PoolWithTag + 32, v2, 0x103u);
          }
        }
      }
      FileObject = nullptr;
      DeviceObject = nullptr;
      goto LABEL_22;
    }
LABEL_23:
    ExFreePoolWithTag((PVOID)SourceString, 0);
  }
  nal_check_cookie(StackCookie);
}



/* Original function: sub_13540 */
__int64 __fastcall sub_13540(int *a1)
{
  __int64 v2; // rsi
  PVOID *v3; // rdi
  _QWORD *v4; // rbx
  unsigned int i; // r11d
  int v6; // ecx
  int v7; // edx
  PVOID *v8; // rbx
  NAL_LIST list;

  v2 = 0;
  list.head = nullptr;
  list.count = 0;
  sub_132B0((__int64 *)((__int64 *)&list.head));
  v3 = (PVOID *)list.head;
  v4 = list.head;
  if ( a1 != nullptr )
  {
    sub_11F30((char *)("Looking for match for %d/%d/%d\n"),
      (unsigned __int8)*a1,
      ((unsigned int)*a1 >> 8) & 0x1F,
      (unsigned __int16)*a1 >> 13);
    for ( i = 0; i < list.count; ++i )
    {
      if ( v4 == nullptr )
        break;
      v6 = *(_DWORD *)v4;
      v7 = *a1;
      if ( (unsigned __int8)*a1 == *(_BYTE *)v4
        && (((unsigned __int16)v7 ^ (unsigned __int16)v6) & 0x1F00) == 0
        && (((unsigned __int16)v7 ^ (unsigned __int16)v6) & 0xE000) == 0 )
      {
        v2 = v4[7];
      }
      v4 = (_QWORD *)v4[73];
    }
  }
  if ( v3 != nullptr )
  {
    do
    {
      ObfDereferenceObject(v3[6]);
      v8 = (PVOID *)v3[73];
      ExFreePoolWithTag(v3, 0);
      v3 = v8;
    }
    while ( v8 != nullptr );
  }
  return v2;
}



/* Original function: sub_13640 */
__int64 __fastcall sub_13640(int *a1, PVOID *a2)
{
  unsigned int v4; // esi
  PVOID *v5; // rdi
  _QWORD *v6; // rdx
  int v7; // r8d
  int v8; // ecx
  int v9; // r9d
  PVOID *v10; // rbx
  NAL_LIST list;

  list.head = nullptr;
  list.count = 0;
  v4 = -932560894;
  sub_132B0((__int64 *)((__int64 *)&list.head));
  v5 = (PVOID *)list.head;
  v6 = list.head;
  if ( a1 != nullptr )
  {
    v7 = 0;
    if ( list.count != 0 )
    {
      while ( v6 != nullptr )
      {
        v8 = *(_DWORD *)v6;
        v9 = *a1;
        if ( (unsigned __int8)*a1 == *(_BYTE *)v6
          && (((unsigned __int16)v9 ^ (unsigned __int16)v8) & 0x1F00) == 0
          && (((unsigned __int16)v9 ^ (unsigned __int16)v8) & 0xE000) == 0 )
        {
          memmove(a2, v6, 0x250u);
          ObReferenceObjectByPointer(a2[6], (ACCESS_MASK)0x1F01FF, nullptr, 0);
          v4 = 0;
          break;
        }
        v6 = (_QWORD *)v6[73];
        if ( ++v7 >= list.count )
          break;
      }
    }
  }
  if ( v5 != nullptr )
  {
    do
    {
      ObfDereferenceObject(v5[6]);
      v10 = (PVOID *)v5[73];
      ExFreePoolWithTag(v5, 0);
      v5 = v10;
    }
    while ( v10 != nullptr );
  }
  return v4;
}



/* Original function: sub_13740 */
__int16 sub_13740()
{
  PVOID *v0; // rdi
  PVOID *v1; // rbx
  NAL_LIST list;

  list.head = nullptr;
  list.count = 0;
  sub_132B0((__int64 *)((__int64 *)&list.head));
  sub_11F30((char *)("_NalReadPciDeviceCount found %d devices (%d)\n"), (unsigned __int16)list.count, list.count);
  v0 = (PVOID *)list.head;
  if ( list.head != nullptr )
  {
    do
    {
      ObfDereferenceObject(v0[6]);
      v1 = (PVOID *)v0[73];
      ExFreePoolWithTag(v0, 0);
      v0 = v1;
    }
    while ( v1 != nullptr );
  }
  return list.count;
}



/* Original function: sub_137D0 */
__int64 __fastcall sub_137D0(__int64 a1, unsigned __int16 *a2)
{
  PVOID *v4; // rdi
  unsigned __int16 v5; // si
  _QWORD *i; // r8
  __int64 v7; // rdx
  PVOID *v8; // rbx
  NAL_LIST list;

  list.head = nullptr;
  list.count = 0;
  sub_132B0((__int64 *)((__int64 *)&list.head));
  v4 = (PVOID *)list.head;
  v5 = 0;
  for ( i = list.head; v5 < *a2; i = (_QWORD *)i[73] )
  {
    if ( i == nullptr )
      break;
    v7 = v5++;
    v7 *= 264;
    *(_BYTE *)(v7 + a1) = *(_BYTE *)i;
    *(_DWORD *)(v7 + a1) ^= (*(_DWORD *)i ^ *(_DWORD *)(v7 + a1)) & 0x1F00;
    *(_DWORD *)(v7 + a1) ^= (*(_DWORD *)i ^ *(_DWORD *)(v7 + a1)) & 0xE000;
  }
  if ( v4 != nullptr )
  {
    do
    {
      ObfDereferenceObject(v4[6]);
      v8 = (PVOID *)v4[73];
      ExFreePoolWithTag(v4, 0);
      v4 = v8;
    }
    while ( v8 != nullptr );
  }
  *a2 = v5;
  return 0;
}



/* Original function: sub_138B0 */
__int64 __fastcall sub_138B0(int *a1, void *a2, unsigned int a3)
{
  __int64 v5; // r12
  unsigned int v6; // ebx
  PVOID PoolWithTag; // rax
  void *v8; // rdi
  struct _DEVICE_OBJECT *v9; // rax

  v5 = a3;
  v6 = -932544510;
  PoolWithTag = ExAllocatePoolWithTag(NonPagedPool, 0x100u, 0x206B6444u);
  v8 = PoolWithTag;
  if ( a2 != nullptr )
  {
    if ( PoolWithTag == nullptr )
      return v6;
    v9 = (struct _DEVICE_OBJECT *)sub_13540((int *)(a1));
    if ( v9 != nullptr )
    {
      sub_12C60((PDEVICE_OBJECT)(v9),(__int64)((__int64)v8),(char)(15),(int)(0),(int)(64));
      memmove(a2, v8, 4 * v5);
      v6 = 0;
    }
  }
  if ( v8 != nullptr )
    sub_11DC0((void *)(v8));
  return v6;
}



/* Original function: sub_13980 */
__int64 __fastcall sub_13980(int *a1, int a2, __int64 a3)
{
  struct _DEVICE_OBJECT *v5; // rax
  NTSTATUS v6; // eax
  unsigned int v7; // ecx

  if ( a3 == 0 )
    return 3362406402LL;
  v5 = (struct _DEVICE_OBJECT *)sub_13540((int *)(a1));
  if ( v5 == nullptr )
    return 3362406402LL;
  v6 = sub_12C60((PDEVICE_OBJECT)(v5),(__int64)(a3),(char)(15),(int)(4 * a2),(int)(4));
  v7 = -932560887;
  if ( v6 >= 0 )
    return 0;
  return v7;
}



/* Original function: sub_13A00 */
__int64 __fastcall sub_13A00(int *a1, int a2, int a3)
{
  struct _DEVICE_OBJECT *v4; // rbx
  PIRP v5; // rax
  __int64 v6; // rcx
  NTSTATUS Status; // r11d
  __int64 result; // rax
  NTSTATUS v9; // [rsp+40h] [rbp-48h]
  struct _IO_STATUS_BLOCK IoStatusBlock; // [rsp+48h] [rbp-40h] BYREF
  struct _KEVENT Event; // [rsp+58h] [rbp-30h] BYREF
  int v12; // [rsp+A0h] [rbp+18h] BYREF

  v12 = a3;
  v4 = (struct _DEVICE_OBJECT *)sub_13540((int *)(a1));
  if ( v4 == nullptr )
    return 3362406402LL;
  KeInitializeEvent(&Event, NotificationEvent, 0);
  v5 = IoBuildSynchronousFsdRequest(0x1Bu, v4, nullptr, 0, nullptr, &Event, &IoStatusBlock);
  if ( v5 == nullptr
    || (v6 = (__int64)&v5->Tail.Overlay.CurrentStackLocation[-1],
        v5->Tail.Overlay.CurrentStackLocation == (struct _IO_STACK_LOCATION *)72) )
  {
    Status = v9;
  }
  else
  {
    v5->IoStatus.Status = -1073741637;
    *(_BYTE *)v6 = 27;
    *(_QWORD *)(v6 + 16) = &v12;
    *(_BYTE *)(v6 + 1) = 16;
    *(_DWORD *)(v6 + 32) = 4;
    *(_DWORD *)(v6 + 8) = 0;
    *(_DWORD *)(v6 + 24) = 4 * a2;
    Status = IofCallDriver(v4, v5);
    if ( Status == 259 )
    {
      KeWaitForSingleObject(&Event, Executive, 0, 0, nullptr);
      Status = IoStatusBlock.Status;
    }
  }
  result = 3362406409LL;
  if ( Status >= 0 )
    return 0;
  return result;
}



/* Original function: sub_13B20 */
__int64 __fastcall sub_13B20(int *Src, int a2, char a3, unsigned int a4)
{
  unsigned int v8; // r12d
  struct _DEVICE_OBJECT *v9; // rax
  struct _DEVICE_OBJECT *v10; // rbp
  _DWORD v12[4]; // [rsp+30h] [rbp-158h] BYREF
  int Dst[70]; // [rsp+40h] [rbp-148h] BYREF

  v8 = -932560894;
  v12[0] = 0;
  v9 = (struct _DEVICE_OBJECT *)sub_13540((int *)(Src));
  v10 = v9;
  if ( v9 != nullptr )
  {
    v8 = 0;
    switch ( a3 )
    {
      case 15:
        memmove(Dst, Src, 0x108u);
        return sub_13A00((int *)(Dst),(int)(a2),(int)(a4));
      case 3:
        v12[0] = (unsigned __int16)a4;
        sub_12C60((PDEVICE_OBJECT)(v9),(__int64)((__int64)v12),(char)(16),(int)(4 * a2),(int)(2));
        return 0;
      case 12:
        v12[0] = HIWORD(a4);
        sub_12C60((PDEVICE_OBJECT)(v9),(__int64)((__int64)v12),(char)(16),(int)(4 * a2),(int)(2));
        return 0;
      default:
        break;
    }
    if ( (a3 & 1) != 0 )
    {
      v12[0] = (unsigned __int8)a4;
      sub_12C60((PDEVICE_OBJECT)(v9),(__int64)((__int64)v12),(char)(16),(int)(4 * a2),(int)(1));
    }
    if ( (a3 & 2) != 0 )
    {
      v12[0] = BYTE1(a4);
      sub_12C60((PDEVICE_OBJECT)(v10),(__int64)((__int64)v12),(char)(16),(int)(4 * a2 + 1),(int)(1));
    }
    if ( (a3 & 4) != 0 )
    {
      v12[0] = BYTE2(a4);
      sub_12C60((PDEVICE_OBJECT)(v10),(__int64)((__int64)v12),(char)(16),(int)(4 * a2 + 2),(int)(1));
    }
    if ( (a3 & 8) != 0 )
    {
      v12[0] = HIBYTE(a4);
      sub_12C60((PDEVICE_OBJECT)(v10),(__int64)((__int64)v12),(char)(16),(int)(4 * a2 + 3),(int)(1));
    }
  }
  return v8;
}



/* Original function: sub_13D00 */
__int64 __fastcall sub_13D00(__int64 a1, __int64 a2)
{
  __int64 v4; // rax
  const void *v5; // rdx

  if ( a1 == 0 || a2 == 0 )
    return 1;
  memmove((void *)(a2 + 8), (const void *)(a1 + 8), 0x108u);
  *(_BYTE *)(a2 + 296) = *(_BYTE *)(a1 + 296);
  *(_QWORD *)a2 = *(_QWORD *)a1;
  *(_QWORD *)(a2 + 272) = *(_QWORD *)(a1 + 272);
  *(_QWORD *)(a2 + 288) = *(_QWORD *)(a1 + 288);
  v4 = *(_QWORD *)(a1 + 280);
  *(_BYTE *)(a2 + 336) = 0;
  *(_QWORD *)(a2 + 280) = (_QWORD)v4;
  v5 = *(const void **)(a2 + 280);
  *(_DWORD *)(a2 + 320) = *(_DWORD *)(a2 + 368);
  *(_DWORD *)(a2 + 308) = *(_DWORD *)(a2 + 356);
  *(_BYTE *)(a2 + 304) = *(_BYTE *)(a2 + 352);
  *(_QWORD *)(a2 + 312) = *(_QWORD *)(a2 + 360);
  sub_11F30((char *)("FillKernelContext: VirtualAddress: %p\n"), v5);
  return 0;
}



/* Original function: sub_13DF0 */
__int64 sub_13DF0()
{
  return 3362390019LL;
}



/* Original function: sub_13E00 */
char __fastcall sub_13E00(__int64 a1)
{
  const char *v2; // rdx
  char result; // al

  if ( a1 == 0 )
    return 0;
  v2 = "FALSE";
  if ( *(_BYTE *)(a1 + 297) != 0 )
    v2 = "TRUE";
  sub_11F30((char *)("_NalHasInterruptOccurred returning %s\n"), v2);
  result = *(_BYTE *)(a1 + 297);
  *(_BYTE *)(a1 + 297) = 0;
  return result;
}



/* Original function: sub_13E60 */
PVOID sub_13E60()
{
  PVOID result; // rax
  PVOID v1; // rbx

  result = ExAllocatePoolWithTag(NonPagedPool, 0x630u, 0x206B6444u);
  v1 = result;
  if ( result != nullptr )
  {
    memset(result, 0, 0x630u);
    return v1;
  }
  return result;
}



/* Original function: sub_13EA0 */
void __fastcall sub_13EA0(PVOID *P)
{
  if ( P != nullptr )
  {
    if ( *((_DWORD *)P + 234) != 0 )
    {
      ObfDereferenceObject(P[49]);
      --*((_DWORD *)P + 234);
    }
    if ( *((_DWORD *)P + 234) == 0 )
      ExFreePoolWithTag(P, 0);
  }
}



/* Original function: sub_13EF0 */
void __fastcall sub_13EF0(__int64 a1, __int64 a2)
{
  NTSTATUS v3; // eax
  PCHAR Buffer; // rcx
  PCHAR v5; // rdx
  __int64 v6; // rbx
  CHAR v7; // al
  struct _STRING v8; // [rsp+20h] [rbp-28h] BYREF
  struct _UNICODE_STRING DestinationString; // [rsp+30h] [rbp-18h] BYREF

  if ( a1 != 0 )
  {
    RtlInitUnicodeString(&DestinationString, (PCWSTR)(a1 + 408));
    v8.Length = 260;
    v8.MaximumLength = 260;
    v8.Buffer = (PCHAR)ExAllocatePoolWithTag(PagedPool, 0x104u, 0x206B6444u);
    if ( v8.Buffer != nullptr )
    {
      v3 = RtlUnicodeStringToAnsiString(&v8, &DestinationString, 0);
      Buffer = v8.Buffer;
      if ( v3 >= 0 )
      {
        v5 = v8.Buffer;
        v6 = a2 - (unsigned __int64)v8.Buffer;
        do
        {
          v7 = *v5++;
          v5[v6 - 1] = v7;
        }
        while ( v7 != 0 );
      }
      ExFreePoolWithTag(Buffer, 0);
    }
  }
}



/* Original function: sub_13FA0 */
__int64 __fastcall sub_13FA0(_QWORD *a1)
{
  unsigned char context[304];
  unsigned int v2; // ebx
  __int64 *v3; // rdi
  __int64 v4; // rbx
  _QWORD *v5; // rdi
  _QWORD *v6; // rdi
  char v7; // r11
  __int64 v8; // rdx
  __int64 v9; // rax
  _DWORD *v10; // rdi
  _BYTE *v11; // rdi
  _BYTE *v12; // rdi
  _BYTE Dst[272]; // [rsp+20h] [rbp-4D8h] BYREF
  volatile uintptr_t StackCookie; // [rsp+4E0h] [rbp-18h]

  StackCookie = BugCheckParameter2;
  v2 = 1;
  if ( a1 != nullptr )
  {
    sub_11F30((char *)("NalOsSpecificIoctl: FunctionId = %d\n"), *a1);
    switch ( *a1 )
    {
      case 1LL:
        v3 = a1 + 2;
        if ( v3 != nullptr )
        {
          memmove(Dst, v3 + 1, 0x108u);
          v4 = *v3;
          sub_13640((int *)(Dst),(PVOID *)(*v3 + 344));
          ++*(_DWORD *)(v4 + 936);
          v2 = 0;
        }
        else
        {
          sub_11F30((char *)("NalResolveOsSpecificIoctl: NAL_WIN_GET_PDO_POINTER_FUNCID FunctionData is NULL\n"));
        }
        break;
      case 2LL:
        if ( a1 == (_QWORD *)-16LL )
        {
          sub_11F30((char *)("NalResolveOsSpecificIoctl: NAL_WIN_GET_SYMBOLIC_NAME_FUNCID FunctionData is NULL\n"));
        }
        else
        {
          sub_13EF0((__int64)(a1[2]),(__int64)(a1 + 3));
          v2 = 0;
        }
        break;
      case 3LL:
        v5 = a1 + 2;
        if ( v5 != nullptr )
        {
          v2 = 0;
          *v5 = sub_13E60();
        }
        else
        {
          sub_11F30((char *)("NalResolveOsSpecificIoctl: NAL_WIN_ALLOC_DEV_CONTEXT_FUNCID FunctionData is NULL\n"));
        }
        break;
      case 4LL:
        if ( a1 == (_QWORD *)-16LL )
        {
          sub_11F30((char *)("NalResolveOsSpecificIoctl: NAL_WIN_FREE_DEV_CONTEXT_FUNCID FunctionData is NULL\n"));
        }
        else
        {
          sub_13EA0((PVOID *)((PVOID)a1[2]));
          v2 = 0;
        }
        break;
      case 5LL:
        v6 = a1 + 2;
        if ( v6 != nullptr )
        {
          memmove((context + 8), v6 + 1, 0x108u);
          v7 = *((_BYTE *)v6 + 296);
          v8 = v6[38];
          (*(_QWORD *)(context + 0)) = *v6;
          (*(_QWORD *)(context + 272)) = v6[34];
          (*(_QWORD *)(context + 288)) = v6[36];
          v9 = v6[35];
          context[296] = v7;
          (*(_QWORD *)(context + 280)) = (_QWORD)v9;
          v2 = 0;
          *((_DWORD *)v6 + 78) = sub_13D00((__int64)(context),(__int64)(v8));
        }
        else
        {
          sub_11F30((char *)("NalResolveOsSpecificIoctl: NAL_WIN_OS_DEVICE_FUNCID FunctionData is NULL\n"));
        }
        break;
      case 6LL:
        v10 = a1 + 2;
        if ( v10 != nullptr )
        {
          v2 = 0;
          *v10 = sub_11210();
        }
        else
        {
          sub_11F30((char *)("NalResolveOsSpecificIoctl: NAL_WIN_DRIVER_GET_REF_COUNT_FUNCID FunctionData is NULL\n"));
        }
        break;
      case 7LL:
        v11 = a1 + 2;
        if ( v11 != nullptr )
        {
          memmove(Dst, v11, 0x108u);
          v2 = 0;
          v11[264] = sub_11220((__int64 *)(Dst),(char)((unsigned __int8)v11[265]));
        }
        else
        {
          sub_11F30((char *)("NalResolveOsSpecificIoctl: NAL_WIN_ADAPTER_IN_USE_FUNCID FunctionData is NULL\n"));
        }
        break;
      case 8LL:
        v12 = a1 + 2;
        if ( v12 != nullptr )
        {
          memmove(Dst, v12, 0x108u);
          v2 = 0;
          v12[264] = sub_112F0((__int64 *)(Dst));
        }
        else
        {
          sub_11F30((char *)("NalResolveOsSpecificIoctl: NAL_WIN_IS_ADAPTER_IN_USE_FUNCID FunctionData is NULL\n"));
        }
        break;
      default:
        sub_11F30((char *)("NalResolveOsSpecificIoctl: FuctionId = %d\n"), *a1);
        v2 = -932569064;
        break;
    }
  }
  { nal_check_cookie(StackCookie); return v2; }
}



/* Original function: sub_14270 */
__declspec(noreturn) void __fastcall sub_14270(ULONG_PTR BugCheckParameter1)
{
  KeBugCheckEx(0xF7u, BugCheckParameter1, BugCheckParameter2, BugCheckParameter3, 0);
}



/* Original function: sub_5E2010 */
__int64 __fastcall sub_5E2010(PDRIVER_OBJECT DriverObject)
{
  char *v3; // rax
  __int64 i; // rdx
  _QWORD *v5; // rcx
  __int64 v6; // rdx
  _DWORD *v7; // rax
  PDEVICE_OBJECT v8; // rax
  _QWORD *DeviceExtension; // rbx
  struct _UNICODE_STRING DestinationString; // [rsp+40h] [rbp-28h] BYREF
  struct _UNICODE_STRING SymbolicLinkName; // [rsp+50h] [rbp-18h] BYREF
  NTSTATUS status;
  PDEVICE_OBJECT DeviceObject; // [rsp+70h] [rbp+8h] BYREF

  sub_11F30((char *)("\nNal Windows Driver Loaded -- Compiled %s %s\n"), "Nov 14 2013", "07:22:40");
  v3 = (char *)&byte_5CFEC0;
  dword_17120 = 0;
  for ( i = 256; i != 0; --i )
  {
    v3[264] = 0;
    *(_QWORD *)v3 = 0;
    v3 += 272;
  }
  v5 = &unk_3E7A50;
  v6 = 50000;
  DriverObject->MajorFunction[0] = (PDRIVER_DISPATCH)&sub_11090;
  DriverObject->MajorFunction[2] = (PDRIVER_DISPATCH)&sub_110F0;
  DriverObject->MajorFunction[14] = (PDRIVER_DISPATCH)&sub_11150;
  DriverObject->DriverUnload = (PDRIVER_UNLOAD)sub_11010;
  v7 = &unk_17148;
  do
  {
    *(v7 - 2) = 0;
    *(_QWORD *)v7 = 0;
    *((_QWORD *)v7 + 2) = 0;
    *((_QWORD *)v7 + 1) = 0;
    v7[8] = 0;
    v7[9] = 0;
    *((_QWORD *)v7 + 3) = 0;
    *((_QWORD *)v7 + 5) = 0;
    *((_QWORD *)v7 + 6) = 0;
    *((_QWORD *)v7 + 7) = 0;
    *((_QWORD *)v7 + 8) = 0;
    v5[1] = 0;
    *v5 = 0;
    *(v5 - 2) = 0;
    *(v5 - 1) = 0;
    v5[2] = 0;
    v7 += 20;
    v5 += 5;
    --v6;
  }
  while ( v6 != 0 );
  sub_11F30((char *)("Nal Windows DriverAddDevice: entered\n"));
  RtlInitUnicodeString(&DestinationString, L"\\Device\\Nal");
  if ( (status = IoCreateDevice(DriverObject, 0x18u, &DestinationString, 0x8086u, 0, 0, &DeviceObject)) >= 0 )
  {
    v8 = DeviceObject;
    DriverObject->DeviceObject = DeviceObject;
    DeviceExtension = v8->DeviceExtension;
    *DeviceExtension = v8;
    RtlInitUnicodeString(&SymbolicLinkName, L"\\DosDevices\\Nal");
    if ( (status = IoCreateSymbolicLink(&SymbolicLinkName, &DestinationString)) >= 0 )
    {
      DeviceObject->Flags |= 4u;
      DeviceObject->Flags &= ~0x80u;
      DeviceExtension[1] = DeviceObject;
      goto LABEL_10;
    }
  }
  else
  {
    sub_11F30((char *)("Nal Windows DriverIoCreateDevice failed.  Status = 0x%0x\n"), status);
    status = (NTSTATUS)0xC0000001;
  }
  sub_11F30((char *)("Nal Windows DriverIoCreateSymbolicLink failed.  Status = 0x%x\n"), status);
  IoDeleteDevice(DeviceObject);
LABEL_10:
  sub_11F30((char *)("Nal Windows DriverAddDevice: done\n"));
  sub_11F30((char *)("Nal Windows Driver DriverEntry: Completed\n"));
  return 0;
}



/* Original function: DriverEntry */
NTSTATUS __stdcall DriverEntry(PDRIVER_OBJECT DriverObject, PUNICODE_STRING RegistryPath)
{
  unsigned __int64 v2; // rax

  v2 = BugCheckParameter2;
  if ( BugCheckParameter2 == 0 || BugCheckParameter2 == 0x2B992DDFA232LL )
  {
    v2 = ((unsigned __int64)&BugCheckParameter2 ^ (*(volatile unsigned __int64 *)0xFFFFF78000000320ULL)) & 0xFFFFFFFFFFFFLL;
    if ( v2 == 0 )
      v2 = 0x2B992DDFA232LL;
    BugCheckParameter2 = v2;
  }
  BugCheckParameter3 = ~v2;
  return sub_5E2010((PDRIVER_OBJECT)(DriverObject));
}



/* Original function: nal_check_cookie */
void nal_check_cookie(ULONG_PTR cookie)
{
  if (cookie != BugCheckParameter2 || (cookie >> 48) != 0)
    sub_14270((ULONG_PTR)(cookie));
}

