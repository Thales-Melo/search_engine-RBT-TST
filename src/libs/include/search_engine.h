#if !defined(_SEARCH_ENGINE_H_)
#define _SEARCH_ENGINE_H_


#include "stop_word.h"
#include "string_map.h"

void run_search_engine(StringMap *sm, StopWord *stop_words, int num_pages);

#endif // _SEARCH_ENGINE_H_
