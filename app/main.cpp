#include <cstdlib>
#include <thread>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "esp_log.h"

#include <gpio.hpp>

static const char* TAG = "PtController";

extern "C" void app_main(void)
{
    /// Create a GPIO object
    hal::Gpio led (GPIO_NUM_2, hal::gpio::Mode::output);

    while (1) {
        led.toggle();
        vTaskDelay(500);
    }
}