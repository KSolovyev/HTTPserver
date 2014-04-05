#ifndef ROOTEXCEPTION_H
#define ROOTEXCEPTION_H
#include <exception>

class RootException : public std::exception
{
public:
    RootException();
    virtual ~RootException() = 0;
    virtual const char* what() const throw(){return "";}
    virtual int getCode() const =0;
};

#endif // ROOTEXCEPTION_H
