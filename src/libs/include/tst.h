#if !defined(_TST_H_)
#define _TST_H_

typedef struct TST TST;

#include "types.h"
#include "string.h"


TST *tst_construct();

void tst_destruct(TST *tst);

void TST_insert(TST* t, String* key , Value val);

Value TST_search(TST* t, String* key);

#endif // _TST_H_
