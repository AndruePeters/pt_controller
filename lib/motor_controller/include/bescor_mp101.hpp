#pragma once

#include <motor_controller.hpp>
#include <gpio.hpp>

/// The Bescor has a really simple hardware interface
/// When \p upPin is high, the motor tilts up
/// When \p downPin is high, the motor tilts down
/// When \p leftPin is high, the motor pans left
/// When \p rightPin is high, the motor pans right
/// \p speedPin is implemented with a variable resistor on the official remote,
///         but pwm is sufficient
struct BescorMp101Config {
    gpio::Gpio upPin;
    gpio::Gpio downPin;
    gpio::Gpio leftPin;
    gpio::Gpio rightPin;
    gpio::Gpio speedPin;    
};


class BescorMp101Controller : public MotorController<BescorMp101Controller> 
{
    BescorMp101Config config;

    BescorMp101Controller(BescorMp101Config&& config): config(std::move(config))
    {

    }

    void panLeftImpl()
    {
        
    }

    void panRightImpl()
    {

    }

    void tiltUpImpl()
    {

    }

    void titlDownImpl()
    {

    }

    void setSpeedImpl()
    {

    }
};

