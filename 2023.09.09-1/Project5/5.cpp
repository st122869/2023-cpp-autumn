#include <iostream>
int main(int argc, char* argv[]) {
	int v = 0;
	int t = 0;
	int a = 0;
	std::cin >> v >> t;
	a = ((v*t%109) + 109) % 109 + 1;
	std::cout << a;
	return EXIT_SUCCESS;
}