#ifndef MATCHER_H
#define MATCHER_H
//#include "allForLibevent.h"
#include <queue>
#include <memory>
#include <string>
#include "rule.h"

class Matcher
{
public:
    Matcher(){}
    virtual ~Matcher() =0;
//    virtual std::queue<std::shared_ptr<Rule>> matchRequest(std::string URL)=0;
    virtual void pushRule(std::shared_ptr<Rule> rule) = 0;
    virtual void execMatchedRules(std::shared_ptr<ParsedRequest> ParsedRequest) = 0;
};

#endif // MATCHER_H
