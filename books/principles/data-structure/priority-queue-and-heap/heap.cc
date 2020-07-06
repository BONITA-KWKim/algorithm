#include "heap.h"

HeapTree *Heap::create (int capacity) {
    HeapTree *new_heap = (HeapTree *)malloc(sizeof(HeapTree));
    new_heap->nodes = (HeapNode *)malloc(sizeof(HeapNode) * capacity);

    new_heap->capacity = capacity;
    new_heap->used_size = 0;

    return new_heap;
}

void Heap::destroy (HeapTree *heap) {
    free(heap->nodes);
    free(heap);
}

void Heap::insert (HeapTree *heap, ElementType data) {
    if (NULL == heap) return;
    // insert at the deepest level and the righ
    if (heap->used_size >= heap->capacity) {
        return;
    } 
    int current_pos = heap->used_size;
    ++heap->used_size;
    heap->nodes[current_pos].data = data;

    if(0 == current_pos) return;

    // check heap rules
    int parent_pos = ((current_pos-1)/2);
    while (0 <= parent_pos) {
        if(heap->nodes[current_pos].data < heap->nodes[parent_pos].data) {
            //swap(&(heap->nodes[current_pos]), &(heap->nodes[prarent_pos]));
            swap(heap, current_pos, parent_pos);
        } else {
            break;
        }
    }

    return;
}

void Heap::delete_min (HeapNode *node, HeapTree *heap) {
    if (NULL == heap) return;

    if (0 >= heap->used_size) return;

    memcpy(node, &heap->nodes[0], sizeof(HeapNode));
    
    // get data at the deepest level and the rightmost
    memcpy(&heap->nodes[0], &heap->nodes[(heap->used_size - 1)], sizeof(HeapNode));
    heap->nodes[heap->used_size - 1].data = 0;
    --heap->used_size;

    // check
    bool continue_flag = false;
    int current_pos = 0;
    while (true) {
        continue_flag = false;
        if (heap->nodes[current_pos*2+1].data < heap->nodes[current_pos].data) {
            // left 
            if(current_pos*2+1 >= heap->used_size) break;
            //swap(heap->nodes[current_pos], heap->nodes[current_pos*2+1]);
            swap(heap, current_pos, current_pos*2+1);
            current_pos = current_pos*2+1;
            continue_flag = true;
        } 
        
        if  (heap->nodes[current_pos*2+2].data < heap->nodes[current_pos].data) {
            // right;
            if(current_pos*2+2 >= heap->used_size) break;
            //swap(heap->nodes[current_pos], heap->nodes[current_pos*2+2]);
            swap(heap, current_pos, current_pos*2+2);
            current_pos = current_pos*2+2;
            continue_flag = true;
        } 

        if (true == continue_flag) continue;
        else break;
    }
}

void Heap::print (HeapTree *heap) {
    std::cout << "capacity: " << heap->capacity << ", used: " << heap->used_size << std::endl;

    for(int i = 0; heap->used_size > i; ++i) {
        std::cout << heap->nodes[i].data << " ";
    }
    std::cout << std::endl;
}
#if 0
void Heap::swap(HeapNode *a, HeapNode *b) {
    HeapNode *tmp = (HeapNode *)malloc(sizeof(HeapNode));
    memcpy(tmp, a, sizeof(HeapNode));
    memcpy(a, b, sizeof(HeapNode));
    memcpy(b, tmp, sizeof(HeapNode));
}
#endif

void Heap::swap(HeapTree *heap, int idx1, int idx2) {
    int copy_size = sizeof(HeapNode);
    HeapNode *tmp = (HeapNode *)malloc(sizeof(HeapNode));

    memcpy(tmp, &heap->nodes[idx1], copy_size);
    memcpy(&heap->nodes[idx1], &heap->nodes[idx2], copy_size);
    memcpy(&heap->nodes[idx2], tmp, copy_size);
}