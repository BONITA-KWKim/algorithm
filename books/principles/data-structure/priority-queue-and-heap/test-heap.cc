#include <iostream>
#include "gtest/gtest.h"

#include "heap.h"

TEST (TESTCASE, TESTNO_001)
{
    Heap *heap = new Heap();
    HeapTree * heap_tree = heap->create(10);

    heap->insert(heap_tree, 12);
    heap->insert(heap_tree, 87);
    heap->insert(heap_tree, 111);
    heap->insert(heap_tree, 34);
    heap->insert(heap_tree, 16);
    heap->insert(heap_tree, 75);

    heap->print(heap_tree);

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

    heap->print(heap_tree);

    heap->destroy(heap_tree);
}

int main (int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
   return RUN_ALL_TESTS();
}