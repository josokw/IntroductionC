TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += c11

SOURCES += main.c \
    display.c \
    subsystems.c

HEADERS += \
    display.h \
    fsm.h \
    subsystems.h
