#include <iostream>
int main(int argc, char* argv[]) {
	int a = 0;
	int b = 0;
	int n = 0;
	int c = 0;
	std::cin >> a;
	std::cin >> b;
	std::cin >> n;
	int a0 = a;
	int b0 = b;
	while (a0 != b0) {
		if (a0 > b0) {
			a0 = a0 - b0;
		}
		else {
			b0 = b0 - a0;
		}
	}
	if (n > a && n > b) {
		std::cout << "Imposible";

	}
	else {
		if (n % a0 == 0) {
			while (true) {
				std::cout << ">A" << std::endl;
				std::cout << "A>B" << std::endl;
				c += a;
				if (c >= b) {
					c %= b;
					std::cout << "B>" << std::endl;
					std::cout << "A>B" << std::endl;
				}
				if (c == n) {
					break;
				}
			}
		}
		else {
			std::cout << "Impossible";
		}
	}
	return EXIT_SUCCESS;
}