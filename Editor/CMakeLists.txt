# Setups Editor
project(Snailgine-Editor)
message(STATUS "Setting up the Editor")

# Target
set(TARGET_NAME Snailgine-Editor)
file(GLOB_RECURSE SRCS "src/*.cpp" "src/*.hpp")
add_executable(${TARGET_NAME} ${SRCS})
target_include_directories(${TARGET_NAME} PUBLIC src)

# Visual Studio Related
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${TARGET_NAME})

# Linking Snailgine
target_link_libraries(${TARGET_NAME} PRIVATE Snailgine)