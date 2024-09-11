#if !defined(_UTILS_H_)
#define _UTILS_H_

#include "rbt.h"
#include "types.h"

/**
 * @brief Converte uma string para letras minúsculas.
 *
 * Esta função percorre cada caractere da string fornecida e converte
 * todos os caracteres alfabéticos para suas respectivas letras minúsculas.
 *
 * @param str A string a ser convertida.
 */
void string_to_lower(char *str);

/**
 * @brief Aplica uma função a todas as páginas de uma árvore rubro-negra.
 *
 * Esta função itera sobre todas as páginas em uma árvore rubro-negra (RBT)
 * e aplica a função fornecida a cada página.
 *
 * @param pages A árvore rubro-negra contendo as páginas.
 * @param function A função a ser aplicada a cada página.
 * @param argument Um argumento adicional a ser passado para a função.
 */
void apply_to_all_pages(RBT *pages, Func function, void *argument);

/**
 * @brief Calcula o valor absoluto de um número de ponto flutuante.
 *
 * Esta função retorna o valor absoluto do número de ponto flutuante fornecido.
 *
 * @param x O número de ponto flutuante.
 * @return O valor absoluto de x.
 */
double fabs(double x);

#endif // _UTILS_H_