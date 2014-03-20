#include "request.h"

Request::Request():request(new string(""))
{
}

bool Request::isReady()
{
    return true;
}

void Request::writeBack(std::string &s)
{
    request->append(s);

}

std::shared_ptr<std::string> Request::getRequestText()
{
    return request;
}
