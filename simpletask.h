#ifndef SIMPLETASK_H
#define SIMPLETASK_H
#include"allForLibevent.h"

class SimpleTask : public Task
{
public:
    SimpleTask(struct bufferevent *buf_ev);
    void operate(Worker* worker);
    size_t getClientId();
private:
    struct bufferevent *buf_ev;
    static getId<bufferevent> counter;
};

getId<bufferevent> SimpleTask::counter;

#endif // SIMPLETASK_H
