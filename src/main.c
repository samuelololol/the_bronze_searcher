#include <stdio.h>
#include <stdlib.h>

#include "cu_common.h"
#include "cu_file.h"

int main(void)
{
    CU_File f = {{&cu_file_search}, "/tmp"};
    int r_size = sizeof(struct _search_result);
    Search_result *r = (Search_result *) malloc(r_size);

    memset(r, '\0', r_size);
    f.method.search(&f, "pattern", r);
    printf("search result: %s\nline: %d\n", r->path, r->line_no);
    return 0;
}
