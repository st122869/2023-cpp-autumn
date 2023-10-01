#include <iostream>
int opposite(int i) {
	int x = 0;
	while (i > 0) {
		x = x * 10 + (i % 10);
		i /= 10;
	}
	return x;
}
int main(int argc, char* argv[]) {
	int k = 0;
	int a = 0;
	std::cin >> k;
	for (int i = 1; i <= k; i++) {
		if (i == opposite(i)) {
			a++;
		}
	}
	std::cout << a;
	return EXIT_SUCCESS;
}
