#pragma once

#include "Hal/gpio_irq_api.h"
#include "Hal/gpio_api.h"
#include "Platform/Callback.h"
#include "Platform/NonCopyable.h"

using namespace QutiPi::Platform;

namespace QutiPi { namespace Drivers {

    class InterruptIn : private NonCopyable<InterruptIn> {

        public:

            /**
             * Create an InterruptIn connected to the specified pin
             *
             *  @param pin InterruptIn pin to connect to
             */
            InterruptIn(PinName pin);
            virtual ~InterruptIn();


            /**
             * Read the input, represented as 0 or 1 (int)
             *
             * @returns int An integer representing the state of the input pin,
             *              - 0 for logic low,
             *              - 1 for logic high
             */
            int read();


            /**
             * An operator shorthand for read()
             */
             operator int();


            /**
             * Attach a function to call when a rising edge occurs on the input
             *
             * @param func A pointer to a void function, or 0 to set as none
             */
            void rise(Callback<void()> func);


            /**
             * Attach a function to call when a falling edge occurs on the input
             *
             * @param func A pointer to a void function, or 0 to set as none
             */
            void fall(Callback<void()> func);


            /**
             * Set the input pin mode
             *
             * @param mode PullUp, PullDown, PullNone
             */
            void mode(PinMode pull);


            /**
             *  Enable IRQ. This method depends on hw implementation, might enable one
             *  port interrupts. For further information, check gpio_irq_enable().
             */
            void enable_irq();


            /**
             *  Disable IRQ. This method depends on hw implementation, might disable one
             *  port interrupts. For further information, check gpio_irq_disable().
             */
            void disable_irq();


            /**
             * Default call back function
             *
             * @brief _irq_handler
             * @param id
             * @param event
             */
            static void _irq_handler(uint32_t id, gpio_irq_event event);

        private:
            gpio_t gpio;
            gpio_irq_t gpio_irq;
            Callback<void()> _rise;
            Callback<void()> _fall;
    };

}}
