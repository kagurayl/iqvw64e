include_guard(GLOBAL)

# Vendored official NuGet packages; no downloads or external absolute paths.
set(_musa_root "${CMAKE_CURRENT_LIST_DIR}/musa")
# CMake's Windows defaults add kernel32/user32/etc. explicitly even with
# /NODEFAULTLIB. Kernel CRT symbols must resolve through WDK import libraries.
set(CMAKE_C_STANDARD_LIBRARIES "")
set(CMAKE_CXX_STANDARD_LIBRARIES "")
if(NOT MSVC OR NOT CMAKE_SIZEOF_VOID_P EQUAL 8 OR NOT WDK_PLATFORM STREQUAL "x64")
    message(FATAL_ERROR "This Musa.Runtime bundle requires MSVC and an x64 WDK target.")
endif()
if(NOT TARGET Musa.Veil)
    include("${CMAKE_CURRENT_LIST_DIR}/veil.cmake")
endif()

add_library(musa_runtime INTERFACE)
add_library(Musa.Runtime ALIAS musa_runtime)
target_include_directories(musa_runtime SYSTEM INTERFACE
    "${_musa_root}/Musa.Runtime/Include"
    "${_musa_root}/Musa.Core/Include"
    "${_musa_root}/Musa.CoreLite/Include")
target_compile_definitions(musa_runtime INTERFACE
    _NO_CRT_STDIO_INLINE _HAS_EXCEPTIONS=1 _KERNEL_MODE NTOS_KERNEL_RUNTIME)
target_compile_options(musa_runtime INTERFACE
    "$<$<COMPILE_LANGUAGE:CXX>:/EHa;/GR;/Zc:wchar_t;/Zc:threadSafeInit->")
target_link_libraries(musa_runtime INTERFACE Musa.Veil
    "${_musa_root}/Musa.Runtime/Library/$<IF:$<CONFIG:Debug>,Debug,Release>/x64/Musa.Runtime.DriverEntry.obj"
    "${_musa_root}/Musa.Runtime/Library/$<IF:$<CONFIG:Debug>,Debug,Release>/x64/Musa.Runtime.lib"
    "${_musa_root}/Musa.Core/Library/$<IF:$<CONFIG:Debug>,Debug,Release>/x64/Musa.Core.StaticLibraryForDriver.lib"
    "${_musa_root}/Musa.CoreLite/Library/$<IF:$<CONFIG:Debug>,Debug,Release>/x64/Musa.CoreLite.SystemCallForDriver.Stubs.obj"
    "${_musa_root}/Musa.CoreLite/Library/$<IF:$<CONFIG:Debug>,Debug,Release>/x64/Musa.CoreLite.StaticLibraryForDriver.lib"
    WDK::CNG)

# Call after wdk_add_driver() and any project-specific WDK flag overrides.
function(musa_use_runtime target)
    get_target_property(_enabled "${target}" MUSA_RUNTIME_ENABLED)
    if(_enabled)
        return()
    endif()
    if(NOT target MATCHES "^[A-Za-z0-9_]+$")
        message(FATAL_ERROR "Musa driver names must contain only letters, digits and underscores.")
    endif()
    get_target_property(_options "${target}" COMPILE_OPTIONS)
    string(REPLACE "/kernel" "" _options "${_options}")
    string(REPLACE "/GR-" "" _options "${_options}")
    set_property(TARGET "${target}" PROPERTY COMPILE_OPTIONS "${_options}")
    set_target_properties("${target}" PROPERTIES
        MUSA_RUNTIME_ENABLED TRUE
        MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>"
        CXX_STANDARD 20 CXX_STANDARD_REQUIRED YES CXX_EXTENSIONS NO)

    # STL must see the full MSVC/UCRT headers before WDK's reduced km/crt headers.
    get_filename_component(_compiler_dir "${CMAKE_CXX_COMPILER}" DIRECTORY)
    get_filename_component(_msvc_root "${_compiler_dir}/../../.." ABSOLUTE)
    target_include_directories("${target}" BEFORE PRIVATE
        "${_msvc_root}/include" "${WDK_ROOT}/Include/${WDK_INC_VERSION}/ucrt")

    # The bootstrap creates a real driver object before Musa initializes its CRT.
    # GsDriverEntry still performs the normal security-cookie initialization.
    get_target_property(_link_flags "${target}" LINK_FLAGS)
    string(REGEX REPLACE "/ENTRY:[^ ]+" "" _link_flags "${_link_flags}")
    set_property(TARGET "${target}" PROPERTY LINK_FLAGS "${_link_flags}")
    target_link_options("${target}" PRIVATE /ENTRY:MusaBootstrapEntry /INTEGRITYCHECK)
    target_sources("${target}" PRIVATE "${CMAKE_CURRENT_FUNCTION_LIST_DIR}/musa/bootstrap.cpp")
    set_source_files_properties("${CMAKE_CURRENT_FUNCTION_LIST_DIR}/musa/bootstrap.cpp"
        PROPERTIES COMPILE_OPTIONS /GS-)
    target_compile_definitions("${target}" PRIVATE "MUSA_DRIVER_NAME=L\"${target}\"")
    # FindWDK uses the legacy link signature; append without mixing signatures.
    set_property(TARGET "${target}" APPEND PROPERTY LINK_LIBRARIES Musa.Runtime)
endfunction()
