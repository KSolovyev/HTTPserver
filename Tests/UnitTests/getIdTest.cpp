
#include"../../getid.h"
#include"../../getid.cpp"
#include <unittest++/UnitTest++.h>

namespace getIdTest
{
    struct Sets{
        Sets(){
            a = new int(5);
        }
        ~Sets()
        {

        }

        getId<int> getHash, getHash2;
         int* a;
    };
}
using namespace getIdTest;


TEST_FIXTURE(Sets,getIdTest)
{

    CHECK_EQUAL(1,getHash(new int));
    CHECK(getHash(a) == 2);
    CHECK_EQUAL(getHash(a), 2);
    CHECK_EQUAL(getHash(a), 2);
    CHECK_EQUAL(getHash(new int), 3);
    CHECK_EQUAL(getHash(a), 2);
    CHECK_EQUAL(getHash2(a), 2);

}



