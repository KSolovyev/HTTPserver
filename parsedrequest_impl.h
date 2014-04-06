#ifndef PARSEDREQUEST_IMPL_H
#define PARSEDREQUEST_IMPL_H
#include "allForLibevent.h"
#include "boost/regex.hpp"
#include "badmethod.h"
#include "forbiddensimbols.h"
#include "wrongrequestformat.h"



class ParsedRequest_impl : public ParsedRequest
{
public:
    bool isValid(){return valid;}
    ParsedRequest_impl(std::shared_ptr<Request> request);
    ~ParsedRequest_impl(){}
    std::string getField(std::string key);
    std::string getMethod();
    std::string getUrl();
    std::string getHttpVersion();
    std::shared_ptr<Request> getRequest();
private:
    void parse()throw(WrongRequestFormat);
    void validate() throw (BadMethod, ForbiddenSimbols);
    bool valid;
    int errorCode;
    std::shared_ptr<Request> request;
    std::string method;
    std::string url;
    std::string http_version;
    std::unordered_map<std::string,std::string> requestFields;
};

#endif // PARSEDREQUEST_IMPL_H
