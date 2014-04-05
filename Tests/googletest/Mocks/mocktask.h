#ifndef MOCKTASK_H
#define MOCKTASK_H
#include "worker.h"
#include "task.h"
#include <gmock/gmock.h>

class MockTask : public Task
{
public:
    MOCK_METHOD1(operate, void(Worker* worker));
    MOCK_METHOD0(getClientId, clientId_t());
};

#endif // MOCKTASK_H
