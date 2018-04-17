#pragma once

#include <device.h>

#ifdef __cplusplus
extern "C" {
#endif

    void set_gpclock(PinName pin, int frequency);

#ifdef __cplusplus
}
#endif
