#include "tasker.h"

Tasker::Tasker()
{

    for(int i = 0; i < getWorkersCount(); i++)
    {

        workers.push_back(new Worker);

    }
    workerIterator = workers.begin();
}

void Tasker::pushTask(Task *task)
{
    Worker* worker = getWorkerResponsableForTask(task);
    worker->
}

Worker *Tasker::getWorkerResponsableForTask(Task* task)
{
    auto worker = clientIdToWorker.find(task->getClientId());
    if (worker == clientIdToWorker.end())
    {

        return getNextFreeWorker();
    }
    else
    {
        return (*worker).second;
    }
}

Worker *Tasker::getNextFreeWorker()
{
    if(workerIterator == workers.end())
    {
        workerIterator = workers.begin();
    }
    return (*(workerIterator++));
}
