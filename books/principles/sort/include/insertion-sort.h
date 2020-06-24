#ifndef __INSERTION_SORT_H__
#define __INSERTION_SORT_H__

#include "sort.h"

class InsertionSort : public Sort{
public:
    InsertionSort(){};
    ~InsertionSort(){};

    void sort (int *arr, int size) override;
private:
};

#endif