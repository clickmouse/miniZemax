#-------------------------------------------------
#
# Project created by QtCreator 2019-07-08T11:21:19
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = miniZemax
TEMPLATE = app


SOURCES += main.cpp \
    miniZemax.cpp \
    Light.cpp \
    Optics.cpp

HEADERS  += \
    miniZemax.h \
    Light.h \
    Optics.h

FORMS    += \
    miniZemax.ui

RESOURCES += \
    icon.qrc

DISTFILES += \
    icon.rc
RC_FILE += icon.rc

