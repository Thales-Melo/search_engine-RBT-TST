#if !defined(_PAGE_MAP_H_)
#define _PAGE_MAP_H_

#include "rbt.h"
#include "page.h"

/**
 * @brief Estrutura para armazenar o mapa de páginas.
 */
typedef struct PageMap PageMap;

/**
 * @brief Constrói um mapa de páginas a partir de um diretório principal.
 *
 * Esta função lê um arquivo de grafo localizado no diretório principal fornecido
 * e constrói um mapa de páginas com base nas informações do arquivo.
 *
 * @param main_dir O diretório principal onde o arquivo de grafo está localizado.
 * @return Um ponteiro para a estrutura PageMap construída.
 */
PageMap *build_link_pages(char *main_dir);

/**
 * @brief Destrói um mapa de páginas.
 *
 * Esta função libera toda a memória alocada para o mapa de páginas e seus componentes.
 *
 * @param pm Um ponteiro para o mapa de páginas a ser destruído.
 */
void page_map_destruct(PageMap *pm);

/**
 * @brief Obtém uma página do mapa de páginas pelo nome.
 *
 * Esta função busca e retorna uma página do mapa de páginas com base no nome fornecido.
 *
 * @param pm Um ponteiro para o mapa de páginas.
 * @param page_name O nome da página a ser buscada.
 * @return Um ponteiro para a página encontrada, ou NULL se a página não for encontrada.
 */
Page* page_map_get_page(PageMap *pm, char *page_name);

/**
 * @brief Obtém todas as páginas do mapa de páginas.
 *
 * Esta função retorna a árvore rubro-negra contendo todas as páginas do mapa de páginas.
 *
 * @param pm Um ponteiro para o mapa de páginas.
 * @return Um ponteiro para a árvore rubro-negra contendo todas as páginas.
 */
RBT *page_map_get_pages(PageMap *pm);

#endif // _PAGE_MAP_H_