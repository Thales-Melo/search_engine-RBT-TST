#if !defined(_PAGE_H_)
#define _PAGE_H_

typedef struct Page Page;

#include "rbt.h"

Page* page_construct(char *page_name);
void page_destruct(Page *page);
RBT *page_get_in_links(Page *page);
RBT *page_get_out_links(Page *page);
double page_get_page_rank(Page *page);
int page_get_num_in_links(Page *page);
int page_get_num_out_links(Page *page);
double page_get_last_page_rank(Page *page);
int page_get_intersection_counter(Page *page);
void page_set_intersection_counter(Page *page, int value);
void page_set_num_out_links(Page *page, int num_out_links);
void page_set_num_in_links(Page *page, int num_in_links);
void page_set_page_rank(Page *page, double pr);
void page_set_last_page_rank(Page *page, double last_pr);
char *page_get_name(Page *page);
void page_insert_in_link(Page *page, Page *in);
void page_insert_out_link(Page *page, Page *out);
void page_update_last_page_rank(Page *page);
void page_print(Page *page);
int pages_comparator(const void *p1, const void *p2);

#endif // _PAGE_H_
