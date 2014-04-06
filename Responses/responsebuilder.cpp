#include "responsebuilder.h"

ResponseBuilder::ResponseBuilder()
{
    response200.reset(new ResponseBlank);
    response200->setConnection("close");
    response200->setHttpVersion("1.1");
    response200->setServer("HighLoadServer.0.1");
    response200->setResponseCode("200 OK");

    response400.reset(new ResponseBlank);

    response405.reset(new ResponseBlank);

    response404.reset(new ResponseBlank);


}

std::shared_ptr<ResponseBlank> ResponseBuilder::getResponse404()
{
    std::shared_ptr<ResponseBlank> response(new ResponseBlank);
    *response = *response404;

    return response;
}

std::shared_ptr<ResponseBlank> ResponseBuilder::getResponse200()
{
std::shared_ptr<ResponseBlank> response(new ResponseBlank);
*response = *response200;

return response;
}

std::shared_ptr<ResponseBlank> ResponseBuilder::getResponse405()
{
    std::shared_ptr<ResponseBlank> response(new ResponseBlank);
    *response = *response405;

    return response;
}

std::shared_ptr<ResponseBlank> ResponseBuilder::getResponseBlank()
{
    return std::shared_ptr<ResponseBlank>(new ResponseBlank);
}
std::shared_ptr<ResponseBlank> ResponseBuilder::getResponse403() const
{
    return response403;
}



