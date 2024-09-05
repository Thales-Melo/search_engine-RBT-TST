#if !defined(_TST_H_)
#define _TST_H_

typedef struct node TST;

#include "types.h"


TST *tst_construct();

void tst_destruct(TST *tst);

TST* TST_insert(TST* t, const char* key , Value val);

Value TST_search(TST* t, const char* key);

#endif // _TST_H_
