
#include <device.h>


/**
 * Hold referance to mapped devices in memory
 */
volatile uint32_t * pinmap = NULL;


/**
 * Base address to access the registers
 */
volatile unsigned int gpio_base = BCM_PORT_SHIFT + 0x00200000;



