#include <iostream>
int main(int argc, char* argv[]) {
	int a = 0;
	int b = 0;
	int c = 0;
	std::cin >> a;
	std::cin >> b;
	std::cin >> c;
	if (a <= b && b <= c) {
		std::cout << a << " " << b << " " << c;
	}
	else {
		if (a <= c && c <= b) {
			std::cout << a << " " << c << " " << b;
		}
		else {
			if (b <= a && a <= c) {
				std::cout << b << " " << a << " " << c;
			}
			else {
				if (b <= c && c <= a) {
					std::cout << b << " " << c << " " << a;
				}
				else {
					if (c <= b && b <= a) {
						std::cout << c << " " << b << " " << a;
					}
					else {
						if (c <= a && a <= b) {
							std::cout << c << " " << a << " " << b;
						}
					}
				}
			}
		}
	}
	return EXIT_SUCCESS;
}