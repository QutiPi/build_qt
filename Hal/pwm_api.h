#pragma once

#include <device.h>

#ifdef __cplusplus
extern "C" {
#endif

    // Pwm modes
    typedef enum {
        balanced = 1,
        mark_space = 0,
    } PwmModes;

    // Set pwm mode
    void pwm_set_mode(PinName pin, PwmModes mode);

    // Set pwm range
    void pwm_set_range(PinName pin, int range);

    // Set the pwm clock
    void pwm_set_clock(PinName pin, int divisor);

    // Set pwm value
    void pwm_set_value(PinName pin, int value);

#ifdef __cplusplus
}
#endif
