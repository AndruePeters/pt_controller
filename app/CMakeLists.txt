include($ENV{IDF_PATH}/tools/cmake/idf.cmake)
set(elf_file ${CMAKE_PROJECT_NAME}.elf)
add_executable(${elf_file} main.cpp dns_server.c portal.c)
target_add_binary_data(${elf_file} "root.html" BINARY)

# Link the static libraries to the executable
# if("${TARGET}" IN_LIST targets)
    target_link_libraries(${elf_file} PUBLIC idf::freertos idf::spi_flash idf::driver idf::esp_http_server idf::esp_event idf::nvs_flash idf::esp_wifi
         hal_gpio wifi motor_controller)
    # Attach additional targets to the executable file for flashing,
    # linker script generation, partition_table generation, etc.
    idf_build_executable(${elf_file})
# else()
    # target_link_libraries(${elf_file} stub::esp32 stub::freertos stub::spi_flash)
# endif()

