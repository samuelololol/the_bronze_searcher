#include <stdio.h>
#include <stdbool.h>

#include "cu_common.h"
#include "cu_file.h"

bool cu_file_search(struct _cu_file *ths, const char *pattern,
                    Search_result *result)
{
    if (!pattern || !ths->path || !is_text_file(pattern))
        return NULL; /* pattern or path error */

    if (!is_folder(ths->path) || !is_text_file(ths->path))
        return NULL; /* path not text file */

    return false;
}
