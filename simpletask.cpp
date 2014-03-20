#include "simpletask.h"



SimpleTask::SimpleTask(bufferevent *buf_ev)
{
    this->buf_ev = buf_ev;
}

void SimpleTask::operate(Worker *worker)
{

    Request *request = worker->getRequest(getClientId());
    char tmp[128];
    size_t n;
    int i;
    while (1) {
            n = bufferevent_read(bev, tmp, sizeof(tmp));
            if (n <= 0)
                    break; /* No more data. */
            request->writeBack(tmp);

    }



}

size_t SimpleTask::getClientId()
{
    return counter(buf_ev);
}
