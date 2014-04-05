#ifndef RESPONSEBUILDER_H
#define RESPONSEBUILDER_H
#include <memory>
#include <response.h>
#include <responseblank.h>

class ResponseBuilder
{
public:
    ResponseBuilder();
    std::shared_ptr<Response> getResponse404();
    std::shared_ptr<Response> getResponse200();
    std::shared_ptr<Response> getResponse405();
    std::shared_ptr<ResponseBlank> getResponseBlank();
};

#endif // RESPONSEBUILDER_H
