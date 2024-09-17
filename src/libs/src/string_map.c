#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/types.h"
#include "../include/utils.h"
#include "../include/string_map.h"
#include "../include/page.h"


#define PAGE_DIR "pages"
#define INDEX_DIR "index.txt"

struct StringMap {
    RBT *map; // Key: word, value: RBT com as páginas que contém a palavra => Key: page_name, Value: Page*
};

StringMap *string_map_construct() {
    StringMap *sm = malloc(sizeof(StringMap));
    if (sm == NULL)
        exit(printf("Error: string_map_construct: could not allocate memory.\n"));
    sm->map = RBT_construct();
    return sm;
}

void string_map_destruct(StringMap *sm) {
    apply_to_all_pages(sm->map, (Func )RBT_destruct, NULL); // Pages são destruídas em page_map_destruct
    RBT_destruct(sm->map, NULL);
    free(sm);
}

RBT *string_map_search(StringMap *sm, char *word) {
    return (RBT*) RBT_search(sm->map, word, strcmp);
}

void string_map_print(StringMap *sm) {
    // Iterar sobre o RBT e imprimir cada palavra e suas páginas
    RBTIterator *iter = RBT_iterator_create(sm->map);
    while (RBT_iterator_valid(iter)) {
        char *word = RBT_iterator_key(iter);
        printf("Key %s\n", word);
        RBT *pages = (RBT*) RBT_iterator_value(iter);
        RBT_print_keys(pages);
        printf("\n");
        RBT_iterator_next(iter);
    }
    RBT_iterator_destroy(iter);
}

void string_map_insert(RBT *sm_map, RBT *pages, Page *page, char *word) {
    // Se a página não estiver na RBT da palavra, inserir
    char *page_name = page_get_name(page);
    if (!RBT_contains_key(pages, page_name, strcmp)) {
        pages = RBT_insert(pages, page_name, page, strcmp);
        sm_map = RBT_insert(sm_map, word, pages, strcmp);
    }
}

StringMap *string_map_build(char *main_dir, StopWord *stop_words, PageMap *pm, int *num_pages) {
    StringMap *sm = string_map_construct();
    
    char index_dir[256];
    sprintf(index_dir, "%s/%s", main_dir, INDEX_DIR);
    FILE *index_file = fopen(index_dir, "r");
    if (index_file == NULL)
        exit(printf("Error string_map_build: failed to open file: %s\n", index_dir));
    
    char *page_name = NULL, *line_from_page = NULL;
    size_t size_p = 0, size_l = 0;
    ssize_t read_p = 0, read_l = 0;

    while(read_p = (getline(&page_name, &size_p, index_file)) != -1) {
        page_name = strtok(page_name, " \n");
        char page_dir[256];
        sprintf(page_dir, "exemplo/pages/%s", page_name);
        FILE *page_file = fopen(page_dir, "r");
        if (page_file == NULL)
            exit(printf("Error string_map_build: failed to open file: %s\n", page_dir));
        *num_pages += 1;

        while(read_l = getline(&line_from_page, &size_l, page_file) != -1) {
            remove_newline(line_from_page);
            char *word_token = strtok(line_from_page, " \n\t");
            while(word_token != NULL) {
                string_to_lower(word_token);

                // Se a palavra não for uma stop word
                if (!stop_word_contains(stop_words, word_token)) {
                    // Verificar se a palavra já está no mapa
                    RBT *pages = string_map_search(sm, word_token);

                    // Se a palavra não estiver no mapa, criar um novo RBT para as páginas
                    if (pages == NULL) 
                        sm->map = RBT_insert(sm->map, word_token, pages, strcmp);
                    
                    // Inserir a página no RBT da palavra (se já não estiver)
                    string_map_insert(
                        sm->map, 
                        pages, 
                        page_map_get_page(pm, page_name), 
                        word_token
                    );
                }
                word_token = strtok(NULL, " \n\t");
            }
        }
        fclose(page_file);
    }
    free(page_name);
    free(line_from_page);
    fclose(index_file);
    return sm;
}