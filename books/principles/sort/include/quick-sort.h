#ifndef __QUICK_SORT_H__
#define __QUICK_SORT_H__

#include "sort.h"

class QuickSort : public Sort 
{
public:
    QuickSort(){};
    ~QuickSort(){};

    void sort (int *arr, int st, int sp) override;
private:
    void swap (int *arr, int i, int j);
    int partition (int *arr, int left, int right);
};

#endif