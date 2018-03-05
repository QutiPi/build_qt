
# We need Qt core for the library
QT += core

# We dont need a gui for library
QT -= gui

# Define the params for the library
TARGET = qutipi-cpp
TEMPLATE = lib
DEFINES += QUTIPI_CPP

# Include the confiruation file
include($$PWD/../../config.pri)

# Select the target for the framework
INCLUDEPATH += $$PWD/Targets/$${TARGETBOARD} \
SUBDIRS += $$PWD/Targets/$${TARGETBOARD}
include( Targets/$${TARGETBOARD}/$${TARGETBOARD}.pro)

# Warnings for deprecated Qt features
DEFINES += QT_DEPRECATED_WARNINGS

# Include all the source files
SOURCES += $$PWD/QutipiCpp.cpp

# Include all the header files
HEADERS += $$PWD/QutipiCpp.h \
    $$PWD/Global.h

# Ensure the targets are not included
SOURCES -= Targets/*/*.cpp
HEADERS -= Targets/*/*.h

# Include the read me files and licensing files
DISTFILES += \
    readme.md
