#include <Veil.h>

extern "C" NTSTATUS NTAPI GsDriverEntry(PDRIVER_OBJECT, PUNICODE_STRING);

// No CRT, STL or dynamically initialized objects may be used before GsDriverEntry.
// This translation unit uses /GS- because the cookie has not been initialized yet.
extern "C" NTSTATUS NTAPI MusaBootstrapEntry(PDRIVER_OBJECT driver, PUNICODE_STRING registryPath)
{
    if (driver)
        return GsDriverEntry(driver, registryPath);

    UNICODE_STRING name;
    RtlInitUnicodeString(&name, L"\\Driver\\" MUSA_DRIVER_NAME);
    return IoCreateDriver(&name, &GsDriverEntry);
}
