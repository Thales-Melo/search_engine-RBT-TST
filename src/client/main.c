#include <stdio.h>
#include <stdlib.h>

#include "../libs/include/stop_word.h"
#include "../libs/include/string_map.h"
#include "../libs/include/page_map.h"

int main(int argc, char *argv[]) {
    if (argc != 2)
        exit(printf("Error: invalid number of arguments.\n"));

    StopWord *stop_words = stop_word_read(argv[1]);
    StringMap *sm = string_map_build(argv[1], stop_words);
    PageMap *pm = build_link_pages(argv[1]);

    stop_word_destruct(stop_words);
    string_map_destruct(sm);
    page_map_destruct(pm);
    
    return 0;
}