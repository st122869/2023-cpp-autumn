#include <iostream>
#include <cstdlib>

int main(int, char**)
{
	int n = 0;
	std::cin >> n;

	int* a = 0;
	a = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; ++i)
	{
		std::cin >> *(a + i);
	}

	int b = 0;
	for (int i = 0; i < n; ++i) {
		if (*(a + i) > 0)
		{
			++b;
		}
	}

	std::cout << b;

	free(a);

	return EXIT_SUCCESS;
}
