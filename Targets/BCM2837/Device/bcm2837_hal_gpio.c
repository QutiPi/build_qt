
#include <Device/bcm2837_hal_gpio.h>

/**
 * Set the maxium drive for an gpio group before damage can be caused
 *      CAUTION: This is not a current source and you should not max out all group
 *      USEFUL READ: https://www.scribd.com/doc/101830961/GPIO-Pads-Control2
 *
 * @brief gpio_set_pad_drive
 * @param group
 *          1: 0x 7e10 002c PADS (GPIO 0-27)
 *          2: 0x 7e10 0030 PADS (GPIO 28-45)
 *          3: 0x 7e10 0034 PADS (GPIO 46-53)
 * @param value
 *          0: 2mA
 *          1: 4mA
 *          2: 6mA
 *          3: 8mA
 *          4: 10mA
 *          5: 12mA
 *          6: 14mA
 *          7: 16mA
 */
void gpio_set_pad_drive(int group, int value)
{

}


/**
 * Set whether to use input hystersis for a group of gpio
 *
 * @brief gpio_input_hysteresis
 * @param group
 * @param state
 */
void gpio_input_hysteresis(int group, bool state)
{

}


/**
 * Limit a group of GPIO's slew rate
 *
 * @brief gpio_limit_slew_rate
 * @param group
 * @param state
 */
void gpio_limit_slew_rate(int group, bool state)
{

}



