#pragma once

#include <device.h>

#ifdef __cplusplus
extern "C" {
#endif

    // Required struct to be declared in target hals
    typedef struct port_s port_t;

    // Init the port
    void port_init(port_t *obj, PortName port, int mask, FunctionSelect dir);

    // Set the port input mode
    void port_mode(port_t *obj, PinMode mode);

    // Set port direction (input or output)
    void port_func(port_t *obj, FunctionSelect dir);

    // Write a value to the port
    void port_write(port_t *obj, int value);

    // Read the current value of the port
    int port_read(port_t *obj);

#ifdef __cplusplus
}
#endif
