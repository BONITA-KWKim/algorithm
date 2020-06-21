#ifndef __SORT_H__
#define __SORT_H__

class Sort 
{
public:
    Sort(){};
    ~Sort(){};

    virtual void sort(int *arr, int size){};
    virtual void sort(int *arr, int st, int sp){};
};

#endif