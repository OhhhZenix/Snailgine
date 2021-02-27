cmake_minimum_required(VERSION 3.16)

# Sets up vcpkg
set(CMAKE_TOOLCHAIN_FILE "${CMAKE_CURRENT_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake" CACHE PATH "Path to vcpkg toolchain")

# Project
project(Snailgine)

# Standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Engine
add_subdirectory(Engine)

# Editor
add_subdirectory(Editor)