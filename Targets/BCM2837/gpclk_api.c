#include <fcntl.h>
#include <sys/mman.h>

#include <device.h>

#include <Hal/gpclk_api.h>


/**
 * Hold referance to mapped clock device in memory
 */
static volatile uint32_t *gpclk = MAP_FAILED;


/**
 * Base address to access the GPIO clock
 */
static volatile unsigned int gpclk_base = BCM_PORT_SHIFT + 0x00101000 ;


/**
 * Define block size
 */
#define BCM_CLK_SIZE 0xA8


/**
 * Setup the gpclk ready for use
 *
 * @brief gpclk_setup
 */
bool gpclk_setup()
{
    // Release memory if range more than once
    if(gpclk != MAP_FAILED)
        munmap((void *)gpclk, BCM_CLK_SIZE);

    // Handler
    int fd;

    // Open dev memory control
    if ((fd = open ("/dev/mem", O_RDWR | O_SYNC | O_CLOEXEC) ) < 0)
    {
      if ((fd = open ("/dev/gpiomem", O_RDWR | O_SYNC | O_CLOEXEC) ) < 0)
          return false;
    }

    // Map device to file system
    gpclk = (uint32_t *)mmap(0, BCM_CLK_SIZE, PROT_READ|PROT_WRITE, MAP_SHARED, fd, gpclk_base);

    // We have success
    return true;
}


/**
 * Destroy setup gpclk
 */
void gpclk_destory()
{
    // Release memory if range more than once
    if(gpclk != MAP_FAILED)
        munmap((void *)gpclk, BCM_CLK_SIZE);
}


/**
 * Assign a clock output to a GPIO pin
 *      NOTE: We assume the use of clock source 1 @19.2MHz
 *
 * @brief set_gpclock
 * @param pin
 * @param frequency
 */
void gpclk_frequency(PinName pin, int frequency)
{
    // Set the integer divisor
    int divi = 19200000 / frequency ;

    // Find the step size
    int resolution = (double)(19200000 % frequency) * 4096.0;

    // Set the fractional divider
    int divf = resolution / 19200000.0;

    // Ensure divi is not over resolution
    if (divi > 4095)
      divi = 4095 ;

    // Clock source
    int source = 1;

    // Request that the GPIO Clock stops
    *(gpclk + pin) = BCM_PASSWORD | source;

    // Wait until BUSY is 0
    while ((*(gpclk + pin) & 0x80) != 0)
      ;

    // Set the new clock divider
    *(gpclk + pin) = BCM_PASSWORD | (divi << 12) | divf;

    // Restart the clock
    *(gpclk + pin) = BCM_PASSWORD | 0x10 | source;
}
