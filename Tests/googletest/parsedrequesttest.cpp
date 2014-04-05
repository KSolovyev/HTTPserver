#include "parsedrequesttest.h"

class ParsedRequestTest: public testing::Test
{
public:
    void SetUp()
    {
        std::shared_ptr<ParsedRequestFactory> tmp(new CommonParsedRequestFactory);
        factory = std::move(tmp);
        std::shared_ptr<std::string> tmp2 (new std::string("GET /someurl/somefile.jpg HTTP/1.1\nHOST: localhost\n\n"));
        request = std::move(tmp2);

    }

    void TearDown()
    {
    }
    std::shared_ptr<ParsedRequestFactory> factory;
    std::shared_ptr<std::string> request;

};

using ::testing::Return;

TEST_F(ParsedRequestTest, FactoryTest)
{
    std::shared_ptr<MockRequest> mockRequestRef(new MockRequest);
    EXPECT_CALL((*mockRequestRef), getRequestText())
            .Times(1)
            .WillRepeatedly(Return((request)));

    std::shared_ptr<ParsedRequest> parsedRequest(factory->getParsedRequest(mockRequestRef));

    ASSERT_TRUE((bool)parsedRequest);


}

TEST_F(ParsedRequestTest, FunctionalityTest)
{
    std::shared_ptr<MockRequest> mockRequestRef(new MockRequest);
    EXPECT_CALL((*mockRequestRef), getRequestText())
            .Times(1)
            .WillRepeatedly(Return((request)));

    std::shared_ptr<ParsedRequest> parsedRequest(factory->getParsedRequest(mockRequestRef));

    ASSERT_EQ(parsedRequest->getMethod(),"GET");
    ASSERT_EQ(parsedRequest->getUrl(),"/someurl/somefile.jpg");
    ASSERT_EQ(parsedRequest->getHttpVersion(),"1.1");
    ASSERT_EQ(parsedRequest->getField("HOST"),"localhost");

}
