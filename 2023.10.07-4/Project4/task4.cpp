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

	int m = *(a + 0);
	for (int i = 0; i < n; ++i)
	{
		if (*(a + i) >= m)
		{
			m = *(a + i);
		}
	}
	std::cout << m;

	free(a);

	return EXIT_SUCCESS;
}
