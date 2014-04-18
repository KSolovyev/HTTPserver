#include "tasker.h"

std::unordered_map<size_t,Worker*> Tasker::clientIdToWorker;

Tasker::Tasker()
{

    std::thread *t;
    for(int i = 0; i < getWorkersCount(); i++)
    {
        Worker * worker = new Worker;
        ParsedRequestFactory* factory = new CommonParsedRequestFactory();
        worker->useParsedRequestFactory(factory);
        Matcher* matcher = new Matcher_impl;
        matcher->pushRule(std::shared_ptr<Rule>(new DefaultRule));
        worker->useMatcher(matcher);
        workers.push_back(worker);
        t = new std::thread(&Worker::run, worker);
        t->detach();
    }
    workerIterator = workers.begin();

}

void Tasker::pushTask(Task *task)
{
    Worker* worker = getWorkerResponsableForTask(task);
    worker->addTask(task);
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

int Tasker::getWorkersCount()
{
   return 1;
    // return std::thread::hardware_concurrency()>2?std::thread::hardware_concurrency():2;
}
