#if !defined(_RBT_H_)
#define _RBT_H_

#include <stdbool.h>
#include "types.h"

typedef struct RBT RBT;


RBT *rbt_construct();

void rbt_destruct(RBT *rbt);

void rbt_insert(RBT *rbt, void *key, Value value);

Value rbt_search(RBT *rbt, void *key);

#endif // _RBT_H_
