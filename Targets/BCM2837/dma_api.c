#include <stdint.h>
#include <stdbool.h>
#include <fcntl.h>
#include <sys/mman.h>

#include <device.h>

#include <Hal/dma_api.h>


/**
 * Hold referance to mapped pwm device in memory
 */
static volatile uint32_t *dma = MAP_FAILED;
static volatile uint32_t *dma15 = MAP_FAILED;



/**
 * Base address to access the pwm
 */
static volatile unsigned int dma_base = BCM_PORT_SHIFT + 0x00007000;
static volatile unsigned int dma15_base = BCM_PORT_SHIFT + 0x00E05000;


/**
 * Define block size
 */
#define BCM_DMA_SIZE 0x1000
