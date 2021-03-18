# Setups Engine
project(Snailgine-Engine)
message(STATUS "Setting up the Engine")

### Options ###
set(SN_ENABLE_PROFILE ON CACHE BOOL "Enable or disable the profiling" FORCE)

### Target ###
set(TARGET_NAME Snailgine)
file(GLOB_RECURSE SRCS "src/*.cpp" "include/*.hpp")
add_library(${TARGET_NAME} ${SRCS})

### Target Include Directories ###
target_include_directories(${TARGET_NAME} PUBLIC "include")

### Precompiled Header ###
target_precompile_headers(${TARGET_NAME} PRIVATE "include/Snailgine/PCH.hpp")

### Linking Library ###
get_filename_component(PARENT_DIR "${CMAKE_CURRENT_SOURCE_DIR}/.." ABSOLUTE)
set(EXTERN_PATH "${PARENT_DIR}/extern")

# spdlog
target_link_libraries(${TARGET_NAME} PUBLIC "spdlog")

# bgfx
target_link_libraries(${TARGET_NAME} PRIVATE "bgfx")

# glfw
target_link_libraries(${TARGET_NAME} PRIVATE "glfw")

### Definitions ###
target_compile_definitions(${TARGET_NAME} PRIVATE "GLFW_INCLUDE_NONE")

if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    target_compile_definitions(${TARGET_NAME} PUBLIC "SN_BUILD_DEBUG=1")
else ()
    target_compile_definitions(${TARGET_NAME} PUBLIC "SN_BUILD_DEBUG=0")
endif ()

if (CMAKE_BUILD_TYPE STREQUAL "Release")
    target_compile_definitions(${TARGET_NAME} PUBLIC "SN_BUILD_RELEASE=1")
else ()
    target_compile_definitions(${TARGET_NAME} PUBLIC "SN_BUILD_RELEASE=0")
endif ()

if (WIN32)
    target_compile_definitions(${TARGET_NAME} PUBLIC "SN_PLATFORM_WINDOW=1")
else ()
    target_compile_definitions(${TARGET_NAME} PUBLIC "SN_PLATFORM_WINDOW=0")
endif ()

if (SN_ENABLE_PROFILE EQUAL ON)
    target_compile_definitions(${TARGET_NAME} PUBLIC "SN_PROFILE=1")
else ()
    target_compile_definitions(${TARGET_NAME} PUBLIC "SN_PROFILE=0")
endif ()

# glfw
if (WIN32)
    target_compile_definitions(${TARGET_NAME} PRIVATE "GLFW_EXPOSE_NATIVE_WIN32")
elseif(APPLE)
    target_compile_definitions(${TARGET_NAME} PRIVATE "GLFW_EXPOSE_NATIVE_COCOA")
elseif(UNIX AND NOT APPLE)
    target_compile_definitions(${TARGET_NAME} PRIVATE "GLFW_EXPOSE_NATIVE_X11")
endif ()