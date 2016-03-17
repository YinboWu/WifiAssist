#-------------------------------------------------
#
# Project created by QtCreator 2016-03-11T22:37:32
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = WifiAssist
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    wifi.cpp \
    wsettings.cpp \
    wdevices.cpp

HEADERS  += mainwindow.h \
    wifi.h \
    wsettings.h \
    wdevices.h

FORMS    += mainwindow.ui

DISTFILES +=

RESOURCES += \
    icon.qrc

