#ifndef RULE_H
#define RULE_H
#include "parsedrequest.h"
#include <string>
#include <memory>

class Rule
{
public:
    Rule(){}
    virtual ~Rule(){}
    virtual bool isMatching(std::string URL) = 0;
    virtual bool isFinal()=0;
    virtual void operateRequest(std::shared_ptr<ParsedRequest> parsedRequest) = 0;
};

#endif // RULE_H


