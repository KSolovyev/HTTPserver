#ifndef WORKER_H
#define WORKER_H
#include <mutex>
#include <queue>
#include<unordered_map>

class Request;

typedef size_t clientId_t;
class Worker
{
public:
    Worker();
    void sleep();
    void run();
    void wakeup();
    void addTask(Task* task);
    void deleteTask(Task* task);
    Request* getRequest(clientId_t);
    int getRequestNum();
private:
    std::mutex taskQuequeBlock;
    std::deque<Task*> taskQueque;
    std::unordered_map<clientId_t, Request*> clientIdToRequest;
};

#endif // WORKER_H
