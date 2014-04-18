#include "request_impl.h"



Request_impl::Request_impl(bufferevent *buf_ev):request(std::make_shared<std::string>(*(new std::string()))), buf_ev(buf_ev)
{

}

bool Request_impl::isReady()
{

    //return request->substr(request->length()-2)=="\r\n";
    return true;
}

void Request_impl::writeBack(std::string &str)
{
    request->append(str);

}

void Request_impl::writeBack(const std::string &str)
{
    request->append(str);

}

std::shared_ptr<std::string> Request_impl::getRequestText()
{
    return request;
}

void Request_impl::setOutputBuffer(bufferevent *buf_ev)
{
    this->buf_ev = buf_ev;
}

bufferevent *Request_impl::getOutputBuffer()
{
    return buf_ev;
}
