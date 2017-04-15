#include <sys/stat.h>
#include "cu_common.h"

/* chec if text file */
bool is_text_file(const char *path)
{
    bool is_file = false;
    struct stat stbuf;

    if (stat(path, &stbuf)) {
        /* stat file error */
        is_file = false;
        goto EXIT;
    }

    if (S_ISREG(stbuf.st_mode))
        is_file = true;

EXIT:
    return is_file;
}

/* check if folder */
bool is_folder(const char *path)
{
    return false;
}
