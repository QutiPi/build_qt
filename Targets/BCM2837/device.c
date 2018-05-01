
#include <device.h>


/**
 * Hold referance to mapped devices in memory
 */
volatile uint32_t * pinmap = NULL;
volatile uint32_t *pwm = NULL;



/**
 * Base address to access the registers
 */
volatile unsigned int gpio_base = BCM_PORT_SHIFT + 0x00200000;
volatile unsigned int pwm_base = BCM_PORT_SHIFT + 0x0020C000;


