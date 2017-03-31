#include "gtest/gtest.h"

extern "C" {
#include "../src/cu_search.h"
}


TEST(Dummy, cu_search)
{
    EXPECT_EQ(NULL, cu_search(NULL, NULL));
}


int main(int argc, char **argv)
{
        ::testing::InitGoogleTest(&argc, argv);
            return RUN_ALL_TESTS();

}
