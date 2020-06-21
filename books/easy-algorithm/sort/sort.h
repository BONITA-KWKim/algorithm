#ifndef __SORT_H__
#define __SORT_H__

class Sort 
{
public:
    Sort(){};
    ~Sort(){};

    virtual void sort(int *arr, int size){};
};

#endif