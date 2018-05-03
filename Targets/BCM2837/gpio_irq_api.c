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
 * Sam
 *
 */


#include <Hal/gpio_irq_api.h>

#include <stdio.h>
#include <stdbool.h>
#include <pthread.h>
#include <sys/poll.h>
#include <string.h>
#include <fcntl.h>
#include <sys/unistd.h>


// Monitoring thread
static pthread_t pthIrq;
static volatile int monitor_status = 1;
static pthread_mutex_t monitor_mutex;

static gpio_irq_handler irq_handler;

// Hold all interrupts that should be monitored
gpio_irq_t monitors[64];


/**
 * Monitor for threads
 *
 * @brief pthIrqThread
 */
static int *pthIrqThread()
{
    // Init vars
    int x;
    uint8_t c;

    // printf("Thread running \r");

    // Set pirority

    // Get any changes
    gpio_irq_t local[64];

    // Monitor for interrupts
    while(true)
    {
        pthread_mutex_lock(&monitor_mutex);
            memcpy(local, monitors, sizeof(monitors));
        pthread_mutex_unlock(&monitor_mutex);

        // For each possiable interrupt
        int i = 0;

        for(i; i < 64; i++)
        {
            // If not acive no need to check
            if(!local[i].active)
                continue;

            // Check file
            x = poll(&local[i].pfd, 1, local[i].timeout);

            // If file has data
            if (x > 0)
            {
                // Rewind
                lseek(local[i].pfd.fd, 0, SEEK_SET);

                // Read & clear
                (void)read(local[i].pfd.fd, &c, 1);

                // Run function
                local[i].handler(local[i].pin, local[i].event);
            }
        }


        // Check wanted status of thread
        pthread_mutex_lock(&monitor_mutex);
            int status = monitor_status;
        pthread_mutex_unlock(&monitor_mutex);

        // Thread has been requested to shut down
        if(status == 2)
        {
            // Set the thread as shut down
            pthread_mutex_lock(&monitor_mutex);
                monitor_status = 0;
            pthread_mutex_unlock(&monitor_mutex);

            printf("Shutting down");

            // Return to end thread
            return 0;
        }
    }
}


/**
 * Setup the thread for monitoring sys and running functions
 *
 * @brief gpio_irq_setup
 * @return
 */
bool gpio_irq_setup()
{
    // Setup pthread
     pthread_attr_t attr;

    // @NOTICE  pthread fuctions return 0 on success negative on failure

    // Init attributes
    if(pthread_attr_init(&attr) == 0)
    {
        if (pthread_attr_setstacksize(&attr, (256*1024)) == 0)
        {
            if(pthread_create(&pthIrq, &attr, pthIrqThread, NULL) == 0)
            {
                // Success
                return true;
            }
        }
    }

    // Failure
    return false;
}


/**
 * Destory iqr functionality
 *
 * @brief gpio_irq_destory
 * @return
 */
bool gpio_irq_destory()
{
    // Tell the thread to quit
    pthread_mutex_lock(&monitor_mutex);
        monitor_status = 2;
    pthread_mutex_unlock(&monitor_mutex);

    // Wait for thread to quit
    while(true)
    {
        // Whats the status of the thread?
        pthread_mutex_lock(&monitor_mutex);
            int status = monitor_status;
        pthread_mutex_unlock(&monitor_mutex);

        // If the thread has stopped then exit
        if(status == 0)
        {
            pthread_cancel(pthIrq);
            pthread_join(pthIrq, NULL);
            break;
        }
    }

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
    // Select pin
    obj->pin = pin;

    // Set the return function
    obj->handler = handler;
    obj->object = id;

    obj->active = false;
    obj->timeout = 0;
    obj->pfd.fd = -1;
    obj->pfd.events = POLLPRI | POLLERR;
    obj->event = IRQ_NONE;

    // Check valid pin
    if (pin == NC)
        return -1;

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

    // Update monitor thread @todo malloc
    pthread_mutex_lock(&monitor_mutex);
        monitors[obj->pin] = *obj;
    pthread_mutex_unlock(&monitor_mutex);

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

    // Update monitor thread
    pthread_mutex_lock(&monitor_mutex);
        monitors[obj->pin] = *obj;
    pthread_mutex_unlock(&monitor_mutex);
}


/**
 * Enable GPIO IRQ
 *
 * @param obj The GPIO object
 */
void gpio_irq_enable(gpio_irq_t *obj)
{
    // Buffer for writes
    char buf[64];

    // Get trigger type
    const char *modeS = "falling";
    switch(obj->event)
    {
        case IRQ_FALL:
            modeS = "falling";
            break;
        case IRQ_RISE:
            modeS = "rising";
            break;
        case IRQ_BOTH:
            modeS = "both";
            break;
        case IRQ_NONE:
            modeS = "none";
            break;
    }

    // Export gpio
    int fdExport = open("/sys/class/gpio/export", O_WRONLY);
    sprintf(buf, "%d\n", obj->pin);
    write(fdExport, buf, strlen(buf));
    close(fdExport);


    // Set gpio direction
    sprintf(buf, "/sys/class/gpio/gpio%d/direction", obj->pin);
    int fdDir = open(buf, O_WRONLY);
    write(fdDir, "in\n", 3);
    close(fdDir);


    // Set gpio edge mode
    if(obj->event != IRQ_NONE)
    {
        sprintf(buf, "/sys/class/gpio/gpio%d/edge", obj->pin);
        int fdEdge = open(buf, O_WRONLY);
        write(fdEdge, modeS, strlen(modeS));
        close(fdEdge);
    }

    // Open file handler for reading only
    sprintf(buf, "/sys/class/gpio/gpio%d/value", obj->pin);
    obj->pfd.fd = open(buf, O_RDWR);
    obj->pfd.events = POLLPRI | POLLERR;

    // Remove previous interrupts
    lseek(obj->pfd.fd, 0, SEEK_SET);
    (void)read(obj->pfd.fd, &buf, sizeof buf);
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

    // Remove port from sys
    int fd = open("/sys/class/gpio/unexport", O_WRONLY);
    sprintf(buf, "%d\n", obj->pin);
    write(fd, buf, strlen(buf));
    close(fd);

    // Close file descriptor
    close(obj->pfd.fd);
    obj->pfd.fd = -1;

    // Set active
    obj->active = false;
}
