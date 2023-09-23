#include <iostream>
int main(int argc, char* argv[]) {
	int n;
	std::cin >> n;
	int price1 = 15;
	int price5 = 70;
	int price10 = 125;
	int price20 = 230;
	int price60 = 440;
	int ticket1 = 0;
	int ticket5 = 0;
	int ticket10 = 0;
	int ticket20 = 0;
	int ticket60 = 0;
	while (n > 0) {
		if (n >= 60 && (price1 * n + price5 * (n / 5) + price10 * (n / 10) + price20 * (n / 20) >= price60)) {
			ticket60++;
			n -= 60;
		}
		else if (n >= 20 && (price1 * n + price5 * (n / 5) + price10 * (n / 10) >= price20)) {
			ticket20++;
			n -= 20;
		}
		else if (n >= 10 && (price1 * n + price5 * (n / 5) >= price10)) {
			ticket10++;
			n -= 10;
		}
		else if (n >= 5 && (price1 * n >= price5)) {
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