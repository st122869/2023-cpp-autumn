#include <iostream>
#include <cmath>
int main(int argc, char* argv[]) {
	int x = 0;
	int a = 0;
	std::cin >> x;
	for (int i = 1; i <= sqrt(x) - 1; i++) {
		if (x % i == 0) {
			a++;
		}
	}
	a *= 2;
	if (int(sqrt(x)) == sqrt(x)) {
		a++;
	}
	std::cout << a;
		return EXIT_SUCCESS;
}