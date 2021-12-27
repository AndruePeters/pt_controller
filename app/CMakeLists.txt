message("BINARY_DIR: ${CMAKE_BINARY_DIR}")


#if(CMAKE_CROSSCOMPILING)
    # Start the build process
    # For some currently unknown reason, this function must be with add_executable()
    # Not sure why it isn't handled by idf_build_executable
    idf_build_process(esp32
            # try and trim the build; additional components
            # will be included as needed based on dependency tree
            #
            # although esptool_py does not generate static library,
            # processing the component is needed for flashing related
            # targets and file generation
            COMPONENTS esp32 freertos esptool_py spi_flash nvs_flash mbedtls esp-tls esp_http_server
            SDKCONFIG ${CMAKE_CURRENT_LIST_DIR}/sdkconfig
            BUILD_DIR "${CMAKE_BINARY_DIR}")

    message("BINARY_DIR: ${CMAKE_BINARY_DIR}")
    set(elf_file ${CMAKE_PROJECT_NAME}.elf)
    add_executable(${elf_file} controller.cpp connect.c  asprintf.h)
    target_link_libraries(${elf_file} PUBLIC idf::esp32 idf::freertos idf::spi_flash idf::nvs_flash idf::mbedtls idf::esp-tls idf::esp_http_server)
    target_compile_options(${elf_file} PUBLIC -mlongcalls)
    # Attach additional targets to the executable file for flashing,
    # linker script generation, partition_table generation, etc.
    idf_build_executable(${elf_file})

    # Copy the new elf file and config.env to the ${CMAKE_BINARY_DIR} for some scripts
    add_custom_command(TARGET ${elf_file} POST_BUILD COMMAND cp ${elf_file}  ${CMAKE_BINARY_DIR}/${elf_file} )
    add_custom_command(TARGET ${elf_file} POST_BUILD COMMAND cp config.env  ${CMAKE_BINARY_DIR}/config.env )
#endif()