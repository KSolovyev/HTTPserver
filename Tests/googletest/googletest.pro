TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

QMAKE_CXXFLAGS += -std=c++11


INCLUDEPATH += /home/constantine/Google\ test/gtest-1.7.0
INCLUDEPATH += /home/constantine/Google\ test/gmock-1.7.0
INCLUDEPATH += ../../
INCLUDEPATH += ../../Exceptions/
LIBS += -L"/home/constantine/Google\ test/gtest-1.7.0/" -lgtest
LIBS += -lpthread
LIBS += -L"/home/constantine/Google\ test/gmock-1.7.0/" -lgmock
LIBS += -lboost_regex
LIBS += -levent

SOURCES += \
    gtest_main.cc \
    main.cpp \
    getidtest.cpp \
    requesttest.cpp \
    workertest.cpp \
    ../../request.cpp \
    ../../worker.cpp \
    ../../getid.cpp \
    mocktask.cpp \
    ../../task.cpp \
    ../../request_impl.cpp \
    mockrequest.cpp \
    parsedrequesttest.cpp \
    ../../parsedrequest_impl.cpp \
    ../../commonparsedrequestfactory.cpp \
    ../../Exceptions/wrongrequestformat.cpp \
    ../../Exceptions/rootexception.cpp \
    ../../Exceptions/forbiddensimbols.cpp \
    ../../Exceptions/badmethod.cpp \
    ../../parsedrequest.cpp \
    ../../settings.cpp \
    ../../parsedrequestfactory.cpp

HEADERS += \
    ../../request.h \
    ../../getid.h \
    requesttest.h \
    getidtest.h \
    ../../worker.h \
    workertest.h \
    mocktask.h \
    ../../task.h \
    ../../request_impl.h \
    mockrequest.h \
    parsedrequesttest.h \
    ../../parsedrequest_impl.h \
    ../../commonparsedrequestfactory.h \
    ../../Exceptions/wrongrequestformat.h \
    ../../Exceptions/rootexception.h \
    ../../Exceptions/forbiddensimbols.h \
    ../../Exceptions/badmethod.h \
    ../../parsedrequest.h \
    ../../settings.h \
    ../../parsedrequestfactory.h

OTHER_FILES +=

