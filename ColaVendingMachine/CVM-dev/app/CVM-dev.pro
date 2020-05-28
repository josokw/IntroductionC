TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += c11

SOURCES += main.c \
    fsm.c \
    display.c \
    devConsole.c \
    files.c \
    coinAcceptor.c \
    changeDispenser.c \
    colaDispenser.c \
    keyboard.c \
    systemErrors.c \
    states.c \
    events.c

HEADERS += \
    appInfo.h \
    fsm.h \
    display.h \
    devConsole.h \
    files.h \
    coinAcceptor.h \
    changeDispenser.h \
    events.h \
    colaDispenser.h \
    keyboard.h \
    states.h \
    systemErrors.h

DISTFILES += \
   ../doc/implementation.dox \
   ../doc/mainpage.dox \
   ../doc/design.dox
