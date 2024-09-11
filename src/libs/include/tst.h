#if !defined(_TST_H_)
#define _TST_H_

#include "types.h"
#include <stdbool.h>

/**
 * @brief Estrutura de nó da árvore ternária de busca (TST).
 */
typedef struct node TST;

/**
 * @brief Constrói uma nova árvore ternária de busca (TST).
 *
 * @return Um ponteiro para a nova árvore TST.
 */
TST *TST_construct();

/**
 * @brief Destrói uma árvore ternária de busca (TST).
 *
 * Esta função libera toda a memória alocada para a árvore TST e seus nós.
 *
 * @param t Um ponteiro para a árvore TST a ser destruída.
 * @param free_value Uma função para liberar a memória dos valores armazenados nos nós.
 */
void TST_destruct(TST* t, void (*free_value)(Value));

/**
 * @brief Insere uma chave e um valor na árvore ternária de busca (TST).
 *
 * Esta função insere a chave e o valor fornecidos na árvore TST.
 *
 * @param t Um ponteiro para a árvore TST.
 * @param key A chave a ser inserida.
 * @param val O valor a ser associado à chave.
 * @return Um ponteiro para a árvore TST atualizada.
 */
TST* TST_insert(TST* t, const char* key , Value val);

/**
 * @brief Busca um valor na árvore ternária de busca (TST) usando uma chave.
 *
 * Esta função busca o valor associado à chave fornecida na árvore TST.
 *
 * @param t Um ponteiro para a árvore TST.
 * @param key A chave a ser buscada.
 * @return O valor associado à chave, ou NULL_Value se a chave não for encontrada.
 */
Value TST_search(TST* t, const char* key);

/**
 * @brief Verifica se uma chave está presente na árvore ternária de busca (TST).
 *
 * Esta função verifica se a chave fornecida está presente na árvore TST.
 *
 * @param t Um ponteiro para a árvore TST.
 * @param key A chave a ser verificada.
 * @return true se a chave estiver presente, false caso contrário.
 */
bool TST_contains(TST* t, const char* key);

/**
 * @brief Imprime todas as chaves presentes na árvore ternária de busca (TST).
 *
 * Esta função imprime todas as chaves armazenadas na árvore TST.
 *
 * @param t Um ponteiro para a árvore TST.
 */
void TST_print_keys(TST* t);

#endif // _TST_H_