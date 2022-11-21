# Andrue Peters
# 5/5/2022

cmake_minimum_required(VERSION 3.24)

project(pt_controller CXX C ASM)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

SET(CMAKE_CXX_STANDARD 20)
#set(CONFIG_ESP32_WIFI_ENABLED ON)
# SET(CMAKE_CXX_EXTENSIONS OFF)

# Include ESP-IDF build system functions
set(targets "esp32" "esp32s2" "esp32s3" "esp32c3" "esp32h2" "esp32c2")
set(EXTRA_COMPONENT_DIRS "$ENV{IDF_PATH}/examples/cxx/experimental/experimental_cpp_component")
include($ENV{IDF_PATH}/tools/cmake/idf.cmake)
if("${TARGET}" IN_LIST targets)
    # Include for ESP-IDF build system functions
    #    include($ENV{IDF_PATH}/tools/cmake/idf.cmake)
    # Create idf::{target} and idf::freertos static libraries

idf_build_process("${TARGET}"
        COMPONENTS freertos esp_wifi esptool_py driver esp_event esp_http_server nvs_flash
        SDKCONFIG ${CMAKE_CURRENT_LIST_DIR}/sdkconfig
        BUILD_DIR ${CMAKE_BINARY_DIR})
else()
    message(WARNING "Unknown target ${TARGET}, creating stubs for esp32 instead")
endif()

# Link the static libraries to the executable
add_executable(dummy.elf dummy.cpp)
if("${TARGET}" IN_LIST targets)
    target_link_libraries(dummy.elf idf::freertos idf::spi_flash)
    # Attach additional targets to the executable file for flashing,
    # linker script generation, partition_table generation, etc.
    idf_build_executable(dummy.elf)
else()
    target_link_libraries(dummy.elf stub::esp32 stub::freertos stub::spi_flash)
endif()

add_subdirectory(app)
add_subdirectory(lib)