TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += c11

SOURCES += main.c \
    TUI.c \
    fsm.c \
    display.c \
    coinAcceptor.c \
    changeDispenser.c \
    colaDispenser.c \
    keyboard.c \
    systemErrors.c \
    events.c

HEADERS += \
    TUI.h \
    appInfo.h \
    fsm.h \
    display.h \
    coinAcceptor.h \
    changeDispenser.h \
    events.h \
    colaDispenser.h \
    keyboard.h \
    states.h \
    systemErrors.h
