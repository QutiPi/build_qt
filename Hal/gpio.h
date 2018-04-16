#pragma once

#ifdef __cplusplus
extern "C" {
#endif

    int gpio_init();

    int gpio_read();

    void gpio_mode();

    void gpio_dir();

    void gpio_write();

#ifdef __cplusplus
}
#endif
