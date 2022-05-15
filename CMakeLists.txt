# Andrue Peters
# 5/5/2022

cmake_minimum_required(VERSION 3.15)

project(pt_controller CXX C)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

SET(CMAKE_CXX_STANDARD 20)
SET(CMAKE_CXX_EXTENSIONS OFF)

# Include ESP-IDF build system functions
include ($ENV{IDF_PATH}/tools/cmake/idf.cmake)

add_subdirectory(app)
add_subdirectory(lib)