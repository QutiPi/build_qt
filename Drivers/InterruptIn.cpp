#include "Drivers/InterruptIn.h"

#include <stdio.h>
#include <QDebug>

namespace QutiPi { namespace Drivers
{

    // Default action
    static void donothing(){}


    /**
     * Create an InterruptIn connected to the specified pin
     *
     *  @param pin InterruptIn pin to connect to
     */
    InterruptIn::InterruptIn(PinName pin) : gpio(),
                                            gpio_irq(),
                                            _rise(),
                                            _fall()
    {
        // Default actions to nothing
        _rise.attach(donothing);
        _fall.attach(donothing);

        // Init the interrupt pin
        gpio_irq_init(&gpio_irq, pin, (&InterruptIn::_irq_handler), (uint32_t)this);
    }


    /**
     * Free the interrupt pin
     *
     * @brief InterruptIn::~InterruptIn
     */
    InterruptIn::~InterruptIn()
    {
        gpio_irq_free(&gpio_irq);
    }


    /**
     * Read the status of the gpio pin
     *
     * @brief InterruptIn::read
     * @return
     */
    int InterruptIn::read()
    {
        return gpio_read(&gpio);
    }


    /**
     * Set the gpio mode (PullUp, PullDown etc)
     *
     * @brief InterruptIn::mode
     * @param pull
     */
    void InterruptIn::mode(PinMode pull)
    {
        gpio_mode(&gpio, pull);
    }



    /**
     * Attach a function to call when a rising edge occurs on the input
     *
     * @param func A pointer to a void function, or 0 to set as none
     */
    void InterruptIn::rise(Callback<void()> func)
    {
        if (func)
        {
            _rise.attach(func);
            gpio_irq_set(&gpio_irq, IRQ_RISE, 1);
        }
        else
        {
            _rise.attach(donothing);
            gpio_irq_set(&gpio_irq, IRQ_RISE, 0);
        }
    }


    /**
     * Attach a function to call when a falling edge occurs on the input
     *
     * @param func A pointer to a void function, or 0 to set as none
     */
    void InterruptIn::fall(Callback<void()> func)
    {
        if (func)
        {
            _fall.attach(func);
            gpio_irq_set(&gpio_irq, IRQ_FALL, 1);
        }
        else
        {
            _fall.attach(donothing);
            gpio_irq_set(&gpio_irq, IRQ_FALL, 0);
        }
    }


    /**
     * Default static call back function
     *
     * @brief _irq_handler
     * @param id
     * @param event
     */
    void InterruptIn::_irq_handler(uint32_t id, gpio_irq_event event)
    {
        // Referance to object
        InterruptIn *handler = (InterruptIn*)((uint32_t*) id);
        //auto *handler = (InterruptIn*)(id);
        //handler->_rise.call();

        // Call revlivent to event
        switch (event)
        {
            case IRQ_RISE:
                handler->_rise.call();
                break;
            case IRQ_FALL:
                handler->_fall.call();
                break;
            case IRQ_NONE:
                break;
        }
    }


    /**
     *  Enable IRQ. This method depends on hw implementation, might enable one
     *  port interrupts. For further information, check gpio_irq_enable().
     */
    void InterruptIn::enable_irq()
    {
        gpio_irq_enable(&gpio_irq);
    }


    /**
     *  Disable IRQ. This method depends on hw implementation, might disable one
     *  port interrupts. For further information, check gpio_irq_disable().
     */
    void InterruptIn::disable_irq() {
        gpio_irq_disable(&gpio_irq);
    }


    /**
     * Short hand for read
     *
     * @brief InterruptIn::operator int
     */
    InterruptIn::operator int() {
        // Underlying call is atomic
        return read();
    }

}}
