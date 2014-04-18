#ifndef PARSEDREQUEST_H
#define PARSEDREQUEST_H
#include <string>
#include <memory>
#include "request.h"
class ParsedRequest
{
public:
    ParsedRequest();
    virtual ~ParsedRequest(){}
    virtual bool isValid()=0;
    virtual std::string getField(std::string key)=0;
    virtual std::string getMethod()=0;
    virtual std::string getUrl()=0;
    virtual std::string getDecodedUrl()=0;
    virtual std::string getHttpVersion()=0;
    virtual std::shared_ptr<Request> getRequest() = 0;
};

#endif // PARSEDREQUEST_H
