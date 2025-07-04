#include <stdio.h>
#include <stdlib.h>

typedef struct QueueNode{
    int data;
    struct QueueNode *next;
} QueueNode;
typedef struct {
    QueueNode* front;
    QueueNode* rear;
    int size;
} Queue;

Queue* create_queue(void) {
    Queue* new_queue = malloc(sizeof(Queue));
    if (new_queue == NULL) {
        printf("Queue memory allocation failed\n");
        return NULL;
    }
    new_queue->front = NULL;
    new_queue->rear = NULL;
    new_queue->size = 0;
    printf("New queue successfully created\n");
    return new_queue;
}

void delete_queue(Queue** queue) {
    if (queue == NULL) {
        printf("Queue deletion failed");
        return;
    }
    if (*queue == NULL) {
        printf("Queue deletion failed");
        return;
    }
    QueueNode* current = (*queue)->front;
    while (current != NULL) {
        QueueNode* temp = current;
        current = current->next;
        free(temp);
    }
    free(*queue);
    *queue = NULL;
    printf("Queue successfully deleted");
    return;
}