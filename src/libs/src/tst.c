#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/tst.h"

struct node {
    Value val;
    unsigned char c;
    TST *l, *m, *r;
};

TST *TST_construct() {
    return NULL;
}

void rec_destruct(TST* t, void (*free_value)(Value)) {
    if (t == NULL) return;
    rec_destruct(t->l, free_value);
    rec_destruct(t->m, free_value);
    rec_destruct(t->r, free_value);
    if (free_value != NULL)
        free_value(t->val);
    free(t);
}

void TST_destruct(TST* t, void (*free_value)(Value)) {
    rec_destruct(t, free_value);
}

TST* create_node() {
    TST* t = (TST*) malloc(sizeof(TST));
    if (t == NULL)
        exit(printf("Error create_node: failed to allocate memory.\n"));
    
    t->val = NULL_Value;
    t->c = 0;
    t->l = t->m = t->r = NULL;
    return t;
}

TST* rec_insert(TST* t, const char* key, Value val, int d, int len) {
    unsigned char c = key[d];
    if (t == NULL) {
        t = create_node();
        t->c = c;
    }
    if (c < t->c)                      { t->l = rec_insert(t->l, key, val, d, len); }
    else if (c > t->c)                 { t->r = rec_insert(t->r, key, val, d, len); }
    else if (d < len - 1)              { t->m = rec_insert(t->m, key, val, d+1, len); }
    else                               { t->val = val; }
    return t;
}

TST* TST_insert(TST* t, const char* key , Value val) {
    int len = strlen(key);
    return rec_insert(t, key, val, 0, len);
}

TST* rec_search(TST* t, const char* key, int d, int len) {
    if (t == NULL) return NULL;
    unsigned char c = key[d];
    if (c < t->c)                       return rec_search(t->l, key, d, len);
    else if (c > t->c)                  return rec_search(t->r, key, d, len);
    else if (d < len - 1)               return rec_search(t->m, key, d+1, len);
    else                                return t;
}

Value TST_search(TST* t, const char* key) {
    int len = strlen(key);
    TST* x = rec_search(t, key, 0, len);
    if (x == NULL) return NULL_Value;
    return x->val;
}

bool TST_contains(TST* t, const char* key) {
    return TST_search(t, key) != NULL_Value;
}

void rec_print_keys(TST* t, char* prefix, int d) {
    if (t == NULL) return;
    rec_print_keys(t->l, prefix, d);
    prefix[d] = t->c;
    if (t->val != NULL_Value) {
        prefix[d+1] = '\0';
        printf("%s\n", prefix);
    }
    rec_print_keys(t->m, prefix, d+1);
    rec_print_keys(t->r, prefix, d);
}

void TST_print_keys(TST* t) {
    char prefix[100];
    rec_print_keys(t, prefix, 0);
}
