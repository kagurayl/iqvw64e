include_guard(GLOBAL)

# Musa's pinned Veil dependency is bundled so copying dev/ also works offline.
if(EXISTS "${CMAKE_CURRENT_LIST_DIR}/musa/Musa.Veil/include/Veil.h")
    add_library(Musa.Veil INTERFACE)
    target_include_directories(Musa.Veil INTERFACE
        "${CMAKE_CURRENT_LIST_DIR}/musa/Musa.Veil/include")
    return()
endif()

include(FetchContent)

# Musa.Veil is a header-only collection of Windows Native API declarations.
FetchContent_Declare(
    veil
    URL https://github.com/MiroKaku/Musa.Veil/archive/491b3ebb86b615fff551763c1a32f57c48d4fbb5.zip
    URL_HASH SHA256=8b87eb3eda03d37b0550d75b50c8ebed41e55ec2bc5afdc8136d3718a87ae4d9
    DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)
FetchContent_MakeAvailable(veil)

add_library(Musa.Veil INTERFACE)
target_include_directories(Musa.Veil INTERFACE "${veil_SOURCE_DIR}")
