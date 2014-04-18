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
        .WillRepeatedly(Return("/test.txt"));
rule->operateRequest(mockedParsedRequest);
}

