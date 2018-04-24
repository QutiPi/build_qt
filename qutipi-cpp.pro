
# We need Qt core for the library
QT += core

# We dont need a gui for library
QT -= gui

# Define the params for the library
TARGET = qutipi-cpp
TEMPLATE = lib
DEFINES += QUTIPI_CPP
CONFIG += staticlib exceptions

# Disable unused warning parameter
QMAKE_CXXFLAGS_WARN_OFF -= -Wunused-parameter -Wall
QMAKE_CFLAGS_WARN_OFF -= -Wunused-parameter -Wall

# Include the confiruation file
include($$PWD/../../config.pri)

# Select the target for the framework
INCLUDEPATH += $$PWD/Targets/$${TARGETSOC} \
SUBDIRS += $$PWD/Targets/$${TARGETSOC}
include(Targets/$${TARGETSOC}/$${TARGETSOC}.pri)

# Warnings for deprecated Qt features
DEFINES += QT_DEPRECATED_WARNINGS

# Include all the source files
SOURCES += Drivers/DigitalIn.cpp \
    Hardware/ADC/MCP3424.cpp \
    Drivers/I2C.cpp

# Include all the header files
HEADERS += $$PWD/Global.h \
    Drivers/DigitalIn.h \
    Hal/pin_map.h \
    Hal/gpio_api.h \
    Hal/gpclk_api.h \
    Hal/dma_api.h \
    Hal/delay_api.h \
    Hal/pcm_api.h \
    Hal/pwm_api.h \
    Hal/gpio_irq_api.h \
    Hal/port_api.h \
    Hal/time_api.h \
    Hardware/ADC/MCP3424.h \
    Drivers/I2C.h

# Ensure the targets are not included
#SOURCES -= Targets/*/*.cpp
#HEADERS -= Targets/*/*.h

# Include the read me files and licensing files
DISTFILES += \
    $$PWD/readme.md
