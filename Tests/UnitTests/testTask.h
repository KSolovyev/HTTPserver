#ifndef TESTTASK_H
#define TESTTASK_H
#include <iostream>
#include"../../allForLibevent.h"
#include"../../task.cpp"
class TestTask1:public Task
{
public:
    TestTask1(int clId):clientId(clId){}
    ~TestTask1(){}
    void operate(Worker* worker){cout<<"Hi, worker";}
    size_t getClientId(){return clientId;}
private:
    int clientId;


};

class TestTask2:public Task
{
public:
    TestTask2(int clId, string s):clientId(clId),buf(s){}
    ~TestTask2(){}
    void operate(Worker* worker){
        Request* req = worker->getRequest(clientId);
        req->writeBack(buf);
    }
    size_t getClientId(){return clientId;}
private:
    int clientId;
    string buf;
};

#endif // TESTTASK_H
