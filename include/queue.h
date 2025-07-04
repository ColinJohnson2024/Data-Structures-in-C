#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct QueueNode {
    int data;
    struct QueueNode* next;
} QueueNode;

typedef struct {
    QueueNode* front;
    QueueNode* read;
    int size;
} Queue;

Queue* create_queue(void);
void delete_queue(Queue** queue);
int enqueue(Queue* queue);
int dequeue(Queue* queue);

int peek_front(Queue* queue);
int is_empty(Queue* queue);
int get_size(Queue* queue);
void print_queue(Queue* queue);


#endif