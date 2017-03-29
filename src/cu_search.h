#ifndef __CU_SEARCH_H__
#define __CU_SEARCH_H__

typedef struct _search_result Search_result;

Search_result *cu_search(const char *pattern, const char *file_path);

#endif
