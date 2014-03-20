TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
QMAKE_CXXFLAGS += -std=c++11
LIBS += -lunittest++
SOURCES += main.cpp \
    getIdTest.cpp \
    RequestTest.cpp \
    WorkerTest.cpp

HEADERS += \
    testTask.h

