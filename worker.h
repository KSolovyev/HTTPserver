#ifndef WORKER_H
#define WORKER_H
#include <mutex>
#include <queue>
#include<unordered_map>
#include "allForLibevent.h"



class Request;
//class Task;

typedef size_t clientId_t;
class Worker
{
public:
    Worker();
    ~Worker();
    void sleep();
    void run();
    void wakeup();
    void addTask(Task* task);
    void deleteTask(Task* task);
    void useParsedRequestFactory(ParsedRequestFactory* parsedRequestFactory);
    void useMatcher(Matcher* matcher);
    std::shared_ptr<Request> getRequest(Outputable* output);
    void deleteRequest(clientId_t clientId);
    std::shared_ptr<ParsedRequestFactory> getParsedRequestFactory();
    std::shared_ptr<Matcher> getMatcher();
    int getRequestNum();
private:
    std::shared_ptr<Matcher> matcher;
    std::mutex taskQuequeBlock;
    ThreadsafeQueue<Task*> taskQueque;
    std::unordered_map<clientId_t, std::shared_ptr<Request>> clientIdToRequest;
    std::shared_ptr<ParsedRequestFactory> parsedRequestFactory;
};

#endif // WORKER_H
