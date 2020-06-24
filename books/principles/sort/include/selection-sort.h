#ifndef __SELECTION_SORT_H__
#define __SELECTION_SORT_H__

#include "sort.h"

class SelectionSort : public Sort 
{
public:
    SelectionSort(){};
    ~SelectionSort(){};

    void sort (int *arr, int size) override;
};

#endif