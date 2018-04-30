#pragma once

#include "Hal/gpio_api.h"
#include <QDebug>
namespace QutiPi { namespace Drivers
{

    class DigitalOut
    {

    public:

        /**
         * Create a digital out pin
         * @brief DigitalOut
         */
        DigitalOut(PinName pin) : gpio()
        {
            // Configure a pin
            gpio_init(&gpio, pin);

            // Set the function (input, output, SDA etc)
            gpio_set(&gpio, OUTPUT);

            // Set mode (pull up, down, none)
            gpio_mode(&gpio, NONE);
        }


        /**
         * Create a digital out pin
         * @brief DigitalOut
         */
        DigitalOut(PinName pin, int value) : gpio()
        {
            // Configure a pin
            gpio_init(&gpio, pin);

            // Write a value to the pin
            gpio_write(&gpio, value);

            // Set mode (pull up, down, none)
            gpio_mode(&gpio, NONE);

            // Set the function (input, output, SDA etc)
            gpio_set(&gpio, OUTPUT);
        }


        /**
         * Read a logic level from a port
         *
         * @brief read
         * @return
         */
        int read()
        {
            // Read port
            return gpio_read(&gpio);
        }


        /**
         * Is the pin setup
         *
         * @brief is_connected
         * @return
         */
        int is_connected()
        {
            return gpio_is_connected(&gpio);
        }


        /**
         * Write a logic level to configured port
         *
         * @brief write
         * @param value
         */
        void write(int value)
        {
            // qDebug() << "Pin name: " << gpio.pin << " Value: " << value;
            // Write value to port
            gpio_write(&gpio, value);
        }


        /**
         * Short hand for write method
         *
         * @brief operator =
         * @param value
         * @return
         */
        DigitalOut& operator= (int value)
        {
            // Write a value from an equals operator
            write(value);

            // Return object
            return *this;
        }


        /**
         * Short hand for write method
         *
         * @brief operator =
         * @param rhs
         * @return
         */
        DigitalOut& operator= (DigitalOut& rhs)
        {
            // Write a value to configured port from another port
            write(rhs.read());

            // Return object
            return *this;
        }


        /**
         * Short hand for read method
         *
         * @brief operator int
         */
        operator int()
        {
            // Read value from port
            return read();
        }


    protected:
        gpio_t gpio;


    };

}}
