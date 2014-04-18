#include "defaultruletest.h"

class DefaultRuleTest: public testing::Test
{
public:
    void SetUp()
    {
        rule = new DefaultRule();
        mockedParsedRequest.reset(new MockParsedRequest);
    }

    void TearDown()
    {
        delete rule;
    }
    Rule* rule;
    std::shared_ptr<MockParsedRequest> mockedParsedRequest;
};


using ::testing::Return;



TEST_F(DefaultRuleTest, CreationTest)
{
    ASSERT_TRUE(rule);
}


TEST_F(DefaultRuleTest, OperateResponseTest)
{
EXPECT_CALL(*mockedParsedRequest, getUrl())
        .WillRepeatedly(Return("/httptest/space%20in name.txt"));
EXPECT_CALL(*mockedParsedRequest, getDecodedUrl())
        .WillRepeatedly(Return("/httptest/space in name.txt"));
EXPECT_CALL(*mockedParsedRequest, getMethod())
        .WillRepeatedly(Return("GET"));
rule->operateRequest(mockedParsedRequest);
}

TEST_F(DefaultRuleTest, boostPathTest)
{
    std::string pathStr1="/home/constantine/HTTProot";
    std::string pathStr2="/home/constantine/HTTProot/../../../../../../../../home/constantine/HTTProot/../HTTPserver";
    boost::regex escape_re("\/?[^\/^(..)]*/../");
    boost::smatch match;


    while(boost::regex_search(pathStr2,match,escape_re))
        pathStr2=boost::regex_replace(pathStr2,escape_re,"/");

    boost::filesystem::path path1(pathStr1);
    boost::filesystem::path path2(pathStr2);
    int i1 = path2.compare(path1);
    std::cout<<i1;

}
