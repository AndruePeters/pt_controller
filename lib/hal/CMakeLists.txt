add_library(hal_gpio src/gpio.cpp)
target_include_directories(hal_gpio PUBLIC include/)
target_link_libraries(hal_gpio PRIVATE idf::driver containers)
