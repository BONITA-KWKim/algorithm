#ifndef __CODEUP_3733_HPP__
#define __CODEUP_3733_HPP__

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <algorithm>

typedef struct tagCollatzLength {
    int no;
    int length;
} CollatzLength;

class Answer3733 {
public:
    Answer3733(){};
    ~Answer3733(){};
    
    static bool compare(CollatzLength *a, CollatzLength *b) {
        if (a->no < b->no) return true;
        return false;
    }
    
    void solution(int st, int sp) {
        collaz_length = (CollatzLength *)malloc(sizeof(CollatzLength) * (sp - st + 1));

        int length = 0;
        unsigned int tmp = 0;
        int count = 0;
        for (int i = st; sp >= i; ++i) {
            length = 0;
            tmp = i;
            while(1 != tmp) {
                if (1 == i%2) {
                    // odd
                    tmp = 3*tmp + 1;
                } else {
                    // even
                    tmp /= 2;
                }
                ++length;
            }
            collaz_length[count].no = i;
            collaz_length[count].length = length;
            ++count;
        }

        //sort
        std::sort(collaz_length, collaz_length+(sp - st + 1), this->compare);
    }

    CollatzLength *collaz_length;
private:

};

#endif
