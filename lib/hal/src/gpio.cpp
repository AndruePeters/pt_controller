#include <algorithm>
#include <array>
#include <string_view>

#include <gpio.hpp>
#include <constexpr_map.hpp>

namespace hal {
namespace gpio::utility {

/// Add unit tests for these
constexpr gpio_int_type_t translate(InterruptType it)
{
    using MapPair = std::pair<InterruptType,gpio_int_type_t>;
    constexpr std::array<MapPair, 6> intTypeArr  {
        {{InterruptType::disable, GPIO_INTR_DISABLE},
        {InterruptType::posedge, GPIO_INTR_POSEDGE},
        {InterruptType::negedge, GPIO_INTR_NEGEDGE},
        {InterruptType::anyedge, GPIO_INTR_ANYEDGE},
        {InterruptType::low_level, GPIO_INTR_LOW_LEVEL},
        {InterruptType::high_level, GPIO_INTR_HIGH_LEVEL}}
    };

    const auto map = containers::ConstexprMap<MapPair::first_type, MapPair::second_type, intTypeArr.size()> {{intTypeArr}};
    return map.at(it);
}

constexpr gpio_mode_t translate(Mode mode)
{
    using MapPair = std::pair<Mode, gpio_mode_t>;
    constexpr std::array<MapPair, 6> modeArr {{
        {Mode::disable, GPIO_MODE_DISABLE},
        {Mode::input, GPIO_MODE_INPUT},
        {Mode::output, GPIO_MODE_OUTPUT},
        {Mode::output_open_drain, GPIO_MODE_OUTPUT_OD},
        {Mode::input_output_only_drain, GPIO_MODE_INPUT_OUTPUT_OD},
        {Mode::input_output, GPIO_MODE_INPUT_OUTPUT}
    }};

    const auto map = containers::ConstexprMap<MapPair::first_type, MapPair::second_type, modeArr.size()> {{modeArr}};
    return map.at(mode);
}

constexpr gpio_pullup_t translate(Pullup pullup)
{
    using MapPair = std::pair<Pullup, gpio_pullup_t>;
    constexpr std::array<MapPair, 2> pullupArr {{
        {Pullup::disable, GPIO_PULLUP_DISABLE},
        {Pullup::enable, GPIO_PULLUP_ENABLE}
    }};

    const auto map = containers::ConstexprMap<MapPair::first_type, MapPair::second_type, pullupArr.size()> {{pullupArr}};
    return map.at(pullup);
}

constexpr gpio_pulldown_t translate(Pulldown pulldown)
{
    using MapPair = std::pair<Pulldown, gpio_pulldown_t>;
    constexpr std::array<MapPair, 2> pulldownArr {{
        {Pulldown::disable, GPIO_PULLDOWN_DISABLE},
        {Pulldown::enable, GPIO_PULLDOWN_ENABLE}
    }};

    const auto map = containers::ConstexprMap<MapPair::first_type, MapPair::second_type, pulldownArr.size()> {{pulldownArr}};
    return map.at(pulldown);
}

constexpr gpio_pull_mode_t translate(PullMode mode)
{
    using MapPair = std::pair<PullMode, gpio_pull_mode_t>;
    constexpr std::array<MapPair, 4> modeArr {{
        {PullMode::pullup, GPIO_PULLUP_ONLY},
        {PullMode::pulldown, GPIO_PULLDOWN_ONLY},
        {PullMode::pullup_pulldown, GPIO_PULLUP_PULLDOWN},
        {PullMode::floating, GPIO_FLOATING}
    }};

    const auto map = containers::ConstexprMap<MapPair::first_type, MapPair::second_type, modeArr.size()> {{modeArr}};
    return map.at(mode);
}

constexpr gpio_drive_cap_t translate(DriverCap driverCap)
{
    using MapPair = std::pair<DriverCap, gpio_drive_cap_t>;
    constexpr std::array<MapPair, 4> drivercapArr {{
        {DriverCap::weak, GPIO_DRIVE_CAP_0},
        {DriverCap::stronger, GPIO_DRIVE_CAP_1},
        {DriverCap::medium, GPIO_DRIVE_CAP_2},
        {DriverCap::strongest, GPIO_DRIVE_CAP_3}
    }};

    const auto map = containers::ConstexprMap<MapPair::first_type, MapPair::second_type, drivercapArr.size()> {{drivercapArr}};
    return map.at(driverCap);
}

} /// gpio::utility




Gpio::Gpio(gpio_num_t gpio_): gpio_(gpio_)
{
    gpio_reset_pin(gpio_);
}

Gpio::Gpio(gpio_num_t gpio_, gpio::Mode mode): gpio_(gpio_)
{
    gpio_reset_pin(gpio_);
    set_mode(mode);
}

/// Configuration based methods
void Gpio::set_mode(gpio::Mode mode)
{
    auto mode_t = gpio::utility::translate(mode);
    gpio_set_direction(gpio_, mode_t);
}

void Gpio::set_pullup(gpio::Pullup pullup)
{
   if (pullup == gpio::Pullup::enable) {
       gpio_pullup_en(gpio_);
   } else {
       gpio_pullup_dis(gpio_);
   }
    
}

void Gpio::set_pulldown(gpio::Pulldown pulldown)
{
    if (pulldown == gpio::Pulldown::enable) {
        gpio_pulldown_en(gpio_);
    } else {
        gpio_pulldown_dis(gpio_);
    }
}

void Gpio::set_pull_mode(gpio::PullMode mode)
{
    auto pull_mode_t = gpio::utility::translate(mode);
    gpio_set_pull_mode(gpio_, pull_mode_t);
}

void Gpio::set_driver_cap(gpio::DriverCap driverCap)
{
    auto driver_cap_t = gpio::utility::translate(driverCap);
    gpio_set_drive_capability(gpio_, driver_cap_t);
}

void Gpio::set_interrupt_type(gpio::InterruptType interruptType)
{
    auto intr_type_t = gpio::utility::translate(interruptType);
    gpio_set_intr_type(gpio_, intr_type_t);
}

void Gpio::set_high()
{
    state = 1;
    gpio_set_level(gpio_, state);
}

void Gpio::set_low()
{
    state = 0;
    gpio_set_level(gpio_, state);
}

void Gpio::toggle()
{
    state ^= 1;
    gpio_set_level(gpio_, state);
}

}