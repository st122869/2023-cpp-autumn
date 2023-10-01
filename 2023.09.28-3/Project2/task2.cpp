#include <iostream>
int main(int argc, char* argv[]) {
	int x = 0;
	std::cin >> x;
	while (x % 10 == 0) {
		x = x / 10;
	}
	for (int i = 0; i <= 10 * x; i++) {
		std::cout << x % 10;
		x = x / 10;
	}
	return EXIT_SUCCESS;
}