# Andrue Peters
# 5/5/2022

cmake_minimum_required(VERSION 3.15)

project(pt_controller CXX C)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)


# Include ESP-IDF build system functions
include ($ENV{IDF_PATH}/tools/cmake/idf.cmake)

add_subdirectory(app)