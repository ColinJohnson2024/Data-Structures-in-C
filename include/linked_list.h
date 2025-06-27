#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* create_node(int data);
int insert_head(Node** head, int data);
int insert_tail(Node** head, int data);
int delete_head(Node** head);
int delete_value(Node** head, int value);
Node* search(Node* head, int value);
void print_list(Node* head);
int get_size(Node* head);
int is_empty(Node* head);
void destroy_list(Node** head);

#endif