#pragma once

#include <device.h>

#ifdef __cplusplus
extern "C" {
#endif

    // Setup GPIO for use
    void pinmap_setup();


    // Select the function for a pin
    void pin_function(PinName pin, FunctionSelect function);

    // Return the current pin function
    FunctionSelect pin_function_current(PinName pin);


    // Set pull up down none
    void pin_mode(PinName pin, PinMode mode);

    // Return the current pin mode
    PinMode pin_mode_current(PinName pin);

#ifdef __cplusplus
}
#endif
