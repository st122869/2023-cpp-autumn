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

	int max = *(a + 0);
	int max_i = 0;
	for (int i = 0; i < n; ++i)
	{
		if (*(a + i) >= max)
		{
			max = *(a + i);
			max_i = i;
		}
	}

	int min = max;
	int min_i = 0;
	for (int i = 0; i < n; ++i)
	{
		if (*(a + i) < min)
		{
			min = *(a + i);
			min_i = i;
		}
	}

	*(a + (max_i)) = min;
	*(a + (min_i)) = max;

	for (int i = 0; i < n; ++i)
	{
		std::cout << *(a + i) << " ";
	}

	free(a);

	return EXIT_SUCCESS;
}
