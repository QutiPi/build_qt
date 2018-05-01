#pragma once

#include "Hal/gpio_api.h"

namespace QutiPi { namespace Drivers {

    class DigitalIn {

        public:

            /**
             * Create DigitalIn and connect to a selected pin
             *
             * @brief DigitalIn
             * @param pin
             */
            DigitalIn(PinName pin) : gpio()
            {
                // Configure a pin
                gpio_init(&gpio, pin);

                // Set mode (pull up, down, none)
                gpio_mode(&gpio, PullNone);

                // Set the function (input, output, SDA etc)
                gpio_set(&gpio, INPUT);
            }


            /**
             *  Create DigitalIn, connect to a selected pin and set the mode
             *
             *  @param pin DigitalIn pin to connect to
             *  @param mode the initial mode of the pin
             */
            DigitalIn(PinName pin, PinMode mode) : gpio()
            {
                // Configure a pin
                gpio_init(&gpio, pin);

                // Set mode (pull up, down, none)
                gpio_mode(&gpio, mode);

                // Set the function (input, output, SDA etc)
                gpio_set(&gpio, INPUT);
            }


            /**
             * Read the input for a selected pin
             *
             * @brief read
             * @return
             *      - 0 if logic low
             *      - 1 if logic high
             */
            int read() {
                // Thread safe / atomic HAL call
                return gpio_read(&gpio);
            }


            /**
             * Set the input pin mode
             *
             *  @param pull PullUp, PullDown, PullNone
             */
            void mode(PinMode pull)
            {
                gpio_mode(&gpio, pull);
            }


            /**
             * Is the pin setup
             *
             * @brief is_connected
             * @return
             *      - 0 if gpio init with NC
             *      - Not zero if init with valid GPIO
             */
            int is_connected()
            {
                return gpio_is_connected(&gpio);
            }


            /**
             * Short hand for read
             *
             * @brief operator int
             */
            operator int()
            {
                return read();
            }

        protected:
            gpio_t gpio;
    };

}}



