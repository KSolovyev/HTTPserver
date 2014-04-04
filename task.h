#ifndef TASK_H
#define TASK_H


#include <set>
#include<functional>

class Worker;

class Task
{
public:
    Task(){}
    virtual ~Task()=0;
    virtual void operate(Worker* worker) = 0;
    virtual size_t getClientId()=0;
private:

};



#endif // TASK_H
