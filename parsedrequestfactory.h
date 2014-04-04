#ifndef PARSEDREQUESTFACTORY_H
#define PARSEDREQUESTFACTORY_H
//#include "allForLibevent.h"
#include <memory>

class ParsedRequest;
class Request;

class ParsedRequestFactory
{
public:
    ParsedRequestFactory();
    virtual ParsedRequest* getParsedRequest(std::shared_ptr<Request> request) = 0;
    virtual ~ParsedRequestFactory(){}
};

#endif // PARSEDREQUESTFACTORY_H
