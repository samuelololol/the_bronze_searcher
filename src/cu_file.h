#ifndef __FILE_H__
#define __FILE_H__
#include <stdbool.h>
#include "cu_common.h"

typedef struct _cu_file_vtable CU_File_VTable;
typedef struct _cu_file CU_File;

struct _cu_file;
struct _cu_file_vtable {
    bool (*search)(struct _cu_file *ths, const char *pattern,
                   Search_result *result);

};

struct _cu_file {
    CU_File_VTable method;
    const char *path;
};

bool cu_file_search(struct _cu_file *ths, const char *pattern,
                    Search_result *result);

#endif
