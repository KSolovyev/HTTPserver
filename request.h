#ifndef REQUEST_H
#define REQUEST_H
#include<string>
#include<memory>
#include"allForLibevent.h"

class Request
{
public:
    Request();
    ~Request();
    bool isReady();
    void writeBack(std::string&);
    std::shared_ptr<std::string> getRequestText();

private:
    std::shared_ptr<std::string> request;

};

#endif // REQUEST_H
