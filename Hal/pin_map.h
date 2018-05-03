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

    /**
     * Setup GPIO for use
     *
     * @brief pinmap_setup
     * @return
     */
    bool pinmap_setup();

    /**
     * Cleanup
     *
     * @brief pinmap_destory
     */
    void pinmap_destory();


    /**
     * Select the function for a pin
     *
     * @brief pin_function
     * @param pin
     * @param function
     */
    void pin_function(PinName pin, FunctionSelect function);

    /**
     * Return the current pin function
     *
     * @brief pin_function_current
     * @param pin
     * @return
     */
    FunctionSelect pin_function_current(PinName pin);

    /**
     * Asset that the pin is allowed the current function
     *
     * @brief assert_functionality
     * @param pin
     * @param function
     * @return
     */
    FunctionPeripherals assert_functionality(PinName pin, FunctionSelect function);


    /**
     * Set pull up down none
     *
     * @brief pin_mode
     * @param pin
     * @param mode
     */
    void pin_mode(PinName pin, PinMode mode);

    /**
     * Return the current pin mode
     *
     * @brief pin_mode_current
     * @param pin
     * @return
     */
    PinMode pin_mode_current(PinName pin);

#ifdef __cplusplus
}
#endif
