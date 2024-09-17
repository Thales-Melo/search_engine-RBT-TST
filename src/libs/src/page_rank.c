#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/page_rank.h"
#include "../include/page_map.h"
#include "../include/page.h"
#include "../include/rbt.h"
#include "../include/utils.h"

#define PGR_LIMIT 0.000001
#define ALPHA 0.85


void initialize_page_rank(void *page, void *initial_pr) {
    Page *p = (Page *)page;
    double initial_value = *(double *)initial_pr;
    page_set_page_rank(p, initial_value);
    page_set_last_page_rank(p, initial_value);
}

void accumulate_page_rank(void *page, void *sum) {
    Page *p = (Page *)page;
    double *total_sum = (double *)sum;
    *total_sum += page_get_last_page_rank(p) / (double)page_get_num_out_links(p);
}

void compute_page_rank(void *page, void *data) {
    Page *p = (Page *)page;
    double num_pages = ((double *)data)[0];
    double *difference = &((double *)data)[1];
    double pr = 0.0;

    RBT *in_pages = page_get_in_links(p);
    apply_to_all_pages(in_pages, accumulate_page_rank, &pr);

    if (page_get_num_out_links(p) == 0)
        pr += page_get_last_page_rank(p);
    
    pr = ALPHA * pr + (1 - ALPHA) / num_pages;
    page_set_page_rank(p, pr);
    *difference += fabs(pr - page_get_last_page_rank(p));
}

void update_last_page_rank(void *page, void *unused) {
    Page *p = (Page *)page;
    page_update_last_page_rank(p);
}

void calculate_page_ranks(int num_pages, PageMap *pm) {
    double initial_pr = 1.0 / (double)num_pages;
    RBT *pages = page_map_get_all_pages(pm);
    apply_to_all_pages(pages, initialize_page_rank, &initial_pr);

    double data[2];
    data[0] = (double)num_pages;
    data[1] = 1.0; // Diferença inicial

    // Iteração até convergência
    while (data[1] >= PGR_LIMIT) {
        data[1] = 0.0;
        apply_to_all_pages(pages, compute_page_rank, data);
        apply_to_all_pages(pages, update_last_page_rank, NULL);
        data[1] /= data[0];
    }
}
