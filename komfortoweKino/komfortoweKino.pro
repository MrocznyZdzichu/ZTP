#-------------------------------------------------
#
# Project created by QtCreator 2019-03-10T18:00:04
#
#-------------------------------------------------

QT       += core gui
CONFIG += c++11
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = komfortoweKino
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    qcustomplot.cpp \
    Interface.cpp \
    Component.cpp \
    Human.cpp \
    vent.cpp \
    ac.cpp \
    building.cpp \
    inputdata.cpp

HEADERS  += mainwindow.h \
    qcustomplot.h \
    Interface.h \
    Component.h \
    Human.h \
    vent.h \
    ac.h \
    building.h \
    inputdata.h

FORMS    += mainwindow.ui
