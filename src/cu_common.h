#ifndef __CU_COMMON_H__
#define __CU_COMMON_H__
#include <stdbool.h>

typedef struct _search_result Search_result;
struct _search_result {
    char *path;
    unsigned int line_no;
    /* unsigned int column; */
};

bool is_text_file(const char *path);
bool is_folder(const char *path);

#endif
