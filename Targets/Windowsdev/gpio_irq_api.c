/**
 * @NOTICE Interupts in Linux
 *
 * Only the kernal (linux) can receive hardware interrupts. There is
 * no way to my knowledge of having hardware interupts within applications
 * running on linux.
 *
 * When linux has an interrupt configured on a pin it will clear the interupt
 * instantly (so it does not miss the next one). Hence i think accessing the
 * interupt registers directly outside of the kernal is pointless.
 *
 * When the kernal receives an interrupt it can transfer a notice to
 * the virtual sys file structure if configured to do so. This is a method of
 * propergating the interrupt onwards to all other services and programs running.
 *
 * Hence this class will impliment a "Soft Interupt" where by it will tell linux
 * to propergate interupts onwards to the sys file structure. The class will then
 * setup a service thread which will constantly monitor for propergated interupts.
 * When it sees one it will run the function the user has requested.
 *
 * I could be wrong but i think the above summarises the problem and solution. Please
 * let me know if i am mistaken or there is a better way.
 *
 * The current implementation has a delay average of around 55-65uS between interupt and
 * the users function being ran, tested through the InteruptIn driver.
 *
 * Sam
 *
 */


#include <Hal/gpio_irq_api.h>

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <fcntl.h>


/**
 * Setup the thread for monitoring sys and running functions
 *
 * @brief gpio_irq_setup
 * @return
 */
bool gpio_irq_setup()
{
    return true;
}


/**
 * Destory iqr functionality
 *
 * @brief gpio_irq_destory
 * @return
 */
bool gpio_irq_destory()
{
   return true;
}


/**
 * Initialize the GPIO IRQ pin
 *
 * @param obj     The GPIO object to initialize
 * @param pin     The GPIO pin name
 * @param handler The handler to be attached to GPIO IRQ
 * @param id      The object ID (id != 0, 0 is reserved)
 * @return -1 if pin is NC, 0 otherwise
 */
int gpio_irq_init(gpio_irq_t *obj, PinName pin, gpio_irq_handler handler, uint32_t id)
{
    return 1;
}


/**
 * Release the GPIO IRQ PIN
 *
 * @param obj The gpio object
 */
void gpio_irq_free(gpio_irq_t *obj)
{
    // Disable IRQ
    gpio_irq_disable(obj);
}


/**
 * Enable/disable pin IRQ event
 *
 * @param obj    The GPIO object
 * @param event  The GPIO IRQ event
 * @param enable The enable flag
 */
void gpio_irq_set(gpio_irq_t *obj, gpio_irq_event event, uint32_t enable)
{
    // Set level
    obj->event = event;

    // Enable IRQ
    gpio_irq_enable(obj);

    // Set active
    obj->active = (bool) enable;
}


/**
 * Enable GPIO IRQ
 *
 * @param obj The GPIO object
 */
void gpio_irq_enable(gpio_irq_t *obj)
{

}


/**
 * Disable GPIO IRQ
 *
 * @param obj The GPIO object
 */
void gpio_irq_disable(gpio_irq_t *obj)
{
    // Buffer for writes
    char buf[64];

    // Close file descriptor
    obj->pfd.fd = -1;

    // Set active
    obj->active = false;
}
