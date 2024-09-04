#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/tst.h"


typedef struct TS_Node TS_Node;

struct TS_Node {
    unsigned char c;
    Value value;
    TS_Node *l, *m, *r;
};


struct TST {
    TS_Node *root;
    int size;
};


TS_Node *ts_node_construct(unsigned char c, Value value) {
    TS_Node *node = malloc(sizeof(TS_Node));
    if (node == NULL)
        exit(printf("Error ts_node_construct: failed to allocate memory.\n"));
    node->c = c;
    node->value = value;
    node->l = node->m = node->r = NULL;
    return node;
}

void ts_node_destruct(TS_Node *node) {
    if (node == NULL)
        return;
    ts_node_destruct(node->l);
    ts_node_destruct(node->m);
    ts_node_destruct(node->r);
    free(node);
}

TST *tst_construct() {
    TST *tst = malloc(sizeof(TST));
    if (tst == NULL)
        exit(printf("Error tst_construct: failed to allocate memory.\n"));
    tst->root = NULL;
    tst->size = 0;
    return tst;
}

void tst_destruct(TST *tst) {
    if (tst == NULL)
        return;
    ts_node_destruct(tst->root);
    free(tst);
}

TS_Node* rec_insert(TST* t, String* key, Value val, int d) {
    if (t == NULL)          return NULL;
    if (key == NULL)        return NULL;

    if (key->len == 0)      return NULL;
    if (t->root == NULL)    t->root = ts_node_construct(key->c[d], NULL);
    
    if (key->c[d] < t->root->c)         t->root->l = rec_insert(t, key, val, d);
    else if (key->c[d] > t->root->c)    t->root->r = rec_insert(t, key, val, d);
    else if (d < key->len - 1)          t->root->m = rec_insert(t, key, val, d + 1);
    else                                t->root->value = val;
    return t->root;
}

void TST_insert(TST* t, String* key , Value val) {
    rec_insert(t, key, val, 0);
}

TST* rec_search(TST* t, String* key, int d) {
    if (t == NULL)          return NULL;
    if (key == NULL)        return t;

    if (key->len == 0)      return t;
    if (t->root == NULL)    return NULL;
    
    if (key->c[d] < t->root->c)         return rec_search(t, key, d);
    else if (key->c[d] > t->root->c)    return rec_search(t, key, d);
    else if (d < key->len - 1)          return rec_search(t, key, d + 1);
    else                                return t;
}

Value TST_search(TST* t, String* key) {
    TST* res = rec_search(t, key, 0);
    if (res == NULL) return NULL;
    return res->root->value;
}
