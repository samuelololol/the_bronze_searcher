#include "gtest/gtest.h"

extern "C" {
#include "../src/cu_search.h"
#include <stdbool.h>
#ifdef __APPLE__
#include <mach-o/dyld.h>
#else
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <libproc.h>
#endif

    static bool get_exe_path(char **out, const unsigned int size)
    {
        bool success = false;

#ifdef __APPLE__
        if (_NSGetExecutablePath(*out, (uint32_t *)&size) == 0)
            success = true;
        else
            success = false;
        goto EXIT;

#elif __linux__
        pid_t pid = pid();
        int ret = proc_pidpath(pid, *out, size);

        if (ret <= 0)
            success = false;

        else
            success = true;
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
