#ifndef REQUEST_IMPL_H
#define REQUEST_IMPL_H
#include "allForLibevent.h"
#include "requesthasnobuffer.h"

class Request_impl : public Request
{
public:
    Request_impl(bufferevent* buf_ev);
    ~Request_impl(){}
    virtual bool isReady();
    virtual void writeBack(std::string &str);
    virtual void writeBack(const std::string &str);
    virtual std::shared_ptr<std::string> getRequestText();
    virtual void setOutputBuffer(struct bufferevent *buf_ev);
    virtual struct bufferevent* getOutputBuffer() throw(RequestHasNoBuffer);

private:
    std::shared_ptr<std::string> request;
    struct bufferevent* buf_ev;

};

#endif // REQUEST_IMPL_H
