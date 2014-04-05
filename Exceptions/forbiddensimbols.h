#ifndef FORBIDDENSIMBOLS_H
#define FORBIDDENSIMBOLS_H
#include "rootexception.h"
#include "settings.h"

class ForbiddenSimbols : public RootException
{
public:
    ForbiddenSimbols(){}
    ~ForbiddenSimbols(){}
    virtual const char* what() const throw(){return "Erorr: Bad simbols in request " + getCode();}
    virtual int getCode()const {return code;}
private:
    static const int code;
};

#endif // FORBIDDENSIMBOLS_H
