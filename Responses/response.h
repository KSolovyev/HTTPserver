#ifndef RESPONSE_H
#define RESPONSE_H
#include <string>
#include <memory>

class Response
{
public:
    Response();
    virtual std::shared_ptr<std::string> getHeaderText()=0;
    virtual std::shared_ptr<std::string> getContentText()=0;
};

#endif // RESPONSE_H
