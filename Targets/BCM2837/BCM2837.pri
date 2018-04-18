
# Select the target board for the ic
INCLUDEPATH += $$PWD/Boards/$${TARGETBOARD} \
SUBDIRS += $$PWD/Boards/$${TARGETBOARD}
include(Boards/$${TARGETBOARD}/$${TARGETBOARD}.pri)

# Include all the header files
HEADERS += \
    $$PWD/peripheral_pins.h \
    $$PWD/device.h \
    $$PWD/Device/bcm2837_hal_gpio.h \
    $$PWD/gpio_object.h \
    $$PWD/units.h

# Include all the source files
SOURCES += \
    $$PWD/pin_map.c \
    $$PWD/gpio_api.c \
    $$PWD/Device/bcm2837_hal_gpio.c \
    $$PWD/delay_api.c \
    $$PWD/gpclk_api.c \
    $$PWD/time_api.c

# Include the read me files and licensing files
DISTFILES += \
    $$PWD/readme.md




