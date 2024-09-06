#if !defined(_STOP_WORD_H_)
#define _STOP_WORD_H_

#include <stdbool.h>

typedef struct StopWord StopWord;

StopWord *stop_word_read(char *main_dir);
void stop_word_destruct(StopWord *sw);
bool stop_word_contains(StopWord *sw, const char *word);

#endif // _STOP_WORD_H_
