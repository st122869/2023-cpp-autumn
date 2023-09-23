#include <iostream>
int main(int argc, char* argv[]) {
	int n;
	std::cin >> n;
	int ticket1 = 0;
	int ticket5 = 0;
	int ticket10 = 0;
	int ticket20 = 0;
	int ticket60 = 0;
	while (n > 0) {
		if (n >= 60) {
			ticket60++;
			n -= 60;
		}
		else if (n >= 20) {
			ticket20++;
			n -= 20;
		}
		else if (n >= 10) {
			ticket10++;
			n -= 10;
		}
		else if (n >= 5) {
			ticket5++;
			n -= 5;
		}
		else {
			ticket1 += n;
			n = 0;
		}
	}
	std::cout << ticket1 << " " << ticket5 << " " << ticket10 << " " << ticket20 << " " << ticket60 << std::endl;
	return EXIT_SUCCESS;
}