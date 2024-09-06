#if !defined(_PAGE_H_)
#define _PAGE_H_

typedef struct Page Page;

#include "rbt.h"

Page* page_construct(char *page_name);
void page_destruct(Page *page);
RBT *page_get_in_links(Page *page);
RBT *page_get_out_links(Page *page);
void page_set_num_out_links(Page *page, int num_out_links);
void page_set_num_in_links(Page *page, int num_in_links);
char *page_get_name(Page *page);
void page_insert_in_link(Page *page, char *page_name);
void page_insert_out_link(Page *page, char *page_name);
void page_print(Page *page);

#endif // _PAGE_H_
