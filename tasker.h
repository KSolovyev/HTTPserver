#ifndef TASKER_H
#define TASKER_H
#include<unordered_map>
#include<list>
#include"allForLibevent.h"
#include <thread>




class Task;

class Tasker
{
public:
    Tasker();
    ~Tasker(){}
    void pushTask(Task* task);

private:
    Worker* getWorkerResponsableForTask(Task *task);
    Worker* getNextFreeWorker();
    static std::unordered_map<size_t,Worker*> clientIdToWorker;

    std::list<Worker*> workers;
    std::list<Worker*>::iterator workerIterator;

    int getWorkersCount();

};



#endif // TASKER_H
