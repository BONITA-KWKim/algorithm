//#include "gtest/gtest.h"
#include "gtest/gtest.h"

#include "insertion-sort.h"
#include "bubble-sort.h"
#include "selection-sort.h"

TEST (SORT, SELECTION_SORT_001)
{
    Sort *sort = new SelectionSort();

    int test_arr[6] = {3, 6, 4, 8, 9, 7};
    int answer[6] = {3, 4, 6, 7, 8, 9};

    sort->sort(test_arr, 6);

    for (int i = 0; sizeof(answer) / sizeof(int) > i; ++i)
    {
        EXPECT_EQ(answer[i], test_arr[i]);
    }
}

TEST (SORT, SELECTION_SORT_002)
{
    Sort *sort = new SelectionSort();

    int test_arr[6] = {-3, -6, -4, -8, -9, -7};
    int answer[6] = {-9, -8, -7, -6, -4, -3};

    sort->sort(test_arr, 6);

    for (int i = 0; sizeof(answer) / sizeof(int) > i; ++i)
    {
        EXPECT_EQ(answer[i], test_arr[i]);
    }
}

TEST (SORT, BUBBLE_SORT_001)
{
    Sort *sort = new BubbleSort();

    int test_arr[6] = {3, 6, 4, 8, 9, 7};
    int answer[6] = {3, 4, 6, 7, 8, 9};

    sort->sort(test_arr, 6);

    for (int i = 0; sizeof(answer) / sizeof(int) > i; ++i)
    {
        EXPECT_EQ(answer[i], test_arr[i]);
    }
}

TEST (SORT, BUBBLE_SORT_002)
{
    Sort *sort = new BubbleSort();

    int test_arr[6] = {-3, -6, -4, -8, -9, -7};
    int answer[6] = {-9, -8, -7, -6, -4, -3};

    sort->sort(test_arr, 6);

    for (int i = 0; sizeof(answer) / sizeof(int) > i; ++i)
    {
        EXPECT_EQ(answer[i], test_arr[i]);
    }
}

int main (int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
