#ifndef REQUEST_H
#define REQUEST_H
#include<string>
#include<memory>
#include <event2/bufferevent.h>


class Request
{
public:
    Request(){}
    virtual ~Request(){}
    virtual bool isReady()=0;
    virtual void writeBack(std::string &str)=0;
    virtual void writeBack(const std::string &str)=0;
    virtual std::shared_ptr<std::string> getRequestText()=0;
    virtual void setOutputBuffer(struct bufferevent *buf_ev) = 0;
    virtual struct bufferevent* getOutputBuffer() = 0;

};

#endif // REQUEST_H
