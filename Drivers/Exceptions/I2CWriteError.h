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

    class I2CWriteError: public I2CError
    {

        public:
            I2CWriteError(std::string location, int address)
                : I2CError(location, address, "when attempting to write bytes.")
            {
            }

    };

}}}
