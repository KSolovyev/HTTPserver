#include "matchertest.h"
#include "matcher.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "mockrequest.h"
#include "matcher_impl.h"
#include "mockrule.h"

class MatcherTest: public testing::Test
{
public:
    void SetUp()
    {
        rule1.reset(new MockRule);
        rule2.reset(new MockRule);
        matcher = new Matcher_impl;
        mockedParsedRequest.reset(new MockParsedRequest);
    }
    void TearDown()
    {
        delete matcher;
    }
    std::shared_ptr<MockRule> rule1;
    std::shared_ptr<MockRule> rule2;
    std::shared_ptr<MockParsedRequest> mockedParsedRequest;

    Matcher *matcher;

};

using ::testing::Return;
using ::testing::_;

TEST_F(MatcherTest, CreationTest)
{
    ASSERT_TRUE(matcher);
    matcher->pushRule(rule1);
}

TEST_F(MatcherTest, FunctionalityTest)
{
    EXPECT_CALL(*rule1, isMatching(_))
            .WillOnce(Return(true))
            .WillRepeatedly(Return(false));
    EXPECT_CALL(*rule1, isFinal())
            .WillRepeatedly(Return(false));

    EXPECT_CALL(*rule2, isMatching(_))
            .WillRepeatedly(Return(true));
    EXPECT_CALL(*rule2, isFinal())
            .WillRepeatedly(Return(true));

    matcher->pushRule(rule2);
    matcher->pushRule(rule1);

    EXPECT_CALL(*mockedParsedRequest, getUrl())
            .WillOnce(Return("/SomeUrl/"))
            .WillRepeatedly(Return("/AnotherUrl/"));

    EXPECT_CALL(*rule1, operateRequest(_))
            .Times(1);

    EXPECT_CALL(*rule2, operateRequest(_))
            .Times(2);

    matcher->execMatchedRules(mockedParsedRequest);
    matcher->execMatchedRules(mockedParsedRequest);

}

