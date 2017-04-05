#include "gtest/gtest.h"

extern "C" {
#include "../src/cu_common.h"
#include "../src/cu_file.h"
}

TEST(cu_file, cu_file_null)
{
    CU_File f = {{&cu_file_search}, "/tmp"};
    EXPECT_EQ(NULL, f.method.search(NULL, NULL, NULL));
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
