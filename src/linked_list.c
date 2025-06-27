#include "linked_list.h"

Node* create_node(int data) {
    Node* new_node = malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Node memory allocation failed\n");
        return NULL;
    }

    new_node->data = data;
    new_node->next = NULL;
    printf("Node successfully created\n");
    return new_node;
}

int insert_head(Node** head, int data) {
    Node* new_node = create_node(data);
    if (new_node == NULL) {
        printf("Node creation failed\n");
        return 0;
    }

    new_node->next = *head;
    *head = new_node;
    printf("Head node inserted successfully\n");
    return 1;
}

int insert_tail(Node** head, int data) {
    Node* new_node = create_node(data);
    if (new_node == NULL) {
        printf("Node creation failed\n");
        return 0;
    }
    if (*head == NULL) {
        *head = new_node;
        return 1;
    }
    Node* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = new_node;
    printf("Tail node inserted successfully\n");
    return 1;
}

void print_list(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

void destroy_list(Node** head) {
    Node* current = *head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
    *head = NULL;
    printf("List destroyed successfully\n");
}

int delete_head(Node** head) {
    if (*head == NULL) {
        printf("No node to delete\n");
        return 0;
    }
    
    Node* node_to_delete = *head;

    *head = node_to_delete->next;

    free(node_to_delete);
    printf("Node successfully deleted\n");
    return 1;
}

int get_size(Node* head) {
    int i = 0;
    while (head != NULL) {
        i++;
        head = head->next;
    }
    return i;
}

int is_empty(Node* head) {
    return (head == NULL);
}

Node* search(Node* head, int value) {
    Node* current = head;
    while (current != NULL) {
        if (current->data == value) {
            printf("Found first matching node");
            return current;
        }
        current = current->next;
    }
    printf("No matching node found");
    return NULL;
}