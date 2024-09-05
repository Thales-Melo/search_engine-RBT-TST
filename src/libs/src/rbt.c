#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/rbt.h"

struct node {
    char *key;
    Value value;
    bool color;
    RBT *l, *r;
};

RBT *RBT_construct() {
    return NULL;
}

void RBT_destruct(RBT *rbt, void (*free_value)(Value)) {
    if (rbt == NULL)
        return;
    RBT_destruct(rbt->l, free_value);
    RBT_destruct(rbt->r, free_value);
    free(rbt->key);
    if (free_value != NULL)
        free_value(rbt->value);
    free(rbt);
}

RBT *RBT_create_node(char *key, Value value, bool color) {
    RBT *node = malloc(sizeof(RBT));
    if (node == NULL)
        exit(printf("Error RBT_create_node: failed to allocate memory.\n"));
    node->key = key;
    node->value = value;
    node->color = color;
    node->l = node->r = NULL;
    return node;
}

bool is_red(RBT *node) {
    return node == NULL ? BLACK : node->color;
}

void color_flip(RBT *node) {
    node->color = !node->color;
    node->l->color = !node->l->color;
    node->r->color = !node->r->color;
}

RBT *rotate_left(RBT *h) {
    RBT *x = h->r;
    h->r = x->l;
    x->l = h;
    x->color = h->color;
    h->color = RED;
    return x;
}

RBT *rotate_right(RBT *h) {
    RBT *x = h->l;
    h->l = x->r;
    x->r = h;
    x->color = h->color;
    h->color = RED;
    return x;
}

RBT *RBT_insert(RBT *h, char *key, Value value, int (*cmp)(const char *, const char *)) {
    if (h == NULL) {
        return RBT_create_node(key, value, RED);
    }

    int cmp_result = cmp(key, h->key);
    if (cmp_result < 0) {
        h->l = RBT_insert(h->l, key, value, cmp);
    } else if (cmp_result > 0) {
        h->r = RBT_insert(h->r, key, value, cmp);
    } else {
        h->value = value;
    }

    if (is_red(h->r) && !is_red(h->l)) {
        h = rotate_left(h);
    }
    if (is_red(h->l) && is_red(h->l->l)) {
        h = rotate_right(h);
    }
    if (is_red(h->l) && is_red(h->r)) {
        color_flip(h);
    }

    return h;
}

Value RBT_search(RBT *rbt, char *key, CompareFunc comp) {
    if (rbt == NULL)    return NULL;
    int cmp = comp(key, rbt->key);
    if (cmp < 0)        return RBT_search(rbt->l, key, comp);
    else if (cmp > 0)   return RBT_search(rbt->r, key, comp);
    else                return rbt->value;
}

bool RBT_contains_key(RBT *rbt, char *key, CompareFunc comp) {
    return RBT_search(rbt, key, comp) != NULL;
}

void RBT_print_keys(RBT *rbt) {
    if (rbt == NULL) return;
    RBT_print_keys(rbt->l);
    printf("%s\n", rbt->key);
    RBT_print_keys(rbt->r);
}