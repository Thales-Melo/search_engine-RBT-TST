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
    int intersection_counter;
    RBT *in_links; // <Key: page_name, Value: *page> Não é cópia, mas sim referencia.
    RBT *out_links; // <Key: page_name, Value: *page> Não é cópia, mas sim referencia.
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
    page->intersection_counter = 0;
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

double page_get_page_rank(Page *page) {
    return page->page_rank;
}

double page_get_last_page_rank(Page *page) {
    return page->last_page_rank;
}

int page_get_num_in_links(Page *page) {
    return page->num_in_links;
}

int page_get_num_out_links(Page *page) {
    return page->num_out_links;
}

int page_get_intersection_counter(Page *page) {
    return page->intersection_counter;
}

void page_set_intersection_counter(Page *page, int value) {
    page->intersection_counter = value;
}

void page_set_page_rank(Page *page, double pr) {
    page->page_rank = pr;
}

void page_set_last_page_rank(Page *page, double last_pr) {
    page->last_page_rank = last_pr;
}

void page_set_num_out_links(Page *page, int num_out_links) {
    page->num_out_links = num_out_links;
}

void page_set_num_in_links(Page *page, int num_in_links) {
    page->num_in_links = num_in_links;
}

void page_insert_in_link(Page *page, Page *in) {
    page->in_links = RBT_insert(page->in_links, page_get_name(in), in, strcmp);
    page->num_in_links++;
}

void page_insert_out_link(Page *page, Page *out) {
    page->out_links = RBT_insert(page->out_links, page_get_name(out), out, strcmp);
}

void page_update_last_page_rank(Page *page) {
    page->last_page_rank = page->page_rank;
}

void page_print(Page *page) {
    // Impressão das paginas de saida
    RBT_print_keys(page->out_links);
}

int pages_comparator(const void *p1, const void *p2) {
    Page* (*page1) = (Page**) p1;
    Page* (*page2) = (Page**) p2;

    if((*page1) == NULL && (*page2) == NULL)              return 0; 
    else if((*page1) == NULL)                             return 1; 
    else if((*page2) == NULL)                             return -1; 

    if((*page1)->page_rank > (*page2)->page_rank)         return -1;
    else if((*page1)->page_rank < (*page2)->page_rank)    return 1;
    else                                                  return 0;
}