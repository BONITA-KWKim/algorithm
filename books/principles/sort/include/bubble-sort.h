#ifndef __BUBBLE_SORT_H__
#define __BUBBLE_SORT_H__

#include "sort.h"

class BubbleSort : public Sort {
public:
    BubbleSort(){};
    ~BubbleSort(){};

    void sort (int *arr, int size) override;
};

#endif