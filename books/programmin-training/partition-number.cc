#include <iostream>

int partition(int, int);

int main(void) 
{
	int n, m;
	std::cout << "input number. n, m: ";
	std::cin >> n >> m;
	int rst = partition(n, m);
	std::cout << "result: " << rst << std::endl;
	return 0;
}

int partition(int n, int m) 
{
	int count = 0, i;
	
	if(n < m)
		m = n;
	if(0 == n) {
		std::cout << std::endl;
		return 1;
	}

	for(i = 1; m >= i; ++i) {
		std::cout << i << " ";
		count += partition(n-i, i);
	}
	
	return count;
}
