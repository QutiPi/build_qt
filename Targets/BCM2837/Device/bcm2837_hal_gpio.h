#pragma once

#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

    // Set pad drive
    void gpio_set_pad_drive(int group, int value);

    // Set input hysteresis
    // void gpio_input_hysteresis(int group, bool state);

    // Limit slew rate of GPIO group
    // void gpio_limit_slew_rate(int group, bool state);

#ifdef __cplusplus
}
#endif
