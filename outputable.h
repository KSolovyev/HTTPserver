#ifndef OUTPUTABLE_H
#define OUTPUTABLE_H
#include <event2/bufferevent.h>
class Outputable
{
public:
    Outputable(){}
    virtual ~Outputable(){}
    virtual bufferevent* getOutputBuffer() = 0;
    virtual size_t getClientId()=0;
};

#endif // OUTPUTABLE_H
