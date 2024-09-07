#if !defined(_SEARCH_ENGINE_H_)
#define _SEARCH_ENGINE_H_

#include "string_map.h"
#include "stop_word.h"

void calculate_page_ranks(int num_pages, PageMap *pm);

#endif // _SEARCH_ENGINE_H_
