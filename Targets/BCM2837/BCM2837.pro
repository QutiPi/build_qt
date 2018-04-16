
# We need Qt core for the library
QT += core

# We dont need a gui for library
QT -= gui

# Define the params for the library
TEMPLATE = lib

# Warnings for deprecated Qt features
DEFINES += QT_DEPRECATED_WARNINGS

# Select the target board for the ic
include(Boards/$${TARGETBOARD}/$${TARGETBOARD}.pri)

# Include all the header files
HEADERS += \
    $$PWD/port_types.h

# Include all the source files
SOURCES += \
    $$PWD/gpio.c

# Include the read me files and licensing files
DISTFILES += \
    $$PWD/readme.md




