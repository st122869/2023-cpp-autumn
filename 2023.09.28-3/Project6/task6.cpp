#include <iostream>
int main(int argc, char* argv[]) {
	int n = 0;
	int i = 2;
	int a = 0;
	int b = 0;
	int c = 0;
	b = a + 1;
	std::cin >> n;
	if (n == 0) {
		std::cout << 0;
	}
	else if (n == 1) {
		std::cout << 1;
	}
	else {
		while (i <= n) {
			c = a + b;
			a = b;
			b = c;
			i++;
		}
		std::cout << c;
	}
	return EXIT_SUCCESS;
}
