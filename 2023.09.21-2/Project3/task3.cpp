#include <iostream>
int main(int argc, char* argv[]) {
	int a = 0;
	int b = 0;
	int c = 0;
	int d = 0;
	std::cin >> a;
	std::cin >> b;
	std::cin >> c;
	std::cin >> d;
	(a == 0 && b == 0) ? std::cout << "INF" : (a == 0 || b % a != 0 || c * (-b / a) + d == 0) ?
		std::cout << "NO" : std::cout << -b / a;
	return EXIT_SUCCESS;
}