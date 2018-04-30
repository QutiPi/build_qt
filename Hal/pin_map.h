#pragma once
#include <stdint.h>
#include <stdbool.h>
#include <fcntl.h>
#include <sys/mman.h>

#include <device.h>

#ifdef __cplusplus
extern "C" {
#endif

    // Hold referance to mapped gpio device in memory
    extern uint32_t * pinmap;

    // Base address to access the GPIO clock
    extern unsigned int gpio_base;

    // Setup GPIO for use
    bool pinmap_setup();


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
