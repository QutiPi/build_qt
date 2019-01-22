
# Select the target board for the ic
INCLUDEPATH += $$PWD/Boards/$${TARGETBOARD} \
SUBDIRS += $$PWD/Boards/$${TARGETBOARD}
include(Boards/$${TARGETBOARD}/$${TARGETBOARD}.pri)

# Disable unused warning parameter
QMAKE_CXXFLAGS_WARN_OFF -= -Wunused-parameter -Wall
QMAKE_CFLAGS_WARN_OFF -= -Wunused-parameter -Wall

# Include all the header files
HEADERS += \
    $$PWD/peripheral_pins.h \
    $$PWD/device.h \
    $$PWD/gpio_object.h \
    $$PWD/units.h

# Include all the source files
SOURCES += \
    $$PWD/pin_map.c \
    $$PWD/gpio_api.c \
    $$PWD/delay_api.c \
    $$PWD/gpclk_api.c \
    $$PWD/time_api.c \
    $$PWD/pwm_api.c \
    $$PWD/dma_api.c \
    $$PWD/pcm_api.c \
    $$PWD/device.c \
    $$PWD/gpio_irq_api.c \
    $$PWD/i2c_api.c

# Include the read me files and licensing files
DISTFILES += \
    $$PWD/readme.md
