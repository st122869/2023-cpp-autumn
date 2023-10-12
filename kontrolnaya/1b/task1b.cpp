#include <iostream>

typedef unsigned int uint;

int main(int argc, char* argv[])
{
	uint n = 0;
	std::cin >> n;

	const int BITS = sizeof(uint) * 8;

	std::cout << "0b ";
	for (int i = BITS - 1; i >= 0; --i)
	{
		std::cout << ((n >> i) & 1) << (i % 4 == 0 ? " " : "");
	}
	std::cout << std::endl;

	if (n == 0)
	{
		n = ~n;
	}
	else
	{
		int start = BITS - 1;
		int end = 0;
		while ((n >> start & 1) == 0)
		{
			start--;
		}
		while ((n >> end & 1) == 0)
		{
			end++;
		}

		start--;
		end++;

		uint mask = 0;
		for (int i = end; i <= start; ++i)
		{
			mask = mask | (1 << i);
		}
		n = n ^ mask;
	}

	std::cout << "0b ";
	for (int i = BITS - 1; i >= 0; --i)
	{
		std::cout << ((n >> i) & 1) << (i % 4 == 0 ? " " : "");
	}

	return EXIT_SUCCESS;
}