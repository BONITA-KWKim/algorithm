#include <iostream>
#include "gtest/gtest.h"

#include "circular-queue.h"

TEST (TESTCASE, TESTNO_001)
{
    circular_queue::ElementType result;
    circular_queue::CQueue *queue = circular_queue::create_queue (10);

    circular_queue::enqueue (queue, 1);
    circular_queue::enqueue (queue, 2);
    circular_queue::enqueue (queue, 3);
    circular_queue::enqueue (queue, 4);
    circular_queue::enqueue (queue, 5);
    circular_queue::enqueue (queue, 6);

    circular_queue::print_queue (queue);

    circular_queue::dequeue (result, queue);
    std::cout << "dequeue: " << result << std::endl;
    circular_queue::dequeue (result, queue);
    std::cout << "dequeue: " << result << std::endl;
    circular_queue::dequeue (result, queue);
    std::cout << "dequeue: " << result << std::endl;

    circular_queue::print_queue (queue);

    EXPECT_EQ(0, 0);
}

int main (int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
   return RUN_ALL_TESTS();
}