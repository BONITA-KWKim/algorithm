#include <iostream>
#include "gtest/gtest.h"

#include "heap.h"
#include "priority-queue.h"

TEST (HEAP_TEST_CASE, TESTNO_001)
{
    Heap *heap = new Heap();
    HeapTree * heap_tree = heap->create(10);

    heap->insert(heap_tree, 12);
    heap->insert(heap_tree, 87);
    heap->insert(heap_tree, 111);
    heap->insert(heap_tree, 34);
    heap->insert(heap_tree, 16);
    heap->insert(heap_tree, 75);

    HeapNode node;
    heap->delete_min(&node, heap_tree);
    EXPECT_EQ(12, node.data);
    heap->delete_min(&node, heap_tree);
    EXPECT_EQ(16, node.data);
    heap->delete_min(&node, heap_tree);
    EXPECT_EQ(34, node.data);
    heap->delete_min(&node, heap_tree);
    EXPECT_EQ(75, node.data);
    heap->delete_min(&node, heap_tree);
    EXPECT_EQ(87, node.data);
    heap->delete_min(&node, heap_tree);
    EXPECT_EQ(111, node.data);

    heap->destroy(heap_tree);
}

TEST (PRIORITY_QUEUE_TEST_CASE, TESTNO_001)
{
    PriorityQueue *queue = new PriorityQueue();
    TPriorityQueue * priority_queue = queue->create(10);
    PQNode popped;

    PQNode nodes[6] = {
        {34, (void*)"coding"},
        {12, (void*)"meeting"},
        {87, (void*)"making coffee"},
        {45, (void*)"write docs"},
        {35, (void*)"debugging"},
        {66, (void*)"brush teeth"}
    };

    for (int i = 0; 6 > i; ++i)
        queue->enqueue(priority_queue, nodes[i]);

    queue->dequeue(&popped, priority_queue);
    EXPECT_EQ(12, popped.priority);
    queue->dequeue(&popped, priority_queue);
    EXPECT_EQ(34, popped.priority);
    queue->dequeue(&popped, priority_queue);
    EXPECT_EQ(35, popped.priority);
    queue->dequeue(&popped, priority_queue);
    EXPECT_EQ(45, popped.priority);
    queue->dequeue(&popped, priority_queue);
    EXPECT_EQ(66, popped.priority);
    queue->dequeue(&popped, priority_queue);
    EXPECT_EQ(87, popped.priority);
}

int main (int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
   return RUN_ALL_TESTS();
}