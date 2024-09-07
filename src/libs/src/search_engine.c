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
    int intersec_counter = page_get_intersection_counter(p); // Contador de interseções da página

    // Se a página ainda não fez parte de nenhuma interseção
    if (intersec_counter == 0) {
        // Adiciona a página ao vetor de interseção e incrementa o índice
        pages[*index] = p;
        (*index)++;
    }
    
    // Incrementa o contador de interseções da página
    page_set_intersection_counter(p, intersec_counter + 1);
}

void display_search_results(char *query, Page **pages, int total_pages, int expected_intersection_count) {
    printf("search: %s\n", query);
    printf("pages: ");

    int printed_pages = 0;
    
    // Itera pelo vetor de páginas para imprimir as que fazem parte da interseção esperada
    for (int i = 0; i < total_pages; i++) {
        Page *p = pages[i];
        
        // Verifica se o contador de interseções da página é igual ao número de termos buscados
        if (page_get_intersection_counter(p) == expected_intersection_count) {
            if (printed_pages > 0) printf(" ");
            printf("%s", page_get_name(p));
            printed_pages++;
        }
    }

    printf("\npr: ");
    
    // Itera novamente para imprimir o PageRank das páginas que fazem parte da interseção
    for (int i = 0; i < total_pages; i++) {
        Page *p = pages[i];
        
        // Verifica novamente se a página está na interseção
        if (page_get_intersection_counter(p) == expected_intersection_count) {
            if (i > 0) printf(" ");
            printf("%.16lf", page_get_page_rank(p));
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

    // Vetor para armazenar as páginas que fazem parte da interseção
    Page **intersection_pages = calloc(num_pages, sizeof(Page *));
    int intersection_index = 0;

    void *args[2] = {intersection_pages, &intersection_index};

    while (getline(&buffer, &buffer_size, stdin) != -1) {
        query = strdup(buffer);

        int num_terms = 0; // Contador de termos válidos
        token = strtok(buffer, " \n");
        
        while (token) {
            // Se o token não for uma stopword
            if (!stop_word_contains(stop_words, token)) {
                // Busca as páginas associadas ao termo no mapa de strings
                RBT *term_pages = string_map_search(sm, token);
                if (term_pages) {
                    // Aplica a função de processamento de interseção nas páginas encontradas
                    apply_to_all_pages(term_pages, process_intersection, args);
                    num_terms++; // Incrementa o contador de termos válidos
                }
            }
            token = strtok(NULL, " \n");
        }

        display_search_results(query, intersection_pages, intersection_index, num_terms);
        
        // Reseta o índice de interseção para a próxima consulta
        intersection_index = 0;
        free(query);
    }

    free(buffer);
    free(intersection_pages);
}
