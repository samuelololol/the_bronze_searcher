#include <sys/stat.h>
#include "cu_common.h"

bool get_file_type(const char *path, mode_t *type)
{
    bool success = false;
    struct stat stbuf;

    if (stat(path, &stbuf) != 0) {
        /* stat file error */
        success = false;
        goto EXIT;
    }

    *type = stbuf.st_mode;
    success = true;

EXIT:
    return success;
}
