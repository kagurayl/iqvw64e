Musa.Runtime CMake integration (MSVC x64)
=======================================

Copy the complete dev/ directory into another project. All Musa binaries and
headers are included locally; configuring does not need NuGet or network access.
An installed matching MSVC toolchain and Windows SDK/WDK are still required.

CMakeLists.txt:

  list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/dev/cmake")
  find_package(WDK REQUIRED)
  include(musa_runtime)
  wdk_add_driver(MyDriver src/main.cpp)
  musa_use_runtime(MyDriver)

Call musa_use_runtime AFTER setting any custom WDK compile options.
It links Musa.Runtime (including DriverEntry.obj), Musa.Core, Musa.CoreLite
(including its syscall stubs), Veil and the WDK CNG library. Debug selects Debug
binaries; Release/RelWithDebInfo/MinSizeRel select Release binaries.
It selects C++20, static CRT conventions, /EHa, RTTI, and full MSVC/UCRT headers;
removes incompatible /kernel and /GR- target flags; disables thread-safe local
static initialization, and configures the driver bootstrap entry.
Do not add the regular user-mode CRT libraries or override the entry afterward.
Disable /RTC flags in project/global Debug options (this project already does).

Application entry:

  extern "C" NTSTATUS NTAPI DriverMain(PDRIVER_OBJECT driver,
                                      PUNICODE_STRING registryPath);

Do not define DriverEntry: the linked Musa object supplies it and initializes
the CRT before calling DriverMain. Musa wraps DriverUnload for CRT teardown.

Mapped loading:
  Call the PE AddressOfEntryPoint, which is MusaBootstrapEntry. If DriverObject
  is null it calls IoCreateDriver("\\Driver\\<CMake-target-name>", GsDriverEntry).
  With a valid DriverObject it calls GsDriverEntry directly. Thus GS/CRT startup
  runs once, with a real driver object. Do not call DriverMain directly.
  The mapper must still perform normal image mapping/import/relocation duties.

STL example (after CRT startup):
  #include <Veil.h>
  #include <vector>
  #include <kallocator.h>
  std::vector<int, std::kallocator<int, NonPagedPoolNx>> values;

Paged/nonpaged allocations, IRQL, exception restrictions and synchronization
still apply. Nonpaged storage does not make all STL operations valid at any IRQL.

Pinned official NuGet packages:
  Musa.Runtime 1451.28000.0 (MSVC 14.51.36231 / UCRT 10.0.28000.0)
  Musa.Core 0.7.0
  Musa.CoreLite 1.2.2
  Musa.Veil 1.10.0

Only x64 kernel libraries are bundled. Package origins, hashes and per-file
hashes are in manifest.json; original nuspec/config/license files are retained.
YY.NuGet.Import.Helper is MSBuild-only and is not required by this CMake adapter.

Upstream:
  https://github.com/MiroKaku/Musa.Runtime
  https://github.com/MiroKaku/Musa.Core
  https://github.com/MiroKaku/Musa.CoreLite
  https://github.com/MiroKaku/Musa.Veil

Integration was inspected/configured without compiling or loading the driver.
