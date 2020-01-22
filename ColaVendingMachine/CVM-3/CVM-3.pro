TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += c11

SOURCES += main.c \
    changeDispenser.c \
    coinAcceptor.c \
    colaDispenser.c \
    display.c \
    keyboard.c

HEADERS += \
    changeDispenser.h \
    coinAcceptor.h \
    colaDispenser.h \
    display.h \
    events.h \
    fsm.h \
    keyboard.h
