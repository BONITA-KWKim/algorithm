#ifndef __PRIORITY_QUEUE_H__
#define __PRIORITY_QUEUE_H__

#include <iostream>

typedef int PriorityType;

typedef struct tabPQNode {
    PriorityType priority;
    void *data;
} PQNode;

typedef struct tagTPriorityQueue {
    PQNode *nodes;
    unsigned int capacity;
    unsigned int used_size;
} TPriorityQueue;

class PriorityQueue {
public:
    PriorityQueue(){};
    ~PriorityQueue(){};

    // create & destroy
    TPriorityQueue *create (int capacity);
    void destroy (TPriorityQueue *queue);
    // enqueue & dequeue
    void enqueue (TPriorityQueue *queue, PQNode newdata);
    void dequeue (PQNode *result, TPriorityQueue *queue);

    bool is_empty(TPriorityQueue *queue);

    void print (TPriorityQueue *heap);
private:
    int get_parent(int index);
    void swap(TPriorityQueue *queue, int index1, int index2);
};

#endif