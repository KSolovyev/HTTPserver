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
    std::string getDecodedUrl();
    std::string getHttpVersion();
    std::shared_ptr<Request> getRequest();
private:
    std::string UriDecode(const std::string & sSrc);
    void parse()throw(WrongRequestFormat);
    void validate() throw (BadMethod, ForbiddenSimbols);
    bool valid;
    int errorCode;
    std::shared_ptr<Request> request;
    std::string method;
    std::string url;
    std::string http_version;
    std::unordered_map<std::string,std::string> requestFields;
    const char HEX2DEC[256] =
    {
        /*       0  1  2  3   4  5  6  7   8  9  A  B   C  D  E  F */
        /* 0 */ -1,-1,-1,-1, -1,-1,-1,-1, -1,-1,-1,-1, -1,-1,-1,-1,
        /* 1 */ -1,-1,-1,-1, -1,-1,-1,-1, -1,-1,-1,-1, -1,-1,-1,-1,
        /* 2 */ -1,-1,-1,-1, -1,-1,-1,-1, -1,-1,-1,-1, -1,-1,-1,-1,
        /* 3 */  0, 1, 2, 3,  4, 5, 6, 7,  8, 9,-1,-1, -1,-1,-1,-1,

        /* 4 */ -1,10,11,12, 13,14,15,-1, -1,-1,-1,-1, -1,-1,-1,-1,
        /* 5 */ -1,-1,-1,-1, -1,-1,-1,-1, -1,-1,-1,-1, -1,-1,-1,-1,
        /* 6 */ -1,10,11,12, 13,14,15,-1, -1,-1,-1,-1, -1,-1,-1,-1,
        /* 7 */ -1,-1,-1,-1, -1,-1,-1,-1, -1,-1,-1,-1, -1,-1,-1,-1,

        /* 8 */ -1,-1,-1,-1, -1,-1,-1,-1, -1,-1,-1,-1, -1,-1,-1,-1,
        /* 9 */ -1,-1,-1,-1, -1,-1,-1,-1, -1,-1,-1,-1, -1,-1,-1,-1,
        /* A */ -1,-1,-1,-1, -1,-1,-1,-1, -1,-1,-1,-1, -1,-1,-1,-1,
        /* B */ -1,-1,-1,-1, -1,-1,-1,-1, -1,-1,-1,-1, -1,-1,-1,-1,

        /* C */ -1,-1,-1,-1, -1,-1,-1,-1, -1,-1,-1,-1, -1,-1,-1,-1,
        /* D */ -1,-1,-1,-1, -1,-1,-1,-1, -1,-1,-1,-1, -1,-1,-1,-1,
        /* E */ -1,-1,-1,-1, -1,-1,-1,-1, -1,-1,-1,-1, -1,-1,-1,-1,
        /* F */ -1,-1,-1,-1, -1,-1,-1,-1, -1,-1,-1,-1, -1,-1,-1,-1
    };
};

#endif // PARSEDREQUEST_IMPL_H
