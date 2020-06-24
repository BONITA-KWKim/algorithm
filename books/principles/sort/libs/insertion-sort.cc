#include "insertion-sort.h"

void InsertionSort::sort (int *arr, int size) {   
    int loc = 0;
    int picked = 0;
    for (int i = 1; size > i; ++i)
    {
        loc = i;
        picked = arr[i];
        while (0 < loc && arr[loc-1] > arr[loc])
        {
            arr[loc] = arr[loc-1];
            arr[loc-1] = picked;
            --loc;
        }

    }
}