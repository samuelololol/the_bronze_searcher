#ifndef __CU_COMMON_H__
#define __CU_COMMON_H__
#include <stdbool.h>
#include <sys/stat.h>

typedef struct _search_result {
    char *path;
    unsigned int line_no;
    /* unsigned int column; */
} Search_result;

bool get_file_type(const char *path, mode_t *type);

#endif
