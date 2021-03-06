#include "gtest/gtest.h"

extern "C" {
#include "../src/cu_common.h"
#include <stdbool.h>
#include <libgen.h>             /* dirname() */
#include <string.h>

#ifdef __APPLE__
#include <mach-o/dyld.h>
//#define _BSD_SOURCE
#else
//#define _GNU_SOURCE
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

            *path_len = strlen(*out);
            // printf("size of path: %lu\n", *path_len);
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

    static bool get_test_data_folder(char **folder, const unsigned int size,
                                     size_t *len)
    {
        bool success = _get_exe_folder_path(folder, size, len);

        if (!success) {
            // printf("get test data folder fail!");
            return false;
        }
        else {
            *len += 10 + 1;

            if(NULL == strncat(*folder, "/test/data", *len)) {
                printf("concat project path with test data folder path fail\n");
                return false;
            }
            else {
                // printf("test data folder: %s\n", *folder);
                return true;
            }
        }
    }

    static bool get_utf8_test_file_path(char **path, const unsigned int size)
    {
        size_t len = 0;

        if(!get_test_data_folder(path, size, &len))
            return false;

        len += 9 + 1;

        if(NULL == strncat(*path, "/utf8.txt", len)) {
            // printf("concat test data folder path with utf8 filename fail\n");
            return false;
        }
        else {
            // printf("test file path: %s\n", *path);
            return true;
        }
    }
}

TEST(cu_common, test_get_file_type)
{
    unsigned int size = PATH_MAX * sizeof(char);
    char *path = (char *)malloc(size);

    if(get_utf8_test_file_path(&path, size))
        printf("path: %s\n", path);

    mode_t type = 0;
    bool success = false;
    success = get_file_type(path, &type);

    EXPECT_TRUE(success);
    EXPECT_TRUE(S_ISREG(type));
    //EXPECT_EQ(true, S_ISREG(type));
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
