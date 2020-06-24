#ifndef __SEQUENTIAL_SEARCH_H__
#define __SEQUENTIAL_SEARCH_H__

#include "gtest/gtest.h"
#include "base-search.h"

class SequentialSearch : public BaseSearch {
public:
    SequentialSearch(){};
    ~SequentialSearch(){};

    void search (void) override {
        return;
    }
private:
};

#endif