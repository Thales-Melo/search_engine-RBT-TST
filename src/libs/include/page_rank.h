#if !defined(_PAGE_RANK_H_)
#define _PAGE_RANK_H_

#include "string_map.h"
#include "stop_word.h"

void calculate_page_ranks(int num_pages, PageMap *pm);

#endif // _PAGE_RANK_H_
