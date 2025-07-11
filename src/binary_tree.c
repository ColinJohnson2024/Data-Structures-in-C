#include "binary_tree.h"

// Tree level operations
Tree* create_tree() {
    Tree* new_tree = malloc(sizeof(Tree));
    if (new_tree == NULL) {
        printf("Tree memory allocation failed\n");
        return NULL;
    }
    new_tree->root = NULL;
    printf("Tree successfully created\n");
    return new_tree;
}

int insert_root(Tree* tree, int data) {
    if (tree->root != NULL) {
        printf("Root node already exists");
        return 0;
    }
    Node* new_root = create_node(data);
    if (new_root == NULL) {
        printf("Root node creation failed\n");
        return 0;
    }
    tree->root = new_root;
    return 1;
}

int delete_tree(Tree** tree) {
    if (*tree == NULL) {
        printf("Tree does not exist\n");
        return 1;
    }
    delete_node((*tree)->root);
    free(*tree);
    *tree = NULL;
    printf("Tree successfully deleted");
    return 1;
}

// Node level operations
Node* create_node(int data) {
    Node* new_node = malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Node memory allocation failed\n");
        return NULL;
    }
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    printf("Node successfully created\n");
    return new_node;
}

int insert_left(Node* parent, int data) {
    if (parent == NULL) {
        printf("No parent node exists\nNode insertion failed\n");
        return 0;
    }
    if (parent->left != NULL) {
        printf("Left node already exists for parent");
        return 0;
    }
    Node* left_node = create_node(data);
    if (left_node == NULL) {
        printf("Node creation failed\n");
        return 0;
    }
    parent->left = left_node;
    printf("Left node successfully created\n");
    return 1;
}

int insert_right(Node* parent, int data) {
    if (parent == NULL) {
        printf("No parent node exists\nNode insertion failed\n");
        return 0;
    }
    if (parent->right != NULL) {
        printf("Right node already exists for parent");
        return 0;
    }
    Node* right_node = create_node(data);
    if (right_node == NULL) {
        printf("Node creation failed\n");
        return 0;
    }
    parent->right = right_node;
    printf("Right node successfully created\n");
    return 1;
}

int delete_node(Node* node) {
    if (node == NULL) {
        printf("Node does not exist\n");
        return 1;
    }
    delete_node(node->left);
    delete_node(node->right);

    free(node);
    printf("Node successfully deleted\n");
    return 1;
}