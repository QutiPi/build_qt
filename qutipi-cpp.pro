
# We need Qt core for the library
QT += core

# We dont need a gui for library
QT -= gui

# Define the params for the library
TARGET = qutipi-cpp
TEMPLATE = lib
DEFINES += QUTIPI_CPP
CONFIG += staticlib

# Include the confiruation file
include($$PWD/../../config.pri)

# Select the target for the framework
INCLUDEPATH += $$PWD/Targets/$${TARGETSOC} \
SUBDIRS += $$PWD/Targets/$${TARGETSOC}
include( Targets/$${TARGETSOC}/$${TARGETSOC}.pro)

# Warnings for deprecated Qt features
DEFINES += QT_DEPRECATED_WARNINGS

# Include all the source files
SOURCES += Drivers/DigitalIn.cpp \

# Include all the header files
HEADERS += $$PWD/Global.h \
    Hal/gpio.h \
    Drivers/DigitalIn.h \
    Hal/pin_map.h \
    Hal/dma.h \
    Hal/pwm.h \
    Hal/gpio_irq.h \
    Hal/delay.h \
    Hal/gpclk.h \
    Hal/timer.h \
    Hal/pcm.h

# Ensure the targets are not included
#SOURCES -= Targets/*/*.cpp
#HEADERS -= Targets/*/*.h

# Include the read me files and licensing files
DISTFILES += \
    $$PWD/readme.md
