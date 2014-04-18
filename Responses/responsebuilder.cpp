#include "responsebuilder.h"

ResponseBuilder::ResponseBuilder()
{
    response200.reset(new ResponseBlank);
    response200->setConnection("close");
    response200->setHttpVersion("1.1");
    response200->setServer("HighLoadServer.0.1");
    response200->setResponseCode("200 OK");

    response400.reset(new ResponseBlank);
    response400->setConnection("close");
    response400->setHttpVersion("1.1");
    response400->setServer("HighLoadServer.0.1");
    response400->setResponseCode("400 Bad Request");

    response403.reset(new ResponseBlank);
    response403->setConnection("close");
    response403->setHttpVersion("1.1");
    response403->setServer("HighLoadServer.0.1");
    response403->setResponseCode("403 Forbidden");

    response405.reset(new ResponseBlank);
    response405->setConnection("close");
    response405->setHttpVersion("1.1");
    response405->setServer("HighLoadServer.0.1");
    response405->setResponseCode("405 Method Not Allowed");

    response404.reset(new ResponseBlank);
    response404->setConnection("close");
    response404->setHttpVersion("1.1");
    response404->setServer("HighLoadServer.0.1");
    response404->setResponseCode("404 Not Found");


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
std::shared_ptr<ResponseBlank> ResponseBuilder::getResponse403()
{
    return response403;
}



