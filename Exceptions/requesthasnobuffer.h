#ifndef REQUESTHASNOBUFFER_H
#define REQUESTHASNOBUFFER_H
#include "rootexception.h"
#include "settings.h"

class RequestHasNoBuffer : public RootException
{
public:
    RequestHasNoBuffer(){}
    ~RequestHasNoBuffer(){}
    virtual const char* what() const throw(){return "Erorr: Bad simbols in request " + getCode();}
    virtual const int getCode()const {return code;}
private:
    static const int code;
};

#endif // REQUESTHASNOBUFFER_H
