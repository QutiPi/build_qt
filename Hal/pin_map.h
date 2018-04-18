#pragma once

#include <device.h>

#ifdef __cplusplus
extern "C" {
#endif

    // Hold referance to mapped gpio device in memory
    static volatile uint32_t * pinmap = MAP_FAILED;

    // Base address to access the GPIO clock
    static volatile unsigned int gpio_base = BCM_PORT_SHIFT + 0x00200000;

    // Define block size
    #define BCM_GPIO_SIZE 0xB4



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
