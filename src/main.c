#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cu_common.h"
#include "cu_file.h"

int main(void)
{
    CU_File f = {
        .search = &cu_file_search,
        .path = "/tmp"
    };

    int r_size = sizeof(struct _search_result);
    Search_result *r = (Search_result *) malloc(r_size);

    memset(r, '\0', r_size);
    f.search(&f, "pattern", r);
    printf("search result: %s\nline: %d\n", r->path, r->line_no);
    return 0;
}
