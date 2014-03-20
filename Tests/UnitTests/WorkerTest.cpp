#include"../../allForLibevent.h"
//#include"../../request.cpp"
#include <unittest++/UnitTest++.h>
#include<string>
#include"testTask.h"
#include "../../worker.cpp"

namespace workerTest
{
    struct Setings_worker{
        Setings_worker(){
            test1 = new TestTask1(1);
            test2 = new TestTask1(1);
            test3 = new TestTask1(2);
            test4 = new TestTask2(3,"abc");
            test5 = new TestTask2(3,"def");
            test6 = new TestTask2(4,"Hi, worker!");
            worker = new Worker;
        }
        ~Setings_worker()
        {

        }
        TestTask1 *test1,*test2,*test3;
        TestTask2 *test4,*test5,*test6;
        Worker* worker;
    };
}

using namespace workerTest;

TEST_FIXTURE(Setings_worker,workerTest)
{
    worker->addTask(test1);
    worker->addTask(test2);
    worker->addTask(test3);
    CHECK_EQUAL(worker->getRequestNum(),0);
    worker->run();
    worker->addTask(test4);
    worker->addTask(test5);
    worker->addTask(test6);
    worker->run();
    CHECK_EQUAL(worker->getRequestNum(),2);
    CHECK_EQUAL("abcdef",*(worker->getRequest(3)->getRequestText()));
    CHECK_EQUAL("Hi, worker!",*(worker->getRequest(4)->getRequestText()));
}


