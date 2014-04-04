#ifndef PARSEDREQUEST_H
#define PARSEDREQUEST_H
#include <string>

class ParsedRequest
{
public:
    ParsedRequest();
    virtual ~ParsedRequest(){}
    virtual bool isValid()=0;
    virtual std::string getField(std::string key)=0;
    virtual std::string getMethod()=0;
    virtual std::string getUrl()=0;
    virtual std::string getHttpVersion()=0;
};

#endif // PARSEDREQUEST_H
