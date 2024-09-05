#if !defined(_STOP_WORD_H_)
#define _STOP_WORD_H_

typedef struct StopWord StopWord;

StopWord *stop_word_read(char *main_dir);
void stop_word_destruct(StopWord *sw);
#endif // _STOP_WORD_H_
