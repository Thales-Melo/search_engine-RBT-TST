#if !defined(_PAGE_H_)
#define _PAGE_H_

/**
 * @brief Estrutura de dados que representa uma página.
 */
typedef struct Page Page;

#include "rbt.h"

/**
 * @brief Constrói uma nova página.
 *
 * Esta função aloca memória e inicializa uma nova página com o nome fornecido.
 *
 * @param page_name O nome da página a ser criada.
 * @return Um ponteiro para a nova página.
 */
Page* page_construct(char *page_name);

/**
 * @brief Destrói uma página.
 *
 * Esta função libera toda a memória alocada para a página e seus componentes.
 *
 * @param page Um ponteiro para a página a ser destruída.
 */
void page_destruct(Page *page);

/**
 * @brief Obtém os links de entrada de uma página.
 *
 * Esta função retorna a árvore rubro-negra contendo os links de entrada da página.
 *
 * @param page Um ponteiro para a página.
 * @return Um ponteiro para a árvore rubro-negra contendo os links de entrada.
 */
RBT *page_get_in_links(Page *page);

/**
 * @brief Obtém os links de saída de uma página.
 *
 * Esta função retorna a árvore rubro-negra contendo os links de saída da página.
 *
 * @param page Um ponteiro para a página.
 * @return Um ponteiro para a árvore rubro-negra contendo os links de saída.
 */
RBT *page_get_out_links(Page *page);

/**
 * @brief Obtém o PageRank de uma página.
 *
 * Esta função retorna o valor do PageRank da página.
 *
 * @param page Um ponteiro para a página.
 * @return O valor do PageRank da página.
 */
double page_get_page_rank(Page *page);

/**
 * @brief Obtém o número de links de entrada de uma página.
 *
 * Esta função retorna o número de links de entrada da página.
 *
 * @param page Um ponteiro para a página.
 * @return O número de links de entrada da página.
 */
int page_get_num_in_links(Page *page);

/**
 * @brief Obtém o número de links de saída de uma página.
 *
 * Esta função retorna o número de links de saída da página.
 *
 * @param page Um ponteiro para a página.
 * @return O número de links de saída da página.
 */
int page_get_num_out_links(Page *page);

/**
 * @brief Obtém o último valor de PageRank de uma página.
 *
 * Esta função retorna o último valor de PageRank da página.
 *
 * @param page Um ponteiro para a página.
 * @return O último valor de PageRank da página.
 */
double page_get_last_page_rank(Page *page);

/**
 * @brief Obtém o contador de interseção de uma página.
 *
 * Esta função retorna o valor do contador de interseção da página.
 *
 * @param page Um ponteiro para a página.
 * @return O valor do contador de interseção da página.
 */
int page_get_intersection_counter(Page *page);

/**
 * @brief Define o valor do contador de interseção de uma página.
 *
 * Esta função define o valor do contador de interseção da página.
 *
 * @param page Um ponteiro para a página.
 * @param value O valor a ser definido para o contador de interseção.
 */
void page_set_intersection_counter(Page *page, int value);

/**
 * @brief Define o número de links de saída de uma página.
 *
 * Esta função define o número de links de saída da página.
 *
 * @param page Um ponteiro para a página.
 * @param num_out_links O número de links de saída a ser definido.
 */
void page_set_num_out_links(Page *page, int num_out_links);

/**
 * @brief Define o número de links de entrada de uma página.
 *
 * Esta função define o número de links de entrada da página.
 *
 * @param page Um ponteiro para a página.
 * @param num_in_links O número de links de entrada a ser definido.
 */
void page_set_num_in_links(Page *page, int num_in_links);

/**
 * @brief Define o valor do PageRank de uma página.
 *
 * Esta função define o valor do PageRank da página.
 *
 * @param page Um ponteiro para a página.
 * @param pr O valor do PageRank a ser definido.
 */
void page_set_page_rank(Page *page, double pr);

/**
 * @brief Define o último valor de PageRank de uma página.
 *
 * Esta função define o último valor de PageRank da página.
 *
 * @param page Um ponteiro para a página.
 * @param last_pr O último valor de PageRank a ser definido.
 */
void page_set_last_page_rank(Page *page, double last_pr);

/**
 * @brief Obtém o nome de uma página.
 *
 * Esta função retorna o nome da página.
 *
 * @param page Um ponteiro para a página.
 * @return O nome da página.
 */
char *page_get_name(Page *page);

/**
 * @brief Insere um link de entrada em uma página.
 *
 * Esta função insere um link de entrada na página fornecida.
 *
 * @param page Um ponteiro para a página.
 * @param in Um ponteiro para a página de entrada.
 */
void page_insert_in_link(Page *page, Page *in);

/**
 * @brief Insere um link de saída em uma página.
 *
 * Esta função insere um link de saída na página fornecida.
 *
 * @param page Um ponteiro para a página.
 * @param out Um ponteiro para a página de saída.
 */
void page_insert_out_link(Page *page, Page *out);

/**
 * @brief Atualiza o último valor de PageRank de uma página.
 *
 * Esta função atualiza o último valor de PageRank da página com o valor atual.
 *
 * @param page Um ponteiro para a página.
 */
void page_update_last_page_rank(Page *page);

/**
 * @brief Compara duas páginas com base em seus valores de PageRank.
 *
 * Esta função compara duas páginas e retorna um valor indicando a ordem relativa
 * com base em seus valores de PageRank.
 *
 * @param p1 Um ponteiro para a primeira página.
 * @param p2 Um ponteiro para a segunda página.
 * @return Um valor negativo se a primeira página tiver um PageRank maior,
 *         um valor positivo se a segunda página tiver um PageRank maior,
 *         ou zero se ambos os PageRanks forem iguais.
 */
int pages_comparator(const void *p1, const void *p2);

#endif // _PAGE_H_