#ifndef MATCHER_IMPL_H
#define MATCHER_IMPL_H
#include "allForLibevent.h"
#include <list>


class Matcher_impl : public Matcher
{
public:
    Matcher_impl();
    virtual void pushRule(std::shared_ptr<Rule> rule);
    virtual void execMatchedRules(std::shared_ptr<ParsedRequest> parsedRequest);

private:
    std::queue<std::shared_ptr<Rule>> matchRequest(std::string url);
    std::list<std::shared_ptr<Rule>> rules;
};

#endif // MATCHER_IMPL_H
