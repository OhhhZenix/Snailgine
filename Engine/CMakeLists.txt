# Setups Engine
project(Snailgine-Engine)
message(STATUS "Setting up the Engine")

### Options ###
set(SN_ENABLE_PROFILE ON CACHE BOOL "Enable or disable the profiling" FORCE)

### Target ###
set(TARGET_NAME Snailgine)
add_library(
	${TARGET_NAME}
	"src/Core/Application.cpp"
    "src/Core/Log.cpp"
)

### Target Include Directories ###
target_include_directories(${TARGET_NAME} PUBLIC "include")

### Precompiled Header ###
target_precompile_headers(${TARGET_NAME} PRIVATE "include/Snailgine/PCH.hpp")

### Linking Library ###
# spdlog
add_subdirectory("extern/spdlog")
target_link_libraries(${TARGET_NAME} PUBLIC "spdlog")

# bgfx
add_subdirectory("extern/bgfx.cmake")
target_link_libraries(${TARGET_NAME} PRIVATE "bgfx")

### Definitions ###
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