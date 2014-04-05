#include "responsebuilder.h"

ResponseBuilder::ResponseBuilder()
{
}

std::shared_ptr<Response> ResponseBuilder::getResponse404()
{

}

std::shared_ptr<Response> ResponseBuilder::getResponse200()
{

}

std::shared_ptr<Response> ResponseBuilder::getResponse405()
{

}

std::shared_ptr<ResponseBlank> ResponseBuilder::getResponseBlank()
{
    return std::shared_ptr<ResponseBlank>(new ResponseBlank);
}
