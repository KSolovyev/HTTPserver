#ifndef BADMETHOD_H
#define BADMETHOD_H
#include "rootexception.h"
#include "settings.h"

class BadMethod : public RootException
{
public:
    BadMethod(){}
    ~BadMethod(){}
    virtual const char* what() const throw(){return "Erorr: Bad Method " + getCode();}
    virtual int getCode()const {return code;}
private:
    static const int code;
};

#endif // BADMETHOD_H
