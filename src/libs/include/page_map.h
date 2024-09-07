#if !defined(_PAGE_MAP_H_)
#define _PAGE_MAP_H_

#include "rbt.h"
#include "page.h"

typedef struct PageMap PageMap;

PageMap *build_link_pages(char *main_dir);
void page_map_destruct(PageMap *pm);
Page* page_map_get_page(PageMap *pm, char *page_name);
RBT *page_map_get_pages(PageMap *pm);
#endif // _PAGE_MAP_H_
