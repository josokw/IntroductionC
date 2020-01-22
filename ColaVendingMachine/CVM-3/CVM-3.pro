TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += c11

SOURCES += main.c \
    coinAcceptor.c \
    colaDispenser.c \
    display.c \
    keyboard.c \
    subsystems.c

HEADERS += \
    coinAcceptor.h \
    colaDispenser.h \
    display.h \
    events.h \
    fsm.h \
    keyboard.h \
    subsystems.h
