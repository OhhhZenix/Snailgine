# Setups Engine
project(Snailgine-Engine)
message("Setting up the Engine")

# Finding glfw3
find_package(glfw3 REQUIRED)

# Target
set(TARGET_NAME Snailgine)
file(GLOB_RECURSE SRCS "src/*.cpp" "src/*.hpp")
add_library(${TARGET_NAME} ${SRCS})
target_include_directories(${TARGET_NAME} PUBLIC src)

# Linking glfw3
target_link_libraries(${TARGET_NAME} PRIVATE glfw)