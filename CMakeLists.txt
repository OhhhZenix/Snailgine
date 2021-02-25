cmake_minimum_required(VERSION 3.16)

# Sets up vcpkg
include(cmake/VcpkgToolchain.cmake)

# Project
project(Snailgine)

# Standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Engine
add_subdirectory(Engine)

# Editor
add_subdirectory(Editor)