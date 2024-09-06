#if !defined(_TST_H_)
#define _TST_H_

#include "types.h"
#include <stdbool.h>

typedef struct node TST;

TST *TST_construct();
void TST_destruct(TST* t, void (*free_value)(Value));
TST* TST_insert(TST* t, const char* key , Value val);
Value TST_search(TST* t, const char* key);
bool TST_contains(TST* t, const char* key);
void TST_print_keys(TST* t);

#endif // _TST_H_
