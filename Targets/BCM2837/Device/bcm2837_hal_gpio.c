#include <stdint.h>
#include <stdbool.h>
#include <fcntl.h>
#include <sys/mman.h>

#include <Device/bcm2837_hal_gpio.h>
#include <Hal/pin_map.h>


/**
 * Hold referance to mapped pads device in memory
 */
static volatile uint32_t *pads = MAP_FAILED;


/**
 * Base address to access the pads
 */
static volatile unsigned int pads_base = BCM_PORT_SHIFT + 0x00100000;


/**
 * Define block size
 */
#define BCM_GPIO_SIZE 0x38




/**
 * Set the maxium drive for an gpio group before damage can be caused
 *      CAUTION: This is not a current source and you should not max out all group
 *      USEFUL READ: https://www.scribd.com/doc/101830961/GPIO-Pads-Control2
 *
 * @brief gpio_set_pad_drive
 * @param group
 *          0: 0x 7e10 002c PADS (GPIO 0-27)
 *          1: 0x 7e10 0030 PADS (GPIO 28-45)
 *          2: 0x 7e10 0034 PADS (GPIO 46-53)
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
    // Ensure group and value are between allowed ranges
    if ((group < 0) || (group > 2) || (value < 0) || (value > 7))
          return ;

    // Generate the new configuration
    uint32_t config = BCM_PASSWORD | 0x18 | (value & 7) ;

    // Assign the new configuration
    *(pads + group + 11) = config ;
}



