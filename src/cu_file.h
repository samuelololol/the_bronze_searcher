#ifndef __FILE_H__
#define __FILE_H__
#include <stdbool.h>
#include "cu_common.h"

struct _cu_file;
typedef struct _cu_file_vtable CU_File_VTable;
typedef struct _cu_file CU_File;

typedef bool (*SEARCHFUNC_IN_FILE)(CU_File *, const char *, Search_result *);

struct _cu_file_vtable {
    SEARCHFUNC_IN_FILE search;
};

struct _cu_file {
    CU_File_VTable method;
    const char *path;
};

bool cu_file_search(struct _cu_file *ths, const char *pattern,
                    Search_result *result);
#endif
