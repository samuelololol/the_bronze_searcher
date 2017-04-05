#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "cu_common.h"
#include "cu_search.h"

/* chec if text file */
static inline bool is_text_file(const char *path)
{
    return false;
}

/* check if folder */
static inline bool is_folder(const char *path)
{
    return false;
}

Search_result *cu_search(const char *pattern, const char *file_path)
{
    if (!pattern || !file_path)
        return NULL; /* pattern or path error */

    if (!is_folder(file_path) || !is_text_file(file_path))
        return NULL; /* path not text file */

    Search_result *result = NULL;
    return result;
}
