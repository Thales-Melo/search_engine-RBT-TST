#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/page.h"


#define INDEX_DIR "index.txt"

struct Page {
    char *page_name;
    double page_rank;
    double last_page_rank;
    int num_out_links;
    int num_in_links;
    RBT *in_links; // <Key: page_name, Value: NULL>
    RBT *out_links; // <Key: page_name, Value: NULL>
};


Page* page_construct(char *page_name) {
    Page *page = (Page*) malloc(sizeof(Page));
    if (page == NULL)
        exit(printf("Error Page_construct: failed to allocate memory.\n"));
    page->page_name = strdup(page_name);
    page->page_rank = 0.0;
    page->last_page_rank = 0.0;
    page->num_out_links = 0;
    page->num_in_links = 0;
    page->in_links = RBT_construct();
    page->out_links = RBT_construct();
    return page;
}

void page_destruct(Page *page) {
    free(page->page_name);
    RBT_destruct(page->in_links, NULL);
    RBT_destruct(page->out_links, NULL);
    free(page);
}

RBT *page_get_in_links(Page *page) {
    return page->in_links;
}

RBT *page_get_out_links(Page *page) {
    return page->out_links;
}

char *page_get_name(Page *page) {
    return page->page_name;
}

void page_set_num_out_links(Page *page, int num_out_links) {
    page->num_out_links = num_out_links;
}

void page_set_num_in_links(Page *page, int num_in_links) {
    page->num_in_links = num_in_links;
}

void page_insert_in_link(Page *page, char *page_name) {
    page->in_links = RBT_insert(page->in_links, page_name, SPECIAL_NULL_VALUE, strcmp);
    page->num_in_links++;
}

void page_insert_out_link(Page *page, char *page_name) {
    page->out_links = RBT_insert(page->out_links, page_name, SPECIAL_NULL_VALUE, strcmp);
}

void page_print(Page *page) {
    // Impressão das paginas de saida
    RBT_print_keys(page->out_links);
}