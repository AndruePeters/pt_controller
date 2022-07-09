add_library(motor_controller INTERFACE)
target_sources(motor_controller INTERFACE "include/motor_controller.hpp" "include/bescor_mp101.hpp")
target_include_directories(motor_controller INTERFACE "include/")
target_link_libraries(motor_controller INTERFACE hal_gpio idf::driver)