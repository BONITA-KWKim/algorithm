#ifndef __PRIORITY_QUEUE_H__
#define __PRIORITY_QUEUE_H__

#include <iostream>

typedef int ElementType;

typedef struct tabHeapNode {
    ElementType data;
} HeapNode;

typedef struct tabHeap {
    HeapNode *nodes;
    int capacity;
    int used_size;
} Heap;

class PriorityQueue {
public:
    PriorityQueue(){};
    ~PriorityQueue(){};

    void insert (Heap *, ElementType);
    void remove_min (Heap *, HeapNode *);
};

#endif