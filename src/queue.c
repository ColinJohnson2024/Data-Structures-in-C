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



