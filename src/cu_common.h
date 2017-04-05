#ifndef __CU_COMMON_H__
#define __CU_COMMON_H__

typedef struct _search_result Search_result;
struct _search_result {
    char *path;
    unsigned int line_no;
    /* unsigned int column; */
};

#endif
