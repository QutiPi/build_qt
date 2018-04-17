#pragma once

#include <device.h>

#ifdef __cplusplus
extern "C" {
#endif

    // Select the function for a pin
    void pin_func(PinName pin, FunctionSelect function);

    // Return the current pin function
    FunctionSelect pin_func(PinName pin);

    // Set pull up down none
    void pin_mode(PinName pin, PinMode mode);

    // Return the current pin mode
    PinMode pin_mode(PinName pin);

#ifdef __cplusplus
}
#endif
