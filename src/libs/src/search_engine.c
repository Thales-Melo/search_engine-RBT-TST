#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/search_engine.h"
#include "../include/page_map.h"
#include "../include/page.h"
#include "../include/rbt.h"
#include "../include/utils.h"


void process_intersection(void *page, void *argument) {
    void **args = (void **) argument;
    Page **pages = (Page **) args[0];
    int *index = (int *) args[1];

    Page *p = (Page *) page;
    int intersec_counter = page_get_intersection_counter(p);
    
    // Se a página ainda não fez parte de nenhuma interseção
    if (intersec_counter == 0) {
        // Adiciona a página ao vetor de interseção e incrementa o índice
        pages[*index] = p;
        (*index)++;
    }
    
    page_set_intersection_counter(p, intersec_counter + 1);
}

void display_search_results(char *query, Page **pages, int total_pages, int expected_intersec_count, bool search_success) {
    printf("search:%s\n", query);
    
    printf("pages:");
    int printed_pages = 0;
    if (search_success) {
        for (int i = 0; i < total_pages; i++) {
            Page *p = pages[i];
            
            // Verifica se o contador de interseções da página é igual ao número de termos buscados
            if (page_get_intersection_counter(p) == expected_intersec_count) {
                if (printed_pages > 0) printf(" ");
                printf("%s", page_get_name(p));
                printed_pages++;
            }
        }
    }

    printf("\npr:");
    for (int i = 0; i < total_pages; i++) {
        Page *p = pages[i];
        
        if (page_get_intersection_counter(p) == expected_intersec_count && search_success) {
            if (i > 0) printf(" ");
            printf("%.20lf", page_get_page_rank(p));
        }
        
        // Reseta o contador de interseção e o vetor de pages para preparar para a próxima consulta
        page_set_intersection_counter(p, 0);
        pages[i] = NULL;
    }
    printf("\n");
}

void run_search_engine(StringMap *sm, StopWord *stop_words, int num_pages) {
    char *buffer = NULL, *query = NULL, *token = NULL;
    size_t buffer_size = 0;
    int intersection_index = 0;
    Page **intersection_pages = calloc(num_pages, sizeof(Page *));
    if (intersection_pages == NULL)
        exit(printf("Error run_search_engine: failed to allocate memory.\n"));
    void *args[2] = {intersection_pages, &intersection_index};

    while (getline(&buffer, &buffer_size, stdin) != -1) {
        query = strdup(buffer);
        remove_newline(query);

        int num_terms = 0; // Contador de termos válidos
        token = strtok(buffer, " \n");
        bool search_success = false;
        while (token) {
            string_to_lower(token);
            if (!stop_word_contains(stop_words, token)) {
                // Busca as páginas associadas ao termo se ele não for uma stopword
                RBT *term_pages = string_map_search(sm, token);
                if (term_pages) {
                    apply_to_all_pages(term_pages, process_intersection, args);
                    num_terms++;
                    search_success = true;
                } else {
                    search_success = false;
                    break;
                }
            }
            token = strtok(NULL, " \n");
        }
        if (search_success)
            qsort(intersection_pages, intersection_index, sizeof(Page *), pages_comparator);
        display_search_results(query, intersection_pages, intersection_index, num_terms, search_success);

        // Reseta o índice de interseção para a próxima consulta
        intersection_index = 0;
        free(query);
    }

    free(buffer);
    free(intersection_pages);
}
