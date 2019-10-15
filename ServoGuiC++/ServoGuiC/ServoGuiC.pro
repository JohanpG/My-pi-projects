#-------------------------------------------------
#
# Project created by QtCreator 2013-12-06T21:53:08
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ServoGuiC
TEMPLATE = app


SOURCES += main.cpp\
        servoguic.cpp\
        servoControlC.cxx

HEADERS  += servoguic.h

FORMS    += servoguic.ui

QMAKE_CXXFLAGS += -std=c++0x

