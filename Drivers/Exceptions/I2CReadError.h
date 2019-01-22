#pragma once

#include <string>
#include <string_view>
#include <exception>
#include <utility>
#include <sstream>

#include <device.h>

#include "Drivers/Exceptions/I2CError.h"

namespace QutiPi { namespace Drivers { namespace Exceptions
{

    class I2CReadError: public I2CError
    {

        public:
            I2CReadError(std::string location, int address)
                : I2CError(location, address, "when attempting to read bytes.")
            {
            }

    };

}}}
