#pragma once

#include "Hal/gpio_api.h"

namespace QutiPi { namespace Drivers
{

    /**
     * A digital input/output, used for setting or reading a bi-directional pin
     *
     * @ingroup drivers
     */
    class DigitalInOut {

        public:

            /**
             * Create a DigitalInOut connected to the specified pin
             *
             *  @param pin DigitalInOut pin to connect to
             */
            DigitalInOut(PinName pin) : gpio()
            {
                // Configure a pin
                gpio_init(&gpio, pin);

                // Set mode (pull up, down, none)
                gpio_mode(&gpio, PullNone);

                // Set the function (input, output, SDA etc)
                gpio_set(&gpio, INPUT);
            }

            /**
             * Create a DigitalInOut connected to the specified pin
             *
             *  @param pin DigitalInOut pin to connect to
             *  @param direction the initial direction of the pin
             *  @param mode the initial mode of the pin
             *  @param value the initial value of the pin if is an output
             */
            DigitalInOut(PinName pin, PinDirection direction, PinMode mode, int value) : gpio()
            {
                // Configure a pin
                gpio_init(&gpio, pin);

                // Set mode (pull up, down, none)
                gpio_mode(&gpio, mode);

                // Set the function (input, output, SDA etc)
                gpio_dir(&gpio, direction);

                // Write
                if(direction == PIN_OUTPUT)
                    gpio_write(&gpio, value);
            }


            /**
             * Set value of output, specified as 0 or 1 (int)
             *
             * @brief write
             * @param value An integer specifying the pin output value,
             *          - 0 for logic low,
             *          - 1 (or any other non-zero value) for logic high
             */
            void write(int value)
            {
                // Thread safe / atomic HAL call
                gpio_write(&gpio, value);
            }


            /**
             * Return the output setting, represented as 0 or 1 (int)
             *
             * @brief read
             * @return int
             *          - integer representing the output setting of the pin if it is an output,
             *          - read value of the input if gpio set as an input
             */
            int read()
            {
                return gpio_read(&gpio);
            }


            /**
             * Set the pin as an input
             *
             * @brief output
             */
            void output()
            {
                gpio_dir(&gpio, PIN_OUTPUT);
            }


            /**
             * Set the pin as an input
             *
             * @brief input
             */
            void input()
            {
                gpio_dir(&gpio, PIN_INPUT);
            }


            /**
             * Set the input pin mode (PullUp, PullDown etc)
             *
             * @brief mode
             * @param pull
             */
            void mode(PinMode pull)
            {
                gpio_mode(&gpio, pull);
            }


            /**
             * Return the output setting, represented as 0 or 1 (int)
             *
             * @brief is_connected
             * @return int
             *          - Non zero value if pin is connected to a GPIO
             *          - 0 if gpio object was initialized with NC
             */
            int is_connected()
            {
                return gpio_is_connected(&gpio);
            }


            /**
             * Short hand for write
             *
             * @brief operator =
             * @param value
             * @return
             */
            DigitalInOut& operator= (int value)
            {
                write(value);
                return *this;
            }


            /**
             * Short hand for write
             *
             * @brief operator =
             * @param rhs
             * @return
             */
            DigitalInOut& operator= (DigitalInOut& rhs)
            {
                write(rhs.read());
                return *this;
            }


            /**
             * A shorthand for read()
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
