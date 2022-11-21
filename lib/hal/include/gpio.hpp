#pragma once

#include <driver/gpio.h>

namespace hal
{


namespace gpio {
    enum struct Mode {
        disable,
        input,
        output,
        output_open_drain,
        input_output_only_drain,
        input_output
    };

    enum struct Pullup { disable, enable };

    enum struct Pulldown { enable, disable };

    enum struct PullMode { pullup, pulldown, pullup_pulldown, floating };

    enum struct DriverCap { weak, stronger, medium, strongest }; // deafult = medium

    enum struct InterruptType { disable, posedge, negedge, anyedge, low_level, high_level };
}

/// Goals to add active high/ active low capability without any runtime overhead
class Gpio
{
    gpio_num_t gpio_;
    uint8_t state = 0;

public:
    explicit Gpio(gpio_num_t gpio_);
    Gpio(gpio_num_t gpio_, gpio::Mode mode);

    /// Configuration based methods
    void set_mode(gpio::Mode mode);
    void set_pullup(gpio::Pullup pullup);
    void set_pulldown(gpio::Pulldown pulldown);
    void set_pull_mode(gpio::PullMode mode);
    void set_driver_cap(gpio::DriverCap DriverCap);
    void set_interrupt_type(gpio::InterruptType interruptType);

    void set_high();
    void set_low();
    void toggle();
};

}