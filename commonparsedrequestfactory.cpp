#include "commonparsedrequestfactory.h"

CommonParsedRequestFactory::CommonParsedRequestFactory()
{
}

ParsedRequest *CommonParsedRequestFactory::getParsedRequest(std::shared_ptr<Request> request)
{
    return new ParsedRequest_impl(request);
}
