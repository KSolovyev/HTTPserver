#include "simpletask.h"


SimpleTask::SimpleTask(bufferevent *buf_ev)
{
    this->buf_ev = buf_ev;
}

void SimpleTask::operate(Worker *worker)
{

    std::shared_ptr<Request> request = worker->getRequest(this);
    char tmp[128];
    std::string tmp_;
    size_t n;
    while (1) {
            n = bufferevent_read(buf_ev, tmp, sizeof(tmp));
            if (n <= 0)
                    break; /* No more data. */
            tmp_ = tmp;
            request->writeBack(tmp_);


    }
    if (request->isReady())
    {
        operateCompliteRequest(request, worker);
    }


}

void SimpleTask::operateCompliteRequest(std::shared_ptr<Request> request, Worker *worker)
{
    ParsedRequestFactory *requestFactory = worker->getParsedRequestFactory();
    std::shared_ptr<ParsedRequest> parsedRequest(requestFactory->getParsedRequest(request));

}

void SimpleTask::sendResponse(Response* response)
{
    
}

size_t SimpleTask::getClientId()
{
    return counter(buf_ev);
}

bufferevent *SimpleTask::getOutputBuffer()
{
    return buf_ev;
}
