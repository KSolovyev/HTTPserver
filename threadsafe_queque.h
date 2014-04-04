#ifndef THREADSAFE_QUEUE_H
#define THREADSAFE_QUEUE_H
#include <iostream>
#include <queue>
#include <mutex>
#include <condition_variable>
#include <memory>
#include <stdio.h>
#include <stdlib.h>

template<typename T>
class ThreadsafeQueue
{
private:
    std::mutex mut;
    std::queue<T> dataQueue;
    std::condition_variable dataCond;
public:

    ThreadsafeQueue(){}
    ThreadsafeQueue(ThreadsafeQueue const& other)
    {
        std::unique_lock<std::mutex> lk(other.mut);
        dataQueue = other.dataQueue;
    }


    void push(T newValue)
    {
        std::unique_lock<std::mutex> lk(mut);
        dataQueue.push(newValue);
        dataCond.notify_one();
    }


    void waitAndPop(T &value)
    {
         std::unique_lock<std::mutex> lk(mut);
         dataCond.wait(lk, [this]{return !dataQueue.empty();});
         value = dataQueue.front();
         dataQueue.pop();
    }


    std::shared_ptr<T> waitAndPop()
    {
        std::unique_lock<std::mutex> lk(mut);
        dataCond.wait(lk, [this]{return !dataQueue.empty();});
        std::shared_ptr<T> res(std::make_shared<T>(dataQueue.front()));
        dataQueue.pop();
        return res;
    }


    bool tryPop(T &value)
    {
        std::unique_lock<std::mutex> lk(mut);
        if(dataQueue.empty())
            return false;
        value = dataQueue.front();
        dataQueue.pop();
        return true;
    }


    std::shared_ptr<T> tryPop()
    {
        std::unique_lock<std::mutex> lk(mut);
        if(dataQueue.empty())
            return std::shared_ptr<T>();
        std::shared_ptr<T> res(std::make_shared<T>(dataQueue.front()));
        dataQueue.pop();
        return res;
    }


    bool empty()
    {
        std::unique_lock<std::mutex> lk(mut);
        return dataQueue.empty();
    }
//    void push(T new_value);
//    void waitAndPop(T& value);
//    std::shared_ptr<T> waitAndPop();
//    bool tryPop(T& value);
//    std::shared_ptr<T> tryPop();
//    bool empty();



};

#endif // THREADSAFE_QUEQUE_H
