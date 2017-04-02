#include "gtest/gtest.h"

extern "C" {
#include "../src/cu_search.h"
#include <stdbool.h>
#include <libgen.h>
#ifdef __APPLE__
#include <mach-o/dyld.h>
#else
#endif

#define PATH_MAX 1024

    static bool get_exe_path(char **out, const unsigned int size)
    {
        bool success = false;

#ifdef __APPLE__
        if (_NSGetExecutablePath(*out, (uint32_t *)&size) == 0) {
            success = true;
            *out = dirname(*out);
        } else {
            success = false;
        }
        goto EXIT;

#elif __linux__

        ssize_t count = readlink("/proc/self/exe", *out, size);

        if (count != -1) {
            success = false;
        } else {
            success = true;
        }
#endif
EXIT:
        return success;
    }
}

TEST(Dummy, cu_search)
{
    unsigned int size = PATH_MAX * sizeof(char);
    char *cfpath = (char *)malloc(size);

    get_exe_path(&cfpath, size);
    printf("fpath: %s\n", cfpath);

    EXPECT_EQ(NULL, cu_search(NULL, NULL));
    free(cfpath);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
