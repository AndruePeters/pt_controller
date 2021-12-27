# Andrue Peters
# 12/23/2021

cmake_minimum_required(VERSION 3.15)

project(pt_controller  CXX C)
set(CMAKE_EXPORT_COMPILE_COMMANDS 1)

# Include for ESP-IDF build system functions
include($ENV{IDF_PATH}/tools/cmake/idf.cmake)

include (cmake/Cache.cmake)
# build the main apps that will be programmed onto the esp
add_subdirectory(app)
#add_subdirectory(external)
