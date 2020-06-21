#include <iostream>
#include <cstdlib>
#include <time.h>       /* time */
#include <gtest/gtest.h>
#include "insertion-sort.h"

int *make_test_array(int);
void destroy_test_array(int *);

TEST (SORT, INSERTION_SORT_001)
{
    InsertSort *sort = new InsertSort();

    int test_arr[6] = {3, 6, 4, 8, 9, 7};
    int answer[6] = {3, 4, 6, 7, 8, 9};

    sort->insert_sort(test_arr, 6);

    for (int i = 0; sizeof(answer) / sizeof(int) > i; ++i)
    {
        EXPECT_EQ(answer[i], test_arr[i]);
    }
}

TEST (SORT, INSERTION_SORT_002)
{
    InsertSort *sort = new InsertSort();

    int test_arr[6] = {-3, -6, -4, -8, -9, -7};
    int answer[6] = {-9, -8, -7, -6, -4, -3};

    sort->insert_sort(test_arr, 6);

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

int *make_test_array (int size)
{
    int *test_arr;
    test_arr = (int *)malloc(sizeof(int) * size);
#if 0
    /* initialize random seed: */
    srand (time(NULL));
    /* generate secret number between 1 and 10: */
    for(int i = 0; size > i; ++i)
        test_arr[i] = rand() % (size*20) + 1;
#endif
    return test_arr;
}

void destroy_test_array (int *arr)
{
    free(arr);
}   