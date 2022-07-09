add_library(hal_gpio "src/gpio.cpp")
target_include_directories(hal_gpio PUBLIC "include/")
target_link_libraries(hal_gpio PUBLIC idf::driver containers)

add_library(hal_pwm "src/pwm.cpp")
target_include_directories(hal_pwm PUBLIC "include/")
target_link_libraries(hal_pwm PUBLIC idf::driver containers)
