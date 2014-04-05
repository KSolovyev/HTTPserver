TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

QMAKE_CXXFLAGS += -std=c++11


INCLUDEPATH += /home/constantine/Google\ test/gtest-1.7.0
INCLUDEPATH += /home/constantine/Google\ test/gmock-1.7.0
INCLUDEPATH += ../../
INCLUDEPATH += ../../Exceptions/
INCLUDEPATH += Mocks/
INCLUDEPATH += ../../Responses/
LIBS += -L"/home/constantine/Google\ test/gtest-1.7.0/" -lgtest
LIBS += -lpthread
LIBS += -L"/home/constantine/Google\ test/gmock-1.7.0/" -lgmock
LIBS += -lboost_regex
LIBS += -levent
LIBS += -lboost_filesystem
LIBS += -lboost_system
LIBS += -lboost_date_time

SOURCES += \
    gtest_main.cc \
    main.cpp \
    getidtest.cpp \
    requesttest.cpp \
    matchertest.cpp \
    workertest.cpp \
    ../../request.cpp \
    ../../worker.cpp \
    ../../getid.cpp \
    Mocks/mocktask.cpp \
    ../../task.cpp \
    ../../request_impl.cpp \
    Mocks/mockrequest.cpp \
    parsedrequesttest.cpp \
    ../../parsedrequest_impl.cpp \
    ../../commonparsedrequestfactory.cpp \
    ../../Exceptions/wrongrequestformat.cpp \
    ../../Exceptions/rootexception.cpp \
    ../../Exceptions/forbiddensimbols.cpp \
    ../../Exceptions/badmethod.cpp \
    ../../parsedrequest.cpp \
    ../../settings.cpp \
    ../../parsedrequestfactory.cpp \
    Mocks/mockrule.cpp \
    ../../matcher_impl.cpp \
    ../../matcher.cpp \
    Mocks/mockparsedrequest.cpp \
    responseblanktest.cpp \
    ../../Responses/responseblank.cpp \
    ../../Responses/response.cpp \
    ../../Exceptions/badresponse.cpp \
    ../../Exceptions/requesthasnobuffer.cpp \
    ../../Responses/responsebuilder.cpp

HEADERS += \
    ../../request.h \
    ../../getid.h \
    requesttest.h \
    matchertest.h \
    getidtest.h \
    ../../worker.h \
    workertest.h \
    Mocks/mocktask.h \
    ../../task.h \
    ../../request_impl.h \
    Mocks/mockrequest.h \
    parsedrequesttest.h \
    ../../parsedrequest_impl.h \
    ../../commonparsedrequestfactory.h \
    ../../Exceptions/wrongrequestformat.h \
    ../../Exceptions/rootexception.h \
    ../../Exceptions/forbiddensimbols.h \
    ../../Exceptions/badmethod.h \
    ../../parsedrequest.h \
    ../../settings.h \
    ../../parsedrequestfactory.h \
    Mocks/mockrule.h \
    ../../matcher_impl.h \
    ../../matcher.h \
    Mocks/mockparsedrequest.h \
    responseblanktest.h \
    ../../Responses/responseblank.h \
    ../../Responses/response.h \
    ../../Exceptions/badresponse.h \
    ../../Exceptions/requesthasnobuffer.h \
    ../../Responses/responsebuilder.h

OTHER_FILES +=

