#include "priority-queue.h"

TPriorityQueue *PriorityQueue::create (int capacity) {
    TPriorityQueue *queue = (TPriorityQueue *)malloc(sizeof(TPriorityQueue));

    queue->nodes = (PQNode *)malloc(sizeof(PQNode) * capacity);
    memset(queue->nodes, 0x00, sizeof(PQNode) * capacity);
    queue->capacity = capacity;
    queue->used_size = 0;

    return queue;
}

void PriorityQueue::destroy (TPriorityQueue *queue) {
    free(queue->nodes);
    free(queue);
}

void PriorityQueue::enqueue (TPriorityQueue *queue, PQNode newdata) {
    if (NULL == queue) return;
    // insert at the deepest level and the righ
    if (queue->used_size >= queue->capacity) {
        return;
    }

    int current_pos = queue->used_size;
    ++queue->used_size;
    //queue->nodes[current_pos].data = data;
    memcpy(&queue->nodes[current_pos], &newdata, sizeof(PQNode));

    if(0 == current_pos) return;

    // check heap rules
    int parent_pos = this->get_parent(current_pos);
    while (0 <= parent_pos) {
        if(queue->nodes[current_pos].priority < queue->nodes[parent_pos].priority) {
            swap(queue, current_pos, parent_pos);
            parent_pos = this->get_parent(current_pos);
        } else {
            break;
        }
    }

    return;
}

void PriorityQueue::dequeue (PQNode *result, TPriorityQueue *queue) {
    if (NULL == queue) return;

    if (0 >= queue->used_size) return;

    memcpy(result, &queue->nodes[0], sizeof(PQNode));
    
    // get data at the deepest level and the rightmost
    memcpy(&queue->nodes[0], &queue->nodes[(queue->used_size - 1)], sizeof(PQNode));
    queue->nodes[queue->used_size - 1].priority = 999999;
    --queue->used_size;

    // check
    unsigned int current_pos = 0;
    unsigned int next_pos = 0;
    while (true) {
        // next_pos is left child index, so (next_pos + 1)n is right child index
        next_pos = current_pos*2+1;
        // If children's index was over used size, stop this.
        if(next_pos >= queue->used_size || next_pos + 1 >= queue->used_size) break;
        // If right child's priority was under the left, next_pos would plus 1. 
        // Go to right child
        if (queue->nodes[next_pos].priority > queue->nodes[next_pos+1].priority) {
            next_pos += 1;
        }

        if (queue->nodes[next_pos].priority < queue->nodes[current_pos].priority) {
            swap(queue, current_pos, next_pos);
            current_pos = next_pos;
            continue;
        }  
        
        break;
    }
}

bool PriorityQueue::is_empty(TPriorityQueue *queue) {
    if (0 == queue->used_size) {
        return true;
    } else {
        return false;
    }
}

void PriorityQueue::print (TPriorityQueue *queue) {
    std::cout << "capacity: " << queue->capacity << ", used: " << queue->used_size << std::endl;

    for(int i = 0; queue->used_size > i; ++i) {
        std::cout << queue->nodes[i].priority << " ";
    }
    std::cout << std::endl;
}

int PriorityQueue::get_parent (int index) {
    return ((index - 1) / 2);
}

void PriorityQueue::swap (TPriorityQueue *queue, int idx1, int idx2) {
    int copy_size = sizeof(PQNode);
    PQNode *tmp = (PQNode *)malloc(sizeof(PQNode));

    memcpy(tmp, &queue->nodes[idx1], copy_size);
    memcpy(&queue->nodes[idx1], &queue->nodes[idx2], copy_size);
    memcpy(&queue->nodes[idx2], tmp, copy_size);
}