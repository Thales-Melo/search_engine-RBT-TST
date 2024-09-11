#if !defined(STRING_MAP_H_)
#define STRING_MAP_H_

#include "stop_word.h"
#include "rbt.h"
#include "page_map.h"

/**
 * @brief Estrutura para armazenar o mapa de strings.
 */
typedef struct StringMap StringMap;

/**
 * @brief Destrói um mapa de strings.
 *
 * Esta função libera toda a memória alocada para o mapa de strings e seus componentes.
 *
 * @param sm Um ponteiro para o mapa de strings a ser destruído.
 */
void string_map_destruct(StringMap *sm);

/**
 * @brief Busca um conjunto de páginas associadas a uma palavra no mapa de strings.
 *
 * Esta função busca e retorna um conjunto de páginas (RBT) associadas à palavra fornecida.
 *
 * @param sm Um ponteiro para o mapa de strings.
 * @param word A palavra a ser buscada.
 * @return Um ponteiro para a árvore rubro-negra (RBT) contendo as páginas associadas à palavra,
 *         ou NULL se a palavra não for encontrada.
 */
RBT *string_map_search(StringMap *sm, char *word);

/**
 * @brief Constrói um mapa de strings a partir de um diretório principal.
 *
 * Esta função lê arquivos de páginas localizados no diretório principal fornecido,
 * filtra palavras de parada e constrói um mapa de strings com base nas palavras encontradas.
 *
 * @param main_dir O diretório principal onde os arquivos de páginas estão localizados.
 * @param stop_words Um ponteiro para a estrutura StopWord contendo as palavras de parada.
 * @param pm Um ponteiro para a estrutura PageMap contendo o mapa de páginas.
 * @param num_pages Um ponteiro para um inteiro onde o número de páginas será armazenado.
 * @return Um ponteiro para a estrutura StringMap construída.
 */
StringMap *string_map_build(char *main_dir, StopWord *stop_words, PageMap *pm, int *num_pages);

#endif // STRING_MAP_H_