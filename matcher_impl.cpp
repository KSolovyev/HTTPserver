#include "matcher_impl.h"

Matcher_impl::Matcher_impl()
{
}

std::queue<std::shared_ptr<Rule> > Matcher_impl::matchRequest(std::string url)
{
    std::queue<std::shared_ptr<Rule>> matched_rules;
    for(std::shared_ptr<Rule> rule:rules)
    {
        if(rule->isMatching(url))
        matched_rules.push(rule);
    }
    return matched_rules;
}

void Matcher_impl::pushRule(std::shared_ptr<Rule> rule)
{
    rules.push_back(rule);
}

void Matcher_impl::execMatchedRules(std::shared_ptr<ParsedRequest> parsedRequest)
{
    std::queue<std::shared_ptr<Rule> > ruleQueue= matchRequest(parsedRequest->getUrl());

    while(!ruleQueue.empty())
    {
        std::shared_ptr<Rule> rule = ruleQueue.front();
        rule->operateRequest(parsedRequest);
        if(rule->isFinal())
            break;
        ruleQueue.pop();
    }
}
