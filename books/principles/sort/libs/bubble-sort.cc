#include "bubble-sort.h"

void BubbleSort::sort (int *arr, int size) {
    bool sorted = true;
    for (int i = size-1; 0 < i; --i)
    {
        sorted = true;
        for (int j = 0; i > j; ++j)
        {
            if (arr[j] > arr[j+1])
            {
                int tmp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = tmp;
                sorted = false;
            }

            if(i <= j && sorted == true) return;
        }
    }
}