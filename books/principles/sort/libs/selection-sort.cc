#include "selection-sort.h"

void SelectionSort::sort (int *arr, int size) {
    if (1 >= size) return;

    for (int i = size-1; 0 < i; --i) 
    {
        // get max
        int max_idx = 0, max_val = arr[0];
        for (int j = 1; i > j; ++j)
        {
            if (max_val < arr[j])
            {
                max_val = arr[j];
                max_idx = j;        
            }
        }

        if (max_val > arr[i])
        {
            int tmp = arr[i];
            arr[i] = arr[max_idx];
            arr[max_idx] = tmp;
        }
    }
}