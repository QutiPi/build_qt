#pragma once

#include <stdint.h>
#include <stdbool.h>
#include <fcntl.h>
#include <sys/mman.h>

#include <device.h>
#include <Hal/pin_map.h>


#ifdef __cplusplus
extern "C" {
#endif

    // Hold referance to mapped gpio device in memory
    extern uint32_t * pinmap;

    // Base address to access the GPIO clock
    extern unsigned int gpio_base;

    /**
     * Setup gpio
     *
     * @brief gpio_setup
     */
    void gpio_setup();

    /**
     * Check the pin was not initialized with NC
     *
     * @brief gpio_is_connected
     * @param obj
     * @return
     */
    int gpio_is_connected(const gpio_t *obj);

    /**
     * Init the gpio pin
     *
     * @brief gpio_init
     * @param obj
     * @param pin
     */
    void gpio_init(gpio_t *obj, PinName pin);

    /**
     * Set the pin mode (Up, Down, None)
     *
     * @brief gpio_mode
     * @param obj
     * @param mode
     */
    void gpio_mode(gpio_t *obj, PinMode mode);

    /**
     * Set pin direction
     *
     * @brief gpio_dir
     * @param obj
     * @param pin
     */
    void gpio_dir(gpio_t *obj, PinDirection pin);

    /**
     * Set if the pin is an input or output
     *
     * @brief gpio_set
     * @param obj
     * @param pin
     */
    void gpio_set(gpio_t *obj, FunctionSelect pin);

    /**
     * Read value from the gpio pin
     *
     * @brief gpio_read
     * @param obj
     * @return
     */
    int gpio_read(gpio_t *obj);

    /**
     * Write value to the gpio pin
     *
     * @brief gpio_write
     * @param obj
     * @param value
     */
    void gpio_write(gpio_t *obj, int value);

#ifdef __cplusplus
}
#endif
