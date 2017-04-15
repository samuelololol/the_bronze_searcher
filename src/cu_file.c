#include <stdio.h>
#include <stdbool.h>

#include "cu_common.h"
#include "cu_file.h"

bool cu_file_search(struct _cu_file *ths, const char *pattern,
                    Search_result *result)
{
    mode_t type;

    if (!get_file_type(pattern, &type))
        return NULL; /* get file type error */

    if (!pattern || !ths->path)
        return NULL; /* pattern or path error */

    if (!S_ISREG(type) && !S_ISDIR(type))
        return NULL; /* neither a regular file or directory */

    return false;
}
