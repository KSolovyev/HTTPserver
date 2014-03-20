#-------------------------------------------------
#
# Project created by QtCreator 2014-03-14T22:12:41
#
#-------------------------------------------------

QT       += testlib

QT       -= gui

TARGET = tst_getidtest
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

QMAKE_CXXFLAGS += -std=c++11

SOURCES += tst_getidtest.cpp \
    ../../getid.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"

HEADERS += \
    ../../getid.h
