#if !defined(_PAGE_MAP_H_)
#define _PAGE_MAP_H_

typedef struct PageMap PageMap;

PageMap *build_link_pages(char *main_dir);
void page_map_destruct(PageMap *pm);

#endif // _PAGE_MAP_H_
