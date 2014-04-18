#ifndef SIMPLETASK_H
#define SIMPLETASK_H
#include"allForLibevent.h"
#include "badmethod.h"
//#include "response.h"
class Worker;

class SimpleTask : public Task, public Outputable
{
public:
    SimpleTask(struct bufferevent *buf_ev);
    ~SimpleTask(){}
    virtual void operate(Worker* worker);
    virtual size_t getClientId();

    // Outputable interface
    bufferevent *getOutputBuffer();

private:
    void operateCompliteRequest(std::shared_ptr<Request> request, Worker *worker);
    struct bufferevent *buf_ev;
    getId<bufferevent> counter;

};



#endif // SIMPLETASK_H
