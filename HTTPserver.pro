TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
LIBS += -levent

QMAKE_CXXFLAGS += -std=c++11

SOURCES += main.cpp \
    looper.cpp \
    tasker.cpp \
    worker.cpp \
    task.cpp \
    simpletask.cpp \
    getid.cpp \
    request.cpp

HEADERS += \
    looper.h \
    tasker.h \
    worker.h \
    task.h \
    allForLibevent.h \
    simpletask.h \
    getid.h \
    request.h

