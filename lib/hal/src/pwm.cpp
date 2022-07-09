#include <pwm.hpp>

namespace hal {

namespace pwm {

}
Pwm::Pwm()
{
    channelConfig.gpio_num = 0; //< int
    channelConfig.speed_mode = LEDC_LOW_SPEED_MODE; //< ledc_mode_t
    channelConfig.channel = LEDC_CHANNEL_0; //< ledc_channel_t
    channelConfig.intr_type = LEDC_INTR_DISABLE; //< ledc_intr_type_t
    channelConfig.timer_sel = LEDC_TIMER_0; //< ledc_timer_t
    channelConfig.duty = 30; //< uint32_T  [0, (2**duty_resolution)]
    channelConfig.hpoint = 40; //< int
}

}