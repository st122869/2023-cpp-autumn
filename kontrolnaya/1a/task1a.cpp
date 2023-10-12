#include<iostream>

int main(int argc, char* argv[])
{
    int n = 0;
    std::cin >> n;

    int c = 0;
    for (int i = 0; i < 32; ++i)
    {
        if ((n >> (31 - i) & 1) == 1)
        {
            ++c;
        }
    }

    std::cout << c;

    return EXIT_SUCCESS;
}