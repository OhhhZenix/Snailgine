cmake_minimum_required(VERSION 3.17)

# Add our cmake module path to the existing cmake module path
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_SOURCE_DIR}/cmake)

# Project
project(Snailgine)

# Standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Engine
add_subdirectory(Engine)

# Editor
# add_subdirectory(Editor)