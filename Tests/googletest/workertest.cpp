#include "workertest.h"
#include "worker.h"
#include "request.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "mocktask.h"
#define CLIENT_ID 1

class WorkerTest: public testing::Test{
public:
    void SetUp(){
        worker = new Worker();
    }

    void TearDown(){
        delete worker;
    }



    Worker *worker;
};


using ::testing::Return;
using ::testing::Invoke;
using ::testing::_;
using ::testing::InvokeWithoutArgs;
using ::testing::A;

TEST_F(WorkerTest,CreationTest)
{
    //Worker *worker = new Worker();
    ASSERT_TRUE(worker);
}

/*TEST_F(WorkerTest,OperatingOnTask)
{
    MockTask task;
    Worker *worker = new Worker();
    EXPECT_CALL(task, operate(_))
            .WillOnce(Invoke(FakeOperate))
            .WillOnce(Invoke(FakeOperate));
    EXPECT_CALL(task, getClientId())
            .WillRepeatedly(Return(CLIENT_ID));
//    EXPECT_CALL(task, operate(worker))
//            .Times(2);
    worker->addTask(&task);
    worker->addTask(&task);
    EXPECT_EQ(worker->getRequestNum(),0);
    worker->run();
    EXPECT_EQ(*(worker->getRequest(CLIENT_ID)->getRequestText()), "abcabc");
}
*/


