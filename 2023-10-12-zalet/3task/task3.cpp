#include <iostream>

int main(int argc, char* argv[])
{
    int n = 0;
    std::cin >> n;

    int a = 0;
    while (n != 0) 
    {
        a = n % 10;
        n /= 10;
        std::cout << a;
    }

	return EXIT_SUCCESS;
}
