#include "getid.h"
#include <gtest/gtest.h>
#include "getidtest.h"

class getIdTest : public testing::Test
{
public:
    virtual void SetUp()
    {
        a = new int(5);



    }

    virtual void TearDown()
    {

        delete a;
    }

    getId<int> getHash, getHash2;
    int* a;
};


//TEST_F(getIdTest, getHashTest)
//{

//    EXPECT_EQ(1,getHash(new int));
//    ASSERT_TRUE(getHash(a) == 2);
//    EXPECT_EQ(getHash(a), 2);
//    EXPECT_EQ(getHash(a), 2);
//    EXPECT_EQ(getHash(new int), 3);
//    EXPECT_EQ(getHash(a), 2);
//    EXPECT_EQ(getHash2(a), 2);
//}
