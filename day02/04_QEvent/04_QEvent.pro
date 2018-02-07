#-------------------------------------------------
#
# Project created by QtCreator 2018-02-05T22:01:54
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 04_QEvent
TEMPLATE = app


SOURCES += main.cpp\
        mywidget.cpp \
    mylabel.cpp \
    mybutton.cpp

HEADERS  += mywidget.h \
    mylabel.h \
    mybuttnon.h \
    mybutton.h

FORMS    += mywidget.ui

CONFIG += c++11
