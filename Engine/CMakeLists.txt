# Setups Engine
project(Snailgine-Engine)
message(STATUS "Setting up the Engine")

# Finding OpenGL
find_package(OpenGL REQUIRED)

# Finding glfw3
find_package(glfw3 REQUIRED)

# Finding glad
find_package(glad REQUIRED)

# Target
set(TARGET_NAME Snailgine)
file(GLOB_RECURSE SRCS "src/*.cpp" "src/*.hpp")
add_library(${TARGET_NAME} ${SRCS})

# Includes the project include path
target_include_directories(${TARGET_NAME} PUBLIC src)

# Creates precompiled header
target_precompile_headers(${TARGET_NAME} PRIVATE src/Snailgine/PCH.hpp)

# Linking OpenGL
target_link_libraries(${TARGET_NAME} PRIVATE OpenGL::GL)

# Linking glfw3
target_link_libraries(${TARGET_NAME} PRIVATE glfw)

# Linking glad
target_link_libraries(${TARGET_NAME} PRIVATE glad::glad)

# Custom definitions
target_compile_definitions(${TARGET_NAME} PRIVATE "GLFW_INCLUDE_NONE")