#include "circular-queue.h"
/*
TQUEUE::CircularQueue::CircularQueue (void) {

}

TQUEUE::CircularQueue::~CircularQueue (void) {
    
}

void TQUEUE::CircularQueue::hello_circular_queue (void) {
    std::cout << "Hello, circular queue" << std::endl;
}
*/

namespace circular_queue {

void hello_queue (void) {
    std::cout << "Hello, circular queue" << std::endl;
}

CQueue *create_queue (int capacity) {
    CQueue *queue = (CQueue *)malloc(sizeof(CQueue));

    queue->nodes = (CQNode *)malloc(sizeof(CQNode) * (capacity+1));
    memset(queue->nodes, 0x00, sizeof(CQNode) * (capacity+1));

    queue->capacity = capacity;
    queue->front = 0;
    queue->rear = 0;

    return queue;
}

void destroy_queue (CQueue * queue) {
    free(queue->nodes);
    free(queue);
}

bool enqueue (CQueue *queue, ElementType data) {
    if (is_full(queue)) return false;

    queue->nodes[queue->rear].data = data;

    if (queue->rear >= queue->capacity) {
        queue->rear = 0;
    } else {
        ++queue->rear;
    }

    return true;
}

bool dequeue (ElementType &result, CQueue *queue) {
    if (is_empty(queue)) return false;

    result = queue->nodes[queue->front].data;
    queue->nodes[queue->front].data = 0;

    if (queue->front >= queue->capacity) {
        queue->front = 0;
    } else {
        ++queue->front;
    }

    return true;
}

bool is_full (CQueue *queue) {
    if (queue->rear > queue->front) {
        return (queue->capacity == (queue->rear - queue->front));
    } else {
        return ((queue->rear + 1) == queue->front);
    }
}

bool is_empty (CQueue *queue) {
    return (queue->front == queue->rear);
}

void print_queue (CQueue *queue) {
    std::cout << "front: " << queue->front << ", rear: " << queue->rear << std::endl;
    for(int i = 0; queue->capacity >= i; ++i) {
        std::cout << queue->nodes[i].data << " ";
    }
    std::cout << std::endl;
}

} // namespace
