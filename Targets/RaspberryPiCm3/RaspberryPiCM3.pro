
# We need Qt core for the library
QT += core

# We dont need a gui for library
QT -= gui

# Define the params for the library
TEMPLATE = lib

# Warnings for deprecated Qt features
DEFINES += QT_DEPRECATED_WARNINGS

# Include all the header files


# Include all the source files
SOURCES += \
    $$PWD/../RaspberryPiCm3/gpio.c

# Include the read me files and licensing files
DISTFILES += \
    readme.md


