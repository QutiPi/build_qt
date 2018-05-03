#pragma once

#include <device.h>

#ifdef __cplusplus
extern "C" {
#endif


    /**
     * GPIO IRQ events
     */
    typedef enum {
        IRQ_BOTH,
        IRQ_RISE,
        IRQ_FALL
    } gpio_irq_event;


    /**
     * GPIO IRQ HAL structure. gpio_irq_s is declared in the target's HAL
     */
    typedef struct gpio_irq_s gpio_irq_t;

    typedef void (*gpio_irq_handler)(PinName pin, gpio_irq_event event);


    /**
     * Setup the iqr functionality
     *
     * @brief gpio_irq_setup
     * @return
     */
    bool gpio_irq_setup();


    /**
     * Destory iqr functionality
     *
     * @brief gpio_irq_destory
     * @return
     */
    bool gpio_irq_destory();


    /**
     * Initialize the GPIO IRQ pin
     *
     * @param obj     The GPIO object to initialize
     * @param pin     The GPIO pin name
     * @param handler The handler to be attached to GPIO IRQ
     * @param id      The object ID (id != 0, 0 is reserved)
     * @return int
     *          - 1 if pin is NC
     *          - 0 otherwise
     */
    int gpio_irq_init(gpio_irq_t *obj, PinName pin, gpio_irq_handler handler, uint32_t id);


    /**
     * Release the GPIO IRQ PIN
     *
     * @param obj The gpio object
     */
    void gpio_irq_free(gpio_irq_t *obj);


    /**
     * Enable/disable pin IRQ event
     *
     * @param obj    The GPIO object
     * @param event  The GPIO IRQ event
     * @param enable The enable flag
     */
    void gpio_irq_set(gpio_irq_t *obj, gpio_irq_event event, uint32_t enable);


    /**
     * Enable GPIO IRQ
     *
     * This is target dependent, as it might enable the entire port or just a pin
     * @param obj The GPIO object
     */
    void gpio_irq_enable(gpio_irq_t *obj);


    /**
     * Disable GPIO IRQ
     *
     * This is target dependent, as it might disable the entire port or just a pin
     * @param obj The GPIO object
     */
    void gpio_irq_disable(gpio_irq_t *obj);


#ifdef __cplusplus
}
#endif
