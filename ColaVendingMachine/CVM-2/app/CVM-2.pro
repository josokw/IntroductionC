TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += c11

SOURCES += main.c \
    coinAcceptor.c \
    colaDispenser.c \
    changeDispenser.c \
    fsm.c \
    display.c \
    devConsole.c \
    keyboard.c \
    systemErrors.c \
    events.c \
    states.c

HEADERS += \
    appInfo.h \
    coinAcceptor.h \
    colaDispenser.h \
    changeDispenser.h \
    fsm.h \
    display.h \
    devConsole.h \
    events.h \
    keyboard.h \
    states.h \
    systemErrors.h

DISTFILES += \
   ../doc/implementation.dox \
   ../doc/mainpage.dox \
   ../doc/design.dox 
