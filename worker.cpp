
#include "worker.h"

Worker::Worker()
{
    sleep();
}

Worker::~Worker()
{
    //delete parsedRequestFactory;
    //delete matcher;
}

void Worker::sleep()
{

}

void Worker::run()
{
    while(1)
    {
        std::shared_ptr<Task*> task = taskQueque.waitAndPop();
        (*task)->operate(this);
    }
}

void Worker::wakeup()
{

}

void Worker::addTask(Task *task)
{
    {
        std::lock_guard<std::mutex> guard(taskQuequeBlock);
        taskQueque.push(task);
    }
    wakeup();
}

std::shared_ptr<Request> Worker::getRequest(Outputable* output)
{
    auto clIdandReq = clientIdToRequest.find(output->getClientId());
    if(clIdandReq == clientIdToRequest.end())
    {
        std::shared_ptr<Request> new_request(new Request_impl(output->getOutputBuffer()));
        clientIdToRequest.insert({{output->getClientId(),new_request}});
        return new_request;
    }
    else
    {
        return (*clIdandReq).second;
    }
}

void Worker::deleteRequest(clientId_t clientId)
{
    clientIdToRequest.erase(clientId);
}

std::shared_ptr<ParsedRequestFactory> Worker::getParsedRequestFactory()
{
    return parsedRequestFactory;
}

std::shared_ptr<Matcher> Worker::getMatcher()
{
    return matcher;
}

void Worker::useParsedRequestFactory(ParsedRequestFactory *parsedRequestFactory)
{
    this->parsedRequestFactory.reset(parsedRequestFactory);
}

void Worker::useMatcher(Matcher *matcher)
{
    this->matcher.reset(matcher);
}

int Worker::getRequestNum()
{

    return clientIdToRequest.size();
}


