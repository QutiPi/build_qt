#pragma once

#include <stdint.h>
#include <stdbool.h>

#include "pin_names.h"
#include "port_names.h"


#if OS==WINDOWS
    struct pollfd {
       int   fd;      // file descriptor
       short events;  // requested events
       short revents; // returned events
    };
#elif OS==LINUX
    #include <sys/poll.h>
#endif


#ifdef __cplusplus
extern "C" {
#endif

// IRQ Events
typedef enum {
    IRQ_NONE,
    IRQ_BOTH,
    IRQ_RISE,
    IRQ_FALL
} gpio_irq_event;

// Do not changed (always required in this format for full support)
typedef void (*gpio_irq_handler)(uint32_t objectId, gpio_irq_event event);

// Interrupt type
struct gpio_irq_s {
    PinName pin;
    gpio_irq_handler handler;
    uint32_t objectId;
    gpio_irq_event event;
    bool active;
    int timeout;
    struct pollfd pfd;
};

#ifdef __cplusplus
}
#endif

