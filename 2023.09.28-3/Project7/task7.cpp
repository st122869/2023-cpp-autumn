#include <iostream>
int main(int argc, char* argv[]) {
	int n = 0;
	int k = 0;
	int m = 1;
	std::cin >> n;
	while (n > m) {
		m *= 2;
		k++;
	}
	std::cout << k;
	return EXIT_SUCCESS;
}