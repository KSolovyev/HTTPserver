#ifndef COMMONPARSEDREQUESTFACTORY_H
#define COMMONPARSEDREQUESTFACTORY_H
#include "allForLibevent.h"

class CommonParsedRequestFactory : public ParsedRequestFactory
{
public:
    CommonParsedRequestFactory();
     virtual ParsedRequest* getParsedRequest(std::shared_ptr<Request> request);
    ~CommonParsedRequestFactory(){}
};

#endif // COMMONPARSEDREQUESTFACTORY_H
