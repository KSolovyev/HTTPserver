#include "requesttest.h"


class RequestTest: public testing::Test{
public:
    void SetUp(){
            firstPiece = "GET /index.html";
            secondPiece = " HTTP/1.1\n\n";
            overallPiece=firstPiece + secondPiece;
            request = new Request_impl(NULL);
        }
    void TearDown(){}
        std::string firstPiece;
        std::string secondPiece;
        std::string overallPiece;
        Request* request;
};



TEST_F(RequestTest,RequestFunctionalTest)
{
    request->writeBack(firstPiece);
    ASSERT_TRUE(!request->isReady());
    EXPECT_EQ(firstPiece,*(request->getRequestText()));
    request->writeBack(secondPiece);
    ASSERT_TRUE(request->isReady());
    EXPECT_EQ(overallPiece,*(request->getRequestText()));
}
