#ifndef __CIRCULAR_QUEUE_H__
#define __CIRCULAR_QUEUE_H__

#include <iostream>


namespace circular_queue {

typedef int ElementType;

typedef struct tagCQNode {
    ElementType data;
} CQNode;

typedef struct tabCQueue {
    int capacity;
    int front;
    int rear;

    CQNode *nodes;
} CQueue;

void hello_queue (void);

CQueue *create_queue (int);
void destroy_queue (CQueue * queue);

bool enqueue (CQueue *, ElementType);
bool dequeue (ElementType &, CQueue *);
bool is_full (CQueue *);
bool is_empty (CQueue *);
void print_queue (CQueue *);

}

#endif