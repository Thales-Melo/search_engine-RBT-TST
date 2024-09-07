#if !defined(STRING_MAP_H_)
#define STRING_MAP_H_

#include "stop_word.h"
#include "rbt.h"
#include "page_map.h"

typedef struct StringMap StringMap;

void string_map_destruct(StringMap *sm);
RBT *string_map_search(StringMap *sm, char *word);
StringMap *string_map_build(char *main_dir, StopWord *stop_words, PageMap *pm, int *num_pages);

#endif // STRING_MAP_H_
