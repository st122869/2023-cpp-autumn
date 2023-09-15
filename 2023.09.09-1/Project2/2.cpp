#include <iostream>
int main(int argc, char* argv[]) {
	int n = 0;
	int a = 0;
	std::cin >> n;
	a = abs(n - 1) + 1;
	std::cout << (1 + n) * a / 2;
	return EXIT_SUCCESS;
}