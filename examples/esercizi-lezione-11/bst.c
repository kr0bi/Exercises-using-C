#include <stdio.h>
#include <stdlib.h>

struct bst {
    int key;
    struct bst *left;
    struct bst *right;
    struct bst *parent;
    struct bst *root;
};

struct bst *create (int data){
    struct bst *ptr = malloc(sizeof(struct bst));
    ptr->key = data;
    ptr->parent = NULL;
    ptr->left = NULL;
    ptr->right = NULL;
    ptr->root = ptr;
}

struct bst *insert (struct bst *T, int data){
    struct bst *y = NULL;
    struct bst *x = T->root;
    while (x!=NULL){
        y = &x;
        if (data->)
    }
}