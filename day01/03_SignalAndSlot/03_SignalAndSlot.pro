#-------------------------------------------------
#
# Project created by QtCreator 2018-01-22T00:09:32
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 03_SignalAndSlot
TEMPLATE = app


SOURCES += main.cpp\
        mainwidget.cpp \
    subwidget.cpp

HEADERS  += mainwidget.h \
    subwidget.h

CONFIG += C++11
