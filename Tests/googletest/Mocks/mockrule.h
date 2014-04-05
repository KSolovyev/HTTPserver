#ifndef MOCKRULE_H
#define MOCKRULE_H
#include "rule.h"
#include <string>
#include <memory>
#include "parsedrequest.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>


class MockRule : public Rule
{
public:
    MockRule(){}
    ~MockRule(){}
    MOCK_METHOD0(isFinal, bool());
    MOCK_METHOD1(isMatching, bool(std::string));
    MOCK_METHOD1(operateRequest, void(std::shared_ptr<ParsedRequest>));
};

#endif // MOCKRULE_H
