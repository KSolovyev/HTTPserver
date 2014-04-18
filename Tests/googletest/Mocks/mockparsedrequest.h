#ifndef MOCKPARSEDREQUEST_H
#define MOCKPARSEDREQUEST_H
#include <gmock/gmock.h>
#include <string>
#include "parsedrequest.h"

class MockParsedRequest : public ParsedRequest
{
public:
    MockParsedRequest(){}
    ~MockParsedRequest(){}
    MOCK_METHOD0(isValid, bool());
    MOCK_METHOD0(getMethod, std::string());
    MOCK_METHOD0(getUrl, std::string());
    MOCK_METHOD0(getDecodedUrl, std::string());
    MOCK_METHOD0(getHttpVersion, std::string());
    MOCK_METHOD1(getField, std::string(std::string));
    MOCK_METHOD0(getRequest, std::shared_ptr<Request>());
};

#endif // MOCKPARSEDREQUEST_H
