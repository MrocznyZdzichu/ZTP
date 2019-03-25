#-------------------------------------------------
#
# Project created by QtCreator 2019-03-10T18:00:04
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = komfortoweKino
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    qcustomplot.cpp \
    Interface.cpp

HEADERS  += mainwindow.h \
    qcustomplot.h \
    Interface.h

FORMS    += mainwindow.ui
