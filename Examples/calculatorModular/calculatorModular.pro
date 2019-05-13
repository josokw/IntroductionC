TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

QMAKE_CFLAGS += -std=c11

SOURCES += main.c \
   calculator.c

HEADERS += \
   calculator.h \
   AppInfo.h
