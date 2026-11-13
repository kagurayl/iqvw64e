cmake_minimum_required(VERSION 3.25)
project(iqvw64e LANGUAGES C)

if(NOT MSVC OR NOT CMAKE_SIZEOF_VOID_P EQUAL 8)
    message(FATAL_ERROR "iqvw64e requires MSVC targeting Windows x64.")
endif()
if(CMAKE_GENERATOR_PLATFORM MATCHES "ARM")
    message(FATAL_ERROR "iqvw64e requires x64, not ARM64.")
endif()
if(NOT CMAKE_CONFIGURATION_TYPES AND NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release CACHE STRING "Build configuration" FORCE)
endif()

list(PREPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/dev/cmake")
find_package(WDK REQUIRED)

wdk_add_driver(iqvw64e
    WINVER 0x0601
    NTDDI_VERSION 0x06010000
    src/nal_recovered.c
    src/nal_data.c
    src/nal_compat.h
    src/nal_globals.h
)
set_target_properties(iqvw64e PROPERTIES
    C_STANDARD 17
    C_STANDARD_REQUIRED YES
    MSVC_RUNTIME_LIBRARY MultiThreaded
)
target_include_directories(iqvw64e PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/src")
target_compile_options(iqvw64e PRIVATE /GS- /Ob0 "$<$<NOT:$<CONFIG:Debug>>:/O2>")

# FindWDK defaults to the CRT GS wrapper. The recovered DriverEntry already
# performs the original cookie initialization; keep its actual entry point.
get_target_property(_wdk_link_flags iqvw64e LINK_FLAGS)
string(REPLACE "/ENTRY:GsDriverEntry" "/ENTRY:DriverEntry" _wdk_link_flags "${_wdk_link_flags}")
set_property(TARGET iqvw64e PROPERTY LINK_FLAGS "${_wdk_link_flags}")
target_link_options(iqvw64e PRIVATE
    "/MAP:$<TARGET_FILE_DIR:iqvw64e>/iqvw64e.map"
)

# The initialized prefix and BSS tail must retain all original table aliases.
add_custom_command(TARGET iqvw64e POST_BUILD
    COMMAND "${CMAKE_COMMAND}"
        "-DMAP_FILE=$<TARGET_FILE_DIR:iqvw64e>/iqvw64e.map"
        "-DDRIVER_FILE=$<TARGET_FILE:iqvw64e>"
        -P "${CMAKE_CURRENT_SOURCE_DIR}/dev/cmake/VerifyNalLayout.cmake"
    VERBATIM
)
