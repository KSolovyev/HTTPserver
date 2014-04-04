#ifndef DEFAULTRULE_H
#define DEFAULTRULE_H
#include "allForLibevent.h"

class DefaultRule : public Rule
{
public:
    DefaultRule();
    ~DefaultRule();
    virtual bool isMatching(std::string url);
    virtual bool isFinal();
    virtual void operateRequest(std::shared_ptr<ParsedRequest> parsedRequest);
};

#endif // DEFAULTRULE_H
