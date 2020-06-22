#ifndef __INSERTION_SORT_H__
#define __INSERTION_SORT_H__

#include "sort.h"

class InsertionSort : public Sort{
public:
    InsertionSort(){};
    ~InsertionSort(){};

    void sort (int *arr, int size) override
    {   
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
private:
};

#endif