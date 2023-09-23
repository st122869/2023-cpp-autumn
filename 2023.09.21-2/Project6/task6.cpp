#include <iostream>
int main() {
	int k = 0;
	int m = 0;
	int n = 0;
	int a = 0;
	std::cin >> k;
	std::cin >> m;
	std::cin >> n;
	if (n > k) {
		a = (n / k * 2 * m) + 2 * m;
	}
	else {
		a = 2 * m;
	}
	std::cout << a;
	return EXIT_SUCCESS;
}