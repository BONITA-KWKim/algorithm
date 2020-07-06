#ifndef __HEAP_H__
#define __HEAP_H__

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>

typedef int ElementType;

typedef struct tagHeapNode {
    ElementType data;
} HeapNode;

typedef struct tagHeap {
    HeapNode *nodes;
    int capacity;
    int used_size;
} HeapTree;

class Heap {
public:
    Heap(){};
    ~Heap(){};

    // create & destroy
    HeapTree *create (int);
    void destroy (HeapTree *);

    // operation
    void insert (HeapTree *, ElementType);
    void delete_min (HeapNode *, HeapTree *);

    // print
    void print (HeapTree *);
private:
    void swap (HeapNode *, HeapNode *);
    void swap (HeapTree *, int , int);
};

#endif