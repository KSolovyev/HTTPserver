#ifndef DEFAULTRULE_H
#define DEFAULTRULE_H
#include "allForLibevent.h"
#include <boost/regex.hpp>
#include <boost/filesystem.hpp>

class DefaultRule : public Rule
{
public:
    DefaultRule();
    ~DefaultRule();
    virtual bool isMatching(std::string url);
    virtual bool isFinal();
    virtual void operateRequest(std::shared_ptr<ParsedRequest> parsedRequest);
private:
    void sendResponse(std::shared_ptr<ParsedRequest> parsedRequest, std::shared_ptr<Response> response);
};

#endif // DEFAULTRULE_H
