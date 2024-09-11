#if !defined(_SEARCH_ENGINE_H_)
#define _SEARCH_ENGINE_H_

#include "stop_word.h"
#include "string_map.h"

/**
 * @brief Executa o motor de busca.
 *
 * Esta função lê consultas da entrada padrão, processa cada consulta para encontrar páginas
 * relevantes, calcula interseções de páginas com base nos termos da consulta e exibe os resultados.
 *
 * @param sm Um ponteiro para a estrutura StringMap contendo o mapa de strings.
 * @param stop_words Um ponteiro para a estrutura StopWord contendo as palavras de parada.
 * @param num_pages O número total de páginas no mapa.
 */
void run_search_engine(StringMap *sm, StopWord *stop_words, int num_pages);

#endif // _SEARCH_ENGINE_H_