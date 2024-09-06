#if !defined(STRING_MAP_H_)
#define STRING_MAP_H_

typedef struct StringMap StringMap;

void string_map_destruct(StringMap *sm);
StringMap *string_map_build(char *main_dir, StopWord *stop_words);

#endif // STRING_MAP_H_
