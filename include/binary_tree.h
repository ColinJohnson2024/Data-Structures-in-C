#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Tree {
    struct Node* root;
} Tree;

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Tree level operations
Tree* create_tree();
int insert_root(Tree* tree, int data);
int delete_tree(Tree** tree);

// Node level operations
Node* create_node(int data);
int insert_left(Node* parent, int data);
int insert_right(Node* parent, int data);
int delete_node(Node* node);

#endif