#pragma once

#include <array>

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
    hal::Gpio upPin;
    hal::Gpio downPin;
    hal::Gpio leftPin;
    hal::Gpio rightPin;
    hal::Gpio speedPin;    
};


class BescorMp101Controller : public MotorController<BescorMp101Controller> 
{
    BescorMp101Config config;

    BescorMp101Controller(BescorMp101Config&& config): config(std::move(config))
    {
        config.upPin.set_mode(hal::gpio::Mode::output);
        config.downPin.set_mode(hal::gpio::Mode::output);
        config.leftPin.set_mode(hal::gpio::Mode::output);
        config.rightPin.set_mode(hal::gpio::Mode::output);
        config.speedPin.set_mode(hal::gpio::Mode::output);
    }

    void panLeftStartImpl()
    {
        config.leftPin.set_high();
    }

    void panLeftStopImpl()
    {
        config.leftPin.set_low();
    }

    void panRightStartImpl()
    {
        config.rightPin.set_high();
    }

    void panRightStopImpl()
    {
        config.rightPin.set_low();
    }

    void tiltUpStartImpl()
    {
        config.upPin.set_high();
    }

    void tiltUpStopImpl()
    {
        config.upPin.set_low();
    }

    void titlDownStartImpl()
    {
        config.downPin.set_high();
    }

    void titlDownStopImpl()
    {
        config.downPin.set_low();
    }


    void setSpeedImpl(int speed)
    {

    }
};

