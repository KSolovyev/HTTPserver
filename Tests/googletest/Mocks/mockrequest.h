#ifndef MOCKREQUEST_H
#define MOCKREQUEST_H
#include "request.h"
#include "gmock/gmock.h"
#include "event2/bufferevent.h"
#include <string>
#include <memory>

class MockRequest : public Request
{
public:
    MockRequest(){}
    ~MockRequest(){}
    MOCK_METHOD0(isReady, bool());
    MOCK_METHOD1(writeBack, void(std::string&));
    MOCK_METHOD1(writeBack, void(const std::string&));
    MOCK_METHOD0(getRequestText, std::shared_ptr<std::string>());
    MOCK_METHOD1(setOutputBuffer, void( bufferevent*));
    MOCK_METHOD0(getOutputBuffer, bufferevent*());

};

#endif // MOCKREQUEST_H
