#pragma once

#include <pin_names.h>

#ifdef __cplusplus
extern "C" {
#endif

    typedef struct {
        PinName pin;
        int peripheral;
        FunctionSelect function;
    } PinMap;

    // Select the function for a pin
    void pin_function(PinName pin, FunctionSelect function);

    // Input, output
    void pin_mode(PinName pin, PinMode mode);

#ifdef __cplusplus
}
#endif
