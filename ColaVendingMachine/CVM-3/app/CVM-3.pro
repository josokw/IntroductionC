TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += c11

SOURCES += main.c \
    TUI.c \
    coinAcceptor.c \
    colaDispenser.c \
    changeDispenser.c \
    fsm.c \
    display.c \
    keyboard.c \
    systemErrors.c \
    events.c

HEADERS += \
    TUI.h \
    appInfo.h \
    coinAcceptor.h \
    colaDispenser.h \
    changeDispenser.h \
    fsm.h \
    display.h \
    events.h \
    keyboard.h \
    states.h \
    systemErrors.h
