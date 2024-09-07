#include <stdio.h>
#include <stdlib.h>

#include <time.h>

#include "../libs/include/stop_word.h"
#include "../libs/include/string_map.h"
#include "../libs/include/page_map.h"
#include "../libs/include/search_engine.h"

int main(int argc, char *argv[]) {
    if (argc != 2)
        exit(printf("Error: invalid number of arguments.\n"));

    #ifdef DEBUG_MODE
    clock_t start, end;
    double cpu_time_used;
    start = clock();
    #endif

    int num_pages = 0;

    StopWord *stop_words = stop_word_read(argv[1]);
    PageMap *pm = build_link_pages(argv[1]);
    StringMap *sm = string_map_build(argv[1], stop_words, pm, &num_pages);

    calculate_page_ranks(num_pages, pm);

    stop_word_destruct(stop_words);
    string_map_destruct(sm);
    page_map_destruct(pm);
        
    #ifdef DEBUG_MODE
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Execution time: %f seconds\n", cpu_time_used);
    #endif

    return 0;
}