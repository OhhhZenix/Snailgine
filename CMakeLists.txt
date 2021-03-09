cmake_minimum_required(VERSION 3.16)
project(Snailgine)

# Standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Extern
add_subdirectory(extern)

# Engine
add_subdirectory(Engine)

# Editor
add_subdirectory(Editor)