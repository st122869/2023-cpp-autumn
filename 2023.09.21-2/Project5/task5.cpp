#include <iostream>
int main(int argc, char* argv[]) {
	int n = 0;
	std::cin >> n;
	std::cout << n;
	std::cout << " ";
	if ((n % 100) <= 14 && (n % 100) >= 11) {
		std::cout << "bochek";
	}
	else {
		switch (n % 10) {
		case 0:
			std::cout << "bochek";
			break;
		case 1:
			std::cout << "bochka";
			break;
		case 2:case 3:case 4:
			std::cout << "bochki";
			break;
		default:
			std::cout << "bochek";
			break;
		}
	}
	return EXIT_SUCCESS;
}