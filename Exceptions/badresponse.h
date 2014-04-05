#ifndef BADRESPONSE_H
#define BADRESPONSE_H
#include "rootexception.h"
#include "settings.h"
#include <string>

class BadResponse : public RootException
{
public:
    BadResponse(std::string msg):msg(msg){}
    ~BadResponse(){}
    virtual const char* what() const throw(){return ("Erorr: Bad Response: " +msg + std::to_string(getCode())).c_str();}
    virtual int getCode()const {return code;}
private:
    static const int code;
    const std::string msg;
};




#endif // BADRESPONSE_H
