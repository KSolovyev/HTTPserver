
#include "worker.h"

Worker::Worker()
{
    sleep();
}

void Worker::sleep()
{

}

void Worker::run()
{

    for(auto it = taskQueque.begin();it<taskQueque.end();)
    {
        (*it)->operate(this);
        {
            std::lock_guard<std::mutex> guard(taskQuequeBlock);
            taskQueque.erase(it);
        }
        it++;
    }
}

void Worker::wakeup()
{

}

void Worker::addTask(Task *task)
{
    {
        std::lock_guard<std::mutex> guard(taskQuequeBlock);
        taskQueque.push_back(task);
    }
    wakeup();
}

Request *Worker::getRequest(clientId_t clientId)
{
    auto request = clientIdToRequest.find(clientId);
    if(request == clientIdToRequest.end())
    {
        Request* new_request = new Request;
        clientIdToRequest.insert({{clientId,new_request}});
        return new_request;
    }
    else
    {
        return (*request).second;
    }
}

int Worker::getRequestNum()
{

    return clientIdToRequest.size();
}
