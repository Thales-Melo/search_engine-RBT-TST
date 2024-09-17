#if !defined(_RBT_H_)
#define _RBT_H_

#include <stdbool.h>
#include "types.h"

/**
 * @brief Estrutura de nó da árvore rubro-negra (RBT).
 */
typedef struct node RBT;

/**
 * @brief Constrói uma nova árvore rubro-negra (RBT).
 *
 * @return Um ponteiro para a nova árvore RBT.
 */
RBT *RBT_construct();

/**
 * @brief Destrói uma árvore rubro-negra (RBT).
 *
 * Esta função libera toda a memória alocada para a árvore RBT e seus nós.
 *
 * @param rbt Um ponteiro para a árvore RBT a ser destruída.
 * @param free_value Uma função para liberar a memória dos valores armazenados nos nós.
 */
void RBT_destruct(RBT *rbt, void (*free_value)(Value));

/**
 * @brief Insere uma chave e um valor na árvore rubro-negra (RBT).
 *
 * Esta função insere a chave e o valor fornecidos na árvore RBT.
 *
 * @param rbt Um ponteiro para a árvore RBT.
 * @param key A chave a ser inserida.
 * @param val O valor a ser associado à chave.
 * @param comp Uma função de comparação para as chaves.
 * @return Um ponteiro para a árvore RBT atualizada.
 */
RBT *RBT_insert(RBT *rbt, char *key, Value val, CompareFunc comp);

/**
 * @brief Busca um valor na árvore rubro-negra (RBT) usando uma chave.
 *
 * Esta função busca o valor associado à chave fornecida na árvore RBT.
 *
 * @param rbt Um ponteiro para a árvore RBT.
 * @param key A chave a ser buscada.
 * @param comp Uma função de comparação para as chaves.
 * @return O valor associado à chave, ou NULL se a chave não for encontrada.
 */
Value RBT_search(RBT *rbt, char *key, CompareFunc comp);

/**
 * @brief Verifica se uma chave está presente na árvore rubro-negra (RBT).
 *
 * Esta função verifica se a chave fornecida está presente na árvore RBT.
 *
 * @param rbt Um ponteiro para a árvore RBT.
 * @param key A chave a ser verificada.
 * @param comp Uma função de comparação para as chaves.
 * @return true se a chave estiver presente, false caso contrário.
 */
bool RBT_contains_key(RBT *rbt, char *key, CompareFunc comp);

/**
 * @brief Imprime todas as chaves presentes na árvore rubro-negra (RBT).
 *
 * Esta função imprime todas as chaves armazenadas na árvore RBT.
 *
 * @param rbt Um ponteiro para a árvore RBT.
 */
void RBT_print_keys(RBT *rbt);

/**
 * @brief Estrutura de iterador para a árvore rubro-negra (RBT).
 */
typedef struct RBTIterator RBTIterator;

/**
 * @brief Cria um iterador para a árvore rubro-negra (RBT).
 *
 * Esta função cria um iterador para percorrer a árvore RBT.
 *
 * @param root Um ponteiro para a raiz da árvore RBT.
 * @return Um ponteiro para o iterador criado.
 */
RBTIterator* RBT_iterator_construct(RBT *root);

/**
 * @brief Obtém o valor atual do iterador.
 *
 * Esta função retorna o valor associado ao nó atual do iterador.
 *
 * @param iter Um ponteiro para o iterador.
 * @return O valor associado ao nó atual.
 */
Value RBT_iterator_value(RBTIterator *iter);

/**
 * @brief Avança o iterador para o próximo nó.
 *
 * Esta função avança o iterador para o próximo nó na árvore RBT.
 *
 * @param iter Um ponteiro para o iterador.
 * @return true se o iterador foi avançado com sucesso, false se não houver mais nós.
 */
bool RBT_iterator_next(RBTIterator *iter);

/**
 * @brief Verifica se o iterador é válido.
 *
 * Esta função verifica se o iterador está em um estado válido.
 *
 * @param iter Um ponteiro para o iterador.
 * @return true se o iterador for válido, false caso contrário.
 */
bool RBT_iterator_valid(RBTIterator *iter);

/**
 * @brief Obtém a chave atual do iterador.
 *
 * Esta função retorna a chave associada ao nó atual do iterador.
 *
 * @param iter Um ponteiro para o iterador.
 * @return A chave associada ao nó atual.
 */
char* RBT_iterator_key(RBTIterator *iter);

/**
 * @brief Destroi o iterador da árvore rubro-negra (RBT).
 *
 * Esta função libera toda a memória alocada para o iterador.
 *
 * @param iter Um ponteiro para o iterador a ser destruído.
 */
void RBT_iterator_destruct(RBTIterator *iter);

#endif // _RBT_H_