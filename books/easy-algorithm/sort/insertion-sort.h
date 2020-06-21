#ifndef __INSERTION_SORT_H__
#define __INSERTION_SORT_H__

#ifdef DEBUG
#include <iostream>
#endif

class InsertSort {
public:
    InsertSort(){};
    ~InsertSort(){};

    void insert_sort (int *arr, int n)
    {
        if (1 >= n) return;

        for (int i = n-1; 0 < i; --i) 
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
#ifdef DEBUG
            std::cout << i << "th: ";
            for (int k = 0; 6 > k; ++k)
            {
                std::cout << arr[k] << "";
            }
            std::cout << std::endl;
#endif
        }
    }
private:
};

#endif