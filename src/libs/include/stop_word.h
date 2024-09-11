#if !defined(_STOP_WORD_H_)
#define _STOP_WORD_H_

#include <stdbool.h>

/**
 * @brief Estrutura para armazenar palavras de parada (stop words).
 */
typedef struct StopWord StopWord;

/**
 * @brief Lê as palavras de parada de um diretório especificado.
 *
 * Esta função lê as palavras de parada de um arquivo localizado no diretório especificado
 * e as armazena em uma estrutura StopWord.
 *
 * @param main_dir O diretório principal onde o arquivo de palavras de parada está localizado.
 * @return Um ponteiro para a estrutura StopWord contendo as palavras de parada.
 */
StopWord *stop_word_read(char *main_dir);

/**
 * @brief Destrói a estrutura StopWord.
 *
 * Esta função libera toda a memória alocada para a estrutura StopWord.
 *
 * @param sw Um ponteiro para a estrutura StopWord a ser destruída.
 */
void stop_word_destruct(StopWord *sw);

/**
 * @brief Verifica se uma palavra está presente na estrutura StopWord.
 *
 * Esta função verifica se a palavra fornecida está presente na estrutura StopWord.
 *
 * @param sw Um ponteiro para a estrutura StopWord.
 * @param word A palavra a ser verificada.
 * @return true se a palavra estiver presente, false caso contrário.
 */
bool stop_word_contains(StopWord *sw, const char *word);

#endif // _STOP_WORD_H_