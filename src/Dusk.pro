#-------------------------------------------------
#
# Project created by QtCreator 2016-07-04T20:55:36
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Dusk
TEMPLATE = app


SOURCES += main.cpp\
        Dusk.cpp \
    ColorSwitcher.cpp \
    BlackWindow.cpp

HEADERS  += Dusk.h \
    ColorSwitcher.h \
    BlackWindow.h

FORMS    += Dusk.ui

RESOURCES += \
    icons.qrc

RC_FILE = Dusk.rc
