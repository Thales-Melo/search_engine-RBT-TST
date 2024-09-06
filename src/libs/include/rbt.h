#if !defined(_RBT_H_)
#define _RBT_H_

#include <stdbool.h>
#include "types.h"

typedef struct node RBT;

RBT *RBT_construct();
void RBT_destruct(RBT *rbt, void (*free_value)(Value)) ;
RBT *RBT_insert(RBT *rbt, char *key, Value val, CompareFunc comp);
Value RBT_search(RBT *rbt, char *key, CompareFunc comp);
bool RBT_contains_key(RBT *rbt, char *key, CompareFunc comp);
void RBT_print_keys(RBT *rbt);



typedef struct RBTIterator RBTIterator;

RBTIterator* RBT_iterator_create(RBT *root);
Value RBT_iterator_value(RBTIterator *iter);
bool RBT_iterator_next(RBTIterator *iter);
bool RBT_iterator_valid(RBTIterator *iter);
char* RBT_iterator_key(RBTIterator *iter);
void RBT_iterator_destroy(RBTIterator *iter);

#endif // _RBT_H_
