#include <iostream>
int main(int argc, char* argv[]) {
	int N = 0;
	int a = 0;
	std::cin >> N;
	a = abs(N - 1) + 1;
	std::cout << (1 + N) * a / 2;
	return EXIT_SUCCESS;
}