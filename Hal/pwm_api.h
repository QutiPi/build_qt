#pragma once
#include <stdint.h>
#include <stdbool.h>

#include <device.h>

#ifdef __cplusplus
extern "C" {
#endif

    // Hold referance to mapped pwm device in memory
    extern uint32_t * pwm;

    // Base address to access the pwm
    extern unsigned int pwm_base;

    // Pwm modes
    typedef enum {
        balanced = 1,
        mark_space = 0,
    } PwmModes;

    bool pwm_setup();
    bool pwm_destory();

    // Set pwm mode
    void pwm_set_mode(PinName pin, PwmModes mode);

    // Set pwm range
    void pwm_set_range(PinName pin, int range);

    // Set the pwm clock
    void pwm_set_clock(PinName pin, int divisor);

    // Set pwm value
    void pwm_write(PinName pin, int value);

#ifdef __cplusplus
}
#endif
