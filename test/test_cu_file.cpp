#include "gtest/gtest.h"

extern "C" {
#include "../src/cu_common.h"
#include "../src/cu_file.h"
#include <stdbool.h>
#include <libgen.h>             /* dirname() */
#include <string.h>

#ifdef __APPLE__
#include <mach-o/dyld.h>
#else
#endif

#define PATH_MAX 1024

    static bool _get_exe_folder_path(char **out, const unsigned int size,
                                     size_t *path_len)
    {
        bool success = false;

#if __APPLE__
        if (_NSGetExecutablePath(*out, (uint32_t *)&size) == 0) {
            success = true;
            *out = dirname(*out); /* _build/./test */
            *out = dirname(*out); /* _build/. */
            *out = dirname(*out); /* _build/ */
            *out = dirname(*out); /* / */
            printf("size of path: %d\n", strlen(*out));
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

    static bool get_test_data_folder(char **folder, const unsigned int size)
    {
        //unsigned int size = PATH_MAX * sizeof(char);
        size_t len = 0;

        bool success = _get_exe_folder_path(folder, size, &len);

        if (!success) {
            printf("get test data folder fail!");
            return false;
        }
        else {
            if(NULL == strncat(*folder, "/test/data", len + 10 + 1)) {
                printf("concat project path with test data folder path fail\n");
                return false;
            }
            else {
                printf("test data folder: %s\n", *folder);
                return true;
            }
        }
    }
}

TEST(cu_file, Test_File_Search_Function_Arguments_NULL)
{
    unsigned int size = PATH_MAX * sizeof(char);
    char *path = (char *)malloc(size);

    if(get_test_data_folder(&path, size))
        printf("path: %s\n", path);


    CU_File f = {{&cu_file_search}, "/tmp"};
    EXPECT_EQ(NULL, f.method.search(NULL, NULL, NULL));
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
