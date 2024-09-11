#if !defined(_PAGE_RANK_H_)
#define _PAGE_RANK_H_

#include "string_map.h"
#include "stop_word.h"

/**
 * @brief Calcula o PageRank das páginas em um mapa de páginas.
 *
 * Esta função calcula o PageRank de cada página no mapa de páginas fornecido,
 * utilizando o algoritmo de PageRank. O cálculo é iterativo e continua até que
 * a diferença entre os valores de PageRank de duas iterações consecutivas seja
 * menor que um limite predefinido.
 *
 * @param num_pages O número total de páginas no mapa.
 * @param pm Um ponteiro para a estrutura PageMap contendo as páginas.
 */
void calculate_page_ranks(int num_pages, PageMap *pm);

#endif // _PAGE_RANK_H_