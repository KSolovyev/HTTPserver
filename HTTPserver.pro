TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
LIBS += -levent
LIBS += -lboost_regex
LIBS += -lboost_filesystem
LIBS += -lboost_system
LIBS += -lboost_date_time

INCLUDEPATH += ./Exceptions/
INCLUDEPATH += ./Responses/
QMAKE_CXXFLAGS += -std=c++11

SOURCES += main.cpp \
    looper.cpp \
    tasker.cpp \
    worker.cpp \
    task.cpp \
    simpletask.cpp \
    getid.cpp \
    request.cpp \
    threadsafe_queque.cpp \
    settings.cpp \
    rule.cpp \
    Responses/response.cpp \
    request_impl.cpp \
    parsedrequest_impl.cpp \
    parsedrequestfactory.cpp \
    matcher_impl.cpp \
    matcher.cpp \
    defaultrule.cpp \
    commonparsedrequestfactory.cpp \
    Exceptions/wrongrequestformat.cpp \
    Exceptions/rootexception.cpp \
    Exceptions/forbiddensimbols.cpp \
    Exceptions/badmethod.cpp \
    parsedrequest.cpp \
    Exceptions/requesthasnobuffer.cpp \
    outputable.cpp \
    Responses/responsebuilder.cpp \
    Responses/responseblank.cpp \
    Exceptions/badresponse.cpp

HEADERS += \
    looper.h \
    tasker.h \
    worker.h \
    task.h \
    allForLibevent.h \
    simpletask.h \
    getid.h \
    request.h \
    threadsafe_queque.h \
    settings.h \
    rule.h \
    Responses/response.h \
    request_impl.h \
    parsedrequest_impl.h \
    parsedrequestfactory.h \
    matcher_impl.h \
    matcher.h \
    defaultrule.h \
    commonparsedrequestfactory.h \
    Exceptions/wrongrequestformat.h \
    Exceptions/rootexception.h \
    Exceptions/forbiddensimbols.h \
    Exceptions/badmethod.h \
    parsedrequest.h \
    Exceptions/requesthasnobuffer.h \
    outputable.h \
    Responses/responsebuilder.h \
    Responses/responseblank.h \
    Exceptions/badresponse.h

OTHER_FILES +=


