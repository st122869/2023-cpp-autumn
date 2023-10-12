#include<iostream>

typedef unsigned short ushort;

int main(int argc, char* argv[])
{
	ushort a = 0;
	ushort b = 0;
	ushort c = 0;
	std::cin >> a;
	std::cin >> b;

	const ushort BITS = sizeof(ushort) * 8;

	bool up = 0;
	for (int i = 0; i < BITS; ++i)
	{
		bool bitA = ((a >> i) & 1);
		bool bitB = ((b >> i) & 1);
		bool current = bitA ^ bitB ^ up;
		up = (bitA & bitB) | (bitA & up) | (bitB & up);
		c = c | ((ushort)current << i);
	}

	std::cout << a << " + " << b << " = " << c;

	return EXIT_SUCCESS;
}