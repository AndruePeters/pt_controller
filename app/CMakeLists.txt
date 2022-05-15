cmake_minimum_required(VERSION 3.15)

set(targets "esp32" "esp32s2" "esp32s3" "esp32c3" "esp32h2" "esp32c2")
set(EXTRA_COMPONENT_DIRS "$ENV{IDF_PATH}/examples/cxx/experimental/experimental_cpp_component")
# if("${TARGET}" IN_LIST targets)
    # Include for ESP-IDF build system functions
    include($ENV{IDF_PATH}/tools/cmake/idf.cmake)
    # Create idf::{target} and idf::freertos static libraries
    idf_build_process("${TARGET}"
                    # try and trim the build; additional components
                    # will be included as needed based on dependency tree
                    #
                    # although esptool_py does not generate static library,
                    # processing the component is needed for flashing related
                    # targets and file generation
                    COMPONENTS "${TARGET}" freertos esptool_py driver
                    SDKCONFIG ${CMAKE_CURRENT_LIST_DIR}/sdkconfig
                    BUILD_DIR ${CMAKE_BINARY_DIR})
# else()
    # message(WARNING "Unknown target ${TARGET}, creating stubs for esp32 instead")
# endif()


set(elf_file ${CMAKE_PROJECT_NAME}.elf)
add_executable(${elf_file} main.cpp)

# Link the static libraries to the executable
# if("${TARGET}" IN_LIST targets)
    target_link_libraries(${elf_file} "idf::${TARGET}" idf::freertos idf::spi_flash idf::driver hal_gpio)
    # Attach additional targets to the executable file for flashing,
    # linker script generation, partition_table generation, etc.
    idf_build_executable(${elf_file})
# else()
    # target_link_libraries(${elf_file} stub::esp32 stub::freertos stub::spi_flash)
# endif()
