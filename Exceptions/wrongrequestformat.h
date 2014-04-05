#ifndef WRONGREQUESTFORMAT_H
#define WRONGREQUESTFORMAT_H
#include "rootexception.h"
#include "settings.h"

class WrongRequestFormat : public RootException
{
public:
    WrongRequestFormat(){}
    virtual const char* what() const throw(){return "Erorr: Bad request format " + getCode();}
    virtual int getCode()const {return code;}
private:
    static const int code;
};

#endif // WRONGREQUESTFORMAT_H
