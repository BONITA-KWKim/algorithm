#ifndef __CODEUP_3701_HPP__
#define __CODEUP_3701_HPP__

#include <iostream>
#include <cstring>

class Answer3701 {
public:
    Answer3701(){
        memset(this->triangle, 0x00, sizeof(int) * row * column);
    };
    ~Answer3701(){};
    
    int get_triangle(int i, int j) {
        if (i == 1 || j == 1) {
            this->triangle[i-1][j-1] = 1;
        }

        if (0 == this->triangle[i-1][j-1]) {
            this->triangle[i-1][j-1] = get_triangle(i-1, j) + get_triangle(i, j-1);
            this->triangle[i-1][j-1] %= 100000000;
        }

        return this->triangle[i-1][j-1];
    }

    const static int row = 50;
    const static int column = 50;
private:
    int triangle[row][column];
};

#endif
/*
#include <iostream>
#include <cstring>

const static int row = 50;
const static int column = 50;
int triangle[row][column];

int get_triangle(int i, int j) {
    if (i == 1 || j == 1) {
        triangle[i-1][j-1] = 1;
    }

    if (0 == triangle[i-1][j-1]) {
        triangle[i-1][j-1] = get_triangle(i-1, j) + get_triangle(i, j-1);
        triangle[i-1][j-1] %= 100000000;
    }

    return triangle[i-1][j-1];
}

int main(void) {
    memset(triangle, 0x00, sizeof(int) * row * column);

    int n, m = 0;
    std::cin >> n >> m;

    int result = get_triangle(n, m);

    std::cout << result << std::endl;

    return 0;
}
*/