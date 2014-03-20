#include <iostream>

#include <unittest++/UnitTest++.h>
using namespace std;

#include "getIdTest.cpp"
#include "RequestTest.cpp"
#include "WorkerTest.cpp"

int main()
{
    return UnitTest::RunAllTests();
}

