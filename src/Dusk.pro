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
    Overlay.cpp \
    BlackOverlay.cpp \
    IdentityOverlay.cpp \
    CheckBox.cpp

HEADERS  += Dusk.h \
    Overlay.h \
    BlackOverlay.h \
    IdentityOverlay.h \
    CheckBox.h

FORMS    += Dusk.ui

RESOURCES += \
    icons.qrc

RC_FILE = Dusk.rc
