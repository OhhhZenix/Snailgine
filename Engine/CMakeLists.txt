# Setups Engine
project(Snailgine-Engine)
message(STATUS "Setting up the Engine")

# Options
option(SN_ENABLE_PROFILE "Enable or disable the profiling" ON)

# Finding spdlog
find_package(spdlog REQUIRED)

# Finding OpenGL
find_package(OpenGL REQUIRED)

# Finding glfw3
find_package(glfw3 REQUIRED)

# Finding glad
find_package(glad REQUIRED)

# Finding glm
find_package(glm REQUIRED)

# Target
set(TARGET_NAME Snailgine)
file(GLOB_RECURSE SRCS "src/*.cpp" "src/*.hpp")
add_library(${TARGET_NAME} ${SRCS})

# Includes the project include path
target_include_directories(${TARGET_NAME} PUBLIC src)

# Creates precompiled header
target_precompile_headers(${TARGET_NAME} PRIVATE src/Snailgine/PCH.hpp)

# Linking spdlog
target_link_libraries(${TARGET_NAME} PRIVATE spdlog::spdlog spdlog::spdlog_header_only)

# Linking OpenGL
target_link_libraries(${TARGET_NAME} PRIVATE OpenGL::GL)

# Linking glfw3
target_link_libraries(${TARGET_NAME} PRIVATE glfw)

# Linking glad
target_link_libraries(${TARGET_NAME} PRIVATE glad::glad)

# Linking glm
target_link_libraries(${TARGET_NAME} PUBLIC glm)

# Custom definitions
target_compile_definitions(${TARGET_NAME} PRIVATE "GLFW_INCLUDE_NONE")

if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    target_compile_definitions(${TARGET_NAME} PRIVATE "SN_BUILD_DEBUG=1")
else ()
    target_compile_definitions(${TARGET_NAME} PRIVATE "SN_BUILD_DEBUG=0")
endif ()

if (CMAKE_BUILD_TYPE STREQUAL "Release")
    target_compile_definitions(${TARGET_NAME} PRIVATE "SN_BUILD_RELEASE=1")
else ()
    target_compile_definitions(${TARGET_NAME} PRIVATE "SN_BUILD_RELEASE=0")
endif ()

if (SN_ENABLE_PROFILE EQUAL ON)
    target_compile_definitions(${TARGET_NAME} PRIVATE "SN_PROFILE=1")
else ()
    target_compile_definitions(${TARGET_NAME} PRIVATE "SN_PROFILE=0")
endif ()