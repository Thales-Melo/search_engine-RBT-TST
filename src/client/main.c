#include <stdio.h>
#include <stdlib.h>

#include <time.h>

#include "../libs/include/stop_word.h"
#include "../libs/include/string_map.h"
#include "../libs/include/page_map.h"
#include "../libs/include/page_rank.h"
#include "../libs/include/search_engine.h"

#define MAIN_DIR argv[1]

int main(int argc, char *argv[]) {
    if (argc != 2)
        exit(printf("Error: invalid number of arguments.\n"));

    #ifdef DEBUG_MODE
    clock_t start, end;
    double cpu_time_used;
    start = clock();
    #endif

    int num_pages = 0;
    StopWord *stop_words = stop_word_read(MAIN_DIR);
    PageMap *pm = build_link_pages(MAIN_DIR);
    StringMap *sm = string_map_build(MAIN_DIR, stop_words, pm, &num_pages);

    calculate_page_ranks(num_pages, pm);
    run_search_engine(sm, stop_words, num_pages);

    stop_word_destruct(stop_words);
    page_map_destruct(pm);
    string_map_destruct(sm);
        
    #ifdef DEBUG_MODE
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Execution time: %f seconds\n", cpu_time_used);
    #endif

    return 0;
}