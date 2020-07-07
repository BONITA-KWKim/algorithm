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
    int parent_pos = this->get_parent(current_pos);
    while (0 <= parent_pos) {
        if(heap->nodes[current_pos].data < heap->nodes[parent_pos].data) {
            //swap(&(heap->nodes[current_pos]), &(heap->nodes[prarent_pos]));
            swap(heap, current_pos, parent_pos);
            parent_pos = this->get_parent(current_pos);
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
    int current_pos = 0;
    int next_pos = 0;
    while (true) {
                // next_pos is left child index, so (next_pos + 1)n is right child index
        next_pos = current_pos*2+1;
        // If children's index was over used size, stop this.
        if(next_pos >= heap->used_size || next_pos + 1 >= heap->used_size) break;
        // If right child's priority was under the left, next_pos would plus 1. 
        // Go to right child
        if (heap->nodes[next_pos].data > heap->nodes[next_pos+1].data) {
            next_pos += 1;
        }

        if (heap->nodes[next_pos].data < heap->nodes[current_pos].data) {
            swap(heap, current_pos, next_pos);
            current_pos = next_pos;
            continue;
        }  
        
        break;
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

int Heap::get_parent (int index) {
    return ((index - 1) / 2);
}

void Heap::swap(HeapTree *heap, int idx1, int idx2) {
    int copy_size = sizeof(HeapNode);
    HeapNode *tmp = (HeapNode *)malloc(sizeof(HeapNode));

    memcpy(tmp, &heap->nodes[idx1], copy_size);
    memcpy(&heap->nodes[idx1], &heap->nodes[idx2], copy_size);
    memcpy(&heap->nodes[idx2], tmp, copy_size);
}