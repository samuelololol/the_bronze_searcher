#include "gtest/gtest.h"
//#include "gmock/gmock.h"

TEST(Dummy, foobar)
{
    EXPECT_EQ(1, 1);
}


int main(int argc, char **argv)
{
        ::testing::InitGoogleTest(&argc, argv);
            return RUN_ALL_TESTS();

}