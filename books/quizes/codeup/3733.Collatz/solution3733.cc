#include <iostream>
#include <cstdlib>
#include <cstring>
#include <algorithm>

typedef struct tagCollatzLength {
    int no;
    int length;
} CollatzLength;

bool compare(const CollatzLength &a, const CollatzLength &b) {
    if (a.no < b.no) return true;
    return false;
}

void solution(CollatzLength *collaz_length,int st, int sp) {
    collaz_length = (CollatzLength *)malloc(sizeof(CollatzLength) * (sp - st + 1));

    int length = 0;
    unsigned int tmp = 0;
    int count = 0;
    for (int i = st; sp >= i; ++i) {
        length = 0;
        tmp = i;
        while(1 != tmp) {
            if (1 == tmp%2) {
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
    std::sort(collaz_length, collaz_length+(sp - st + 1), compare);
}

int main (void) {
    CollatzLength *collaz_length;

    solution(collaz_length, 1, 10);

    std::cout << collaz_length[0].no << " " << collaz_length[0].length << std::endl;

    return 0;
}
