TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += c11

SOURCES += main.c \
    TUI.c \
    coinAcceptor.c \
    colaDispenser.c \
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
    fsm.h \
    display.h \
    events.h \
    keyboard.h \
    states.h \
    systemErrors.h

DISTFILES += \
   ../doc/implementation.dox \
   ../doc/mainpage.dox \
   ../doc/design.dox 
