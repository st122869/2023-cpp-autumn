#include <iostream>
int main(int argc, char* argv[]) {
	int a = 0;
	int b = 0;
	int c = 0;
	std::cin >> a >> b;
	c = (a * (a / b) + b * (b / a)) / (b / a + a / b);
	std::cout << c;
	return EXIT_SUCCESS;
}