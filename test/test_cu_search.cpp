#include "gtest/gtest.h"

extern "C" {
#include "../src/cu_common.h"
#include "../src/cu_search.h"
#include <stdbool.h>
#include <libgen.h>             /* dirname() */
#ifdef __APPLE__
#include <mach-o/dyld.h>
#else
#endif

#define PATH_MAX 1024

    static bool _get_exe_folder_path(char **out, const unsigned int size)
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

    static void get_test_data_folder(char **folder)
    {
        unsigned int size = PATH_MAX * sizeof(char);
        char *exe_folder_path = (char *)malloc(size);

        _get_exe_folder_path(&exe_folder_path, size);
        printf("exe folder: %s\n", exe_folder_path);

        free(exe_folder_path);
    }
}

TEST(Dummy, cu_search)
{
    unsigned int size = PATH_MAX * sizeof(char);
    char *path = (char *)malloc(size);

    get_test_data_folder(&path);
    path = dirname(path);

    printf("path: %s\n", path);
    EXPECT_EQ(NULL, cu_search(NULL, NULL));
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
