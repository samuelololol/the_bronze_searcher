#include <stdio.h>
#include <stdbool.h>

#include "cu_common.h"
#include "cu_file.h"

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

//struct _cu_file_vtable {
//    bool (*search)(struct _cu_file *this, const char *pattern,
//                   const char *file_path, Search_result *result);
//};

//struct _cu_file {
//    struct _cu_file_vtable method;
//    const char *path;
//};

bool cu_file_search(struct _cu_file *ths, const char *pattern,
                    Search_result *result)
{
    return false;
}
