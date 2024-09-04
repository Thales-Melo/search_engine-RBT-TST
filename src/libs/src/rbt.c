#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/rbt.h"

#define RED true
#define BLACK false

typedef struct RB_Node RB_Node;
struct RB_Node {
    void *key;
    Value value;
    bool color;
    RB_Node *l, *r;
};

struct RBT {
    RB_Node *root;
    int size;
};


RB_Node *rb_node_construct(void *key, Value value, bool color) {
    RB_Node *node = malloc(sizeof(RB_Node));
    if (node == NULL)
        exit(printf("Error rb_node_construct: failed to allocate memory.\n"));
    node->key = key;
    node->value = value;
    node->color = color;
    node->l = node->r = NULL;
    return node;
}

void rb_node_destruct(RB_Node *node) {
    if (node == NULL)
        return;
    rb_node_destruct(node->l);
    rb_node_destruct(node->r);
    free(node);
}

RBT *rbt_construct() {
    RBT *rbt = malloc(sizeof(RBT));
    if (rbt == NULL)
        exit(printf("Error rbt_construct: failed to allocate memory.\n"));
    rbt->root = NULL;
    rbt->size = 0;
    return rbt;
}

void rbt_destruct(RBT *rbt) {
    if (rbt == NULL)
        return;
    rb_node_destruct(rbt->root);
    free(rbt);
}

bool is_red(RB_Node *node) {
    return node == NULL ? BLACK : node->color;
}

RB_Node *rotate_left(RB_Node *node) {
    RB_Node *x = node->r;
    node->r = x->l;
    x->l = node;
    x->color = node->color;
    node->color = RED;
    return x;
}

RB_Node *rotate_right(RB_Node *node) {
    RB_Node *x = node->l;
    node->l = x->r;
    x->r = node;
    x->color = node->color;
    node->color = RED;
    return x;
}

void flip_colors(RB_Node *node) {
    node->color = RED;
    node->l->color = BLACK;
    node->r->color = BLACK;
}

RB_Node *rec_rbt_insert(RBT *rbt, RB_Node *node, void *key, Value value) {
    if (node == NULL) {
        rbt->size++;
        return rb_node_construct(key, value, RED);
    }

    if (key < node->key)        node->l = rec_rbt_insert(rbt, node->l, key, value);
    else if (key > node->key)   node->r = rec_rbt_insert(rbt, node->r, key, value);
    else                        node->value = value;

    if (is_red(node->r) && !is_red(node->l))        node = rotate_left(node);
    if (is_red(node->l) && is_red(node->l->l))       node = rotate_right(node);
    if (is_red(node->l) && is_red(node->r))          flip_colors(node);

    return node;
}

void rbt_insert(RBT *rbt, void *key, Value value) {
    rbt->root = rec_rbt_insert(rbt, rbt->root, key, value);
    rbt->root->color = BLACK;
}

Value rec_rbt_search(RB_Node *node, void *key) {
    if (node == NULL)           return NULL;
    if (key < node->key)        return rec_rbt_search(node->l, key);
    else if (key > node->key)   return rec_rbt_search(node->r, key);
    else                        return node->value;
}

Value rbt_search(RBT *rbt, void *key) {
    return rec_rbt_search(rbt->root, key);
}
