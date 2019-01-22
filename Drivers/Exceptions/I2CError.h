#pragma once

#include <string>
#include <string_view>
#include <exception>
#include <utility>
#include <sstream>

#include <device.h>

#include "Drivers/I2C.h"

namespace QutiPi { namespace Drivers { namespace Exceptions
{
    /**
     * A generic exception to return when a failure occures on the I2C bus
     *      - It is recommend that you extend this if a more specific
     *        implimentation is required for a I2C bus error.
     *
     * @brief The I2CError class
     */
    class I2CError: public std::exception
    {

        public:
            I2CError(std::string location, int address, std::string append = "")
                    // Set the bus location
                :   m_location(location)

                    // Set the address location
                ,   m_address(address)
            {

                // Convert address hex
                std::stringstream sstream;
                sstream << std::hex << address;

                // Append string
                if(append != "")
                    append.insert(0, " ");

                // Return
                m_message = "An error occure on I2C bus: " + location + " at address: 0x" + sstream.str() + append;
            }


            /**
             * Return the summary error response
             *
             * @brief what
             * @return
             */
            virtual const char* what() const noexcept override
            {
                return m_message.c_str();
            }


            /**
             * Return the location of the failed IC
             *
             * @brief getAddress
             * @return
             */
            std::string getLocation()
            {
                return m_location;
            }


            /**
             * Return the address of the failed IC
             *
             * @brief getAddress
             * @return
             */
            int getAddress()
            {
                return m_address;
            }

        protected:
            /**
             * Set the summary error message
             *
             * @brief setMessage
             * @param message
             */
            void setMessage(std::string message)
            {
                m_message = message;
            }

        private:
            // Location of device that failed
            std::string m_location;

            // Address of device that failed
            int m_address;

            // Summary error message
            std::string m_message;
    };

}}}
