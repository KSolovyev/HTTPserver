#ifndef RULE_H
#define RULE_H
#include "parsedrequest.h"
#include "responsebuilder.h"
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
    ResponseBuilder* getResponseBuilder(){return &responseBuilder;}

private:
    static ResponseBuilder responseBuilder;

};

#endif // RULE_H


