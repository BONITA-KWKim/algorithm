#ifndef __CODEUP_1916_HPP__
#define __CODEUP_1916_HPP__

#include <iostream>
#include <cstring>

class Answer1916 {
public:
    Answer1916(){
        memset(this->memo, 0x00, sizeof(int) * memo_size);
    };
    ~Answer1916(){};
    
    int solution(int n) {
        if (1 == n || 2 == n) 
            this->memo[n-1] = 1;
        
        if (0 == this->memo[n-1]) {
            this->memo[n-1] = solution(n-1) + solution(n-2);
            this->memo[n-1] %= 10009;
        }


        return this->memo[n-1];
    }

    const static int memo_size = 200;
private:
    int memo[memo_size];
};

#endif

/*
#include <iostream>
#include <cstring>

const int memo_size = 200;
int memo[memo_size];

int solution(int n) {
    if (1 == n || 2 == n) 
        memo[n-1] = 1;

    if (0 == memo[n-1]) {
        memo[n-1] = solution(n-1) + solution(n-2);
        memo[n-1] %= 10009;
    }

    return memo[n-1];
}

int main(void) {
    memset(memo, 0x00, sizeof(int) * memo_size);

    int n = 0;
    std::cin >> n;

    long long rst = solution(n);
    int result = rst % 10009;

    std::cout << result << std::endl;

    return 0;
}
*/