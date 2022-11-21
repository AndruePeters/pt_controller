add_library(wifi "src/wifi.cpp")
target_include_directories(wifi PUBLIC include/)
target_link_libraries(wifi PRIVATE idf::esp_wifi idf::nvs_flash)
