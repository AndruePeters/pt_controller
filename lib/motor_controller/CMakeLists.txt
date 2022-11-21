add_library(motor_controller "include/motor_controller.hpp" "include/bescor_mp101.hpp")
target_include_directories(motor_controller PUBLIC "include/")
target_link_libraries(motor_controller hal_gpio)