#ifndef __BUBBLE_SORT_H__
#define __BUBBLE_SORT_H__

#include "sort.h"

class BubbleSort : public Sort {
public:
    BubbleSort(){};
    ~BubbleSort(){};

    void sort (int *arr, int size) override
    {
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
};

#endif