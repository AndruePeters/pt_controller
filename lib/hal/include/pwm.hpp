#pragma once

#include <driver/ledc.h>

namespace hal {

class Pwm {
    gpio_num_t gpio_;
    ledc_channel_config_t channelConfig;
    ledc_timer_config_t timerConfig;

public:
    Pwm();
    void start();
    void stop();
    void pause();

    /// need some stuff to set parameters for the two different configs
};



}