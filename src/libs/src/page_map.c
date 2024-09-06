#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/page.h"
#include "../include/rbt.h"
#include "../include/page_map.h"

#define GRAPH_DIR "graph.txt"

struct PageMap {
    RBT *pages; // <Key: page_name, Value: Page*>
};

PageMap* page_map_construct() {
    PageMap *pm = (PageMap*) malloc(sizeof(PageMap));
    if (pm == NULL)
        exit(printf("Error PageMap_construct: failed to allocate memory.\n"));
    pm->pages = RBT_construct();
    return pm;
}

void page_map_destruct(PageMap *pm) {
    RBT_destruct(pm->pages, (void (*)(void *)) page_destruct);
    free(pm);
}

Page* page_map_get_page(PageMap *pm, char *page_name) {
    return (Page*) RBT_search(pm->pages, page_name, strcmp);
}

void page_map_print(PageMap *pm) {
    RBTIterator *it = RBT_iterator_create(pm->pages);
    while(RBT_iterator_valid(it)) {
        Page *page = (Page*) RBT_iterator_value(it);
        printf("Page %s", RBT_iterator_key(it));
        page_print(page);
        RBT_iterator_next(it);
    }
    RBT_iterator_destroy(it);
}

PageMap *build_link_pages(char *main_dir) {
    PageMap *pm = page_map_construct();

    char graph_file[256];
    sprintf(graph_file, "%s/%s", main_dir, GRAPH_DIR);
    FILE *file = fopen(graph_file, "r");
    if (file == NULL)
        exit(printf("Error build_link_pages: Failed to open file %s\n", graph_file));

    int tok_counter = 0;
    size_t size = 0;
    char *line = NULL, *token = NULL, *current_key = NULL;
    ssize_t read;

    Page *current_page = NULL, *page_dest = NULL;
    RBT *current_node = NULL, *out_pages = NULL, *dest_in_pages = NULL;
    while(read = getline(&line, &size, file) != -1) {
        token = strtok(line, " \n");
        tok_counter = 0;
        while(token) {
            if (!tok_counter) {
                //Pegar a página atual
                current_page = page_map_get_page(pm, token);
                if (current_page == NULL) {
                    //Se a página ainda não existe, criar uma nova
                    current_page = page_construct(token);
                    pm->pages = RBT_insert(pm->pages, token, current_page, strcmp);
                } 
                // Pegar a lista de páginas de saída
                out_pages = page_get_out_links(current_page);
            } else if (tok_counter == 1) {
                // Numero de links de saída. Setar a quantidade de links de saída
                page_set_num_out_links(current_page, atoi(token));
            } else {
                // Páginas que a página atual aponta, ou seja, páginas de saída
                
                // Inserir as páginas de saída
                page_insert_out_link(current_page, token);

                // Pegar a página de destino
                page_dest = page_map_get_page(pm, token);
                if (page_dest == NULL) {
                    // Se a página de destino não existe, criar uma nova
                    page_dest = page_construct(token);
                    pm->pages = RBT_insert(pm->pages, token, page_dest, strcmp);
                }
                
                // Pegar a lista de páginas de entrada da página de destino
                dest_in_pages = page_get_in_links(page_dest);
                // Inserir a current_page na lista de páginas de entrada da página de destino
                page_insert_in_link(page_dest, page_get_name(current_page));
            }
            token = strtok(NULL, " \n");
            tok_counter++;
        }
    }
    free(line);
    fclose(file);
    printf("PageMap built.\n");
    return pm;
}