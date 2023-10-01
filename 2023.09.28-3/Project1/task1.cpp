#include <iostream>
int main(int argc, char* argv[]) {
	int a = 0;
	int b = 1;
	int c = 0;
	std::cin >> a;
	for (int i = 1; i <= a; i++) {
		std::cout << b;
		std::cout << " ";
		c++;
		if (b == c) {
			b++;
			c = 0;
		}
	}
}
