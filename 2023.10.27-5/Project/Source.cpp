#include <iostream>
#include "Header.h"
#include <stdlib.h>

int main(int argc, char* argv[])
{
	int* a = nullptr;
	int len = 0;

	std::cin >> len;
	a = new int[len];

	for (int i = 0; i < len; ++i)
	{
		std::cin >> a[i];
	}

	bool exit = false;
	while (!exit)
	{
		{
			system("cls");
			printMenu();
			printArray(a, len);
		}
		int choice = 0;
		{
			std::cin >> choice;
		}
		{
			switch (choice)
			{
			case 0:
				exit = true;
				break;
			case 1:
				printArray(a, len);
				system("pause");
				break;
			case 2:
			{
				int element = 0;
				std::cout << "Input element to add : ";
				std::cin >> element;
				addElement(a, len, element);
				break;
			}
			case 3:
			{
				int index = 0;
				std::cout << "Input index to extract : ";
				std::cin >> index;
				std::cout << "Extracted  " << extractElement(a, len, index) << std::endl;
				break;
			}
			case 4:
			{
				std::cout << "Sorted: ";
				Sort(a, len);
				for (int i = 0; i < len; i++)
				{
					std::cout << a[i] << " ";
				}
				system("pause");
				break;
			}
			case 5:
			{
				std::cout << "Reversed: ";
				printReverseArray(a, len);
				system("pause");
				break;
			}
			case 6:
			{
				std::cout << "Places of min and max are swapped: ";
				swapPlaces(a, len);
				system("pause");
				break;
			}
			case 7:
			{
				std::cout << "Without dublicates: ";
				withoutDublicates(a, len);
				system("pause");
				break;
			}
			case 8:
			{
				int n = 0;
				std::cout << "Enter the number of elements to add: ";
				std::cin >> n;

				std::cout << "With n random elements: ";
				for (int i = 0; i < n; ++i)
				{
					int element = rand();
					addElement(a, len, element);
				}
			}

			default:
				std::cout << "Unknown command" << std::endl;
				break;
			}
		}
	}
	return EXIT_SUCCESS;
}


void printArray(int* a, int len)
{
	if (a == nullptr)
	{
		std::cout << "EMPTY";
	}
	else
	{
		for (int i = 0; i < len; ++i)
		{
			std::cout << a[i] << " ";
		}
	}
	std::cout << std::endl;
}

void expandArray(int*& a, int& len)
{
	int* newA = new int[len + 1] { 0 };
	if (a != nullptr)
	{
		for (int i = 0; i < len; ++i)
		{
			newA[i] = a[i];
		}
		delete[] a;
	}
	a = newA;
	++len;
}

void addElement(int*& a, int& len, int element)
{
	expandArray(a, len);
	a[len - 1] = element;
}

void contractArray(int*& a, int& len)
{
	if (a != nullptr)
	{
		int* newA = new int[len - 1];
		for (int i = 0; i < len - 1; ++i)
		{
			newA[i] = a[i];
		}
		delete[] a;
		a = newA;
		--len;
	}
}

bool indexValid(int index, int len)
{
	return (index >= 0 && index < len);
}

int extractElement(int*& a, int& len, int index)
{
	int res = -1;
	if (indexValid(index, len))
	{
		res = a[index];
		for (int i = index; i < len - 1; ++i)
		{
			a[i] = a[i + 1];
		}
		contractArray(a, len);
	}
	return res;
}

void printReverseArray(int* a, int len)
{
	if (a == nullptr)
	{
		std::cout << "EMPTY";
	}
	else
	{
		for (int i = 0; i < len; ++i)
		{
			std::cout << a[len - i - 1] << " ";
		}
	}
	std::cout << std::endl;
}

void printMenu()
{
	std::cout << "0 - Exit" << std::endl;
	std::cout << "1 - Print array" << std::endl;
	std::cout << "2 - Append element to array" << std::endl;
	std::cout << "3 - Extract element from array" << std::endl;
	std::cout << "4 - Sort" << std::endl;
	std::cout << "5 - Reverse" << std::endl;
	std::cout << "6 - Swap places" << std::endl;
	std::cout << "7 - Without dublicates" << std::endl;
	std::cout << "8 - Add n random elements" << std::endl;
}

void swapPlaces(int* a, int len)
{
	if (a == nullptr)
	{
		std::cout << "EMPTY";
	}
	else
	{
		int max = a[0];
		int max_i = 0;
		for (int i = 0; i < len; ++i)
		{
			if (a[i] > max)
			{
				max = a[i];
				max_i = i;
			}
		}

		int min = max;
		int min_i = 0;
		for (int i = 0; i < len; ++i)
		{
			if (a[i] <= min)
			{
				min = a[i];
				min_i = i;
			}
		}

		a[max_i] = min;
		a[min_i] = max;

		for (int i = 0; i < len; ++i)
		{
			std::cout << a[i] << " ";
		}
	}
	std::cout << std::endl;
}

void withoutDublicates(int*& a, int& len)
{
	for (int i = 0; i < len; ++i)
	{

		for (int j = i + 1; j < len; ++j)
		{
			if (a[i] == a[j])
			{
				for (int k = i; k < len - 1; ++k)
				{
					a[k] = a[k + 1];
				}
				len--;
			}
		}

		std::cout << a[i] << " ";
	}
}

void Sort(int*& a, int& len)
{
	for (int i = 1; i < len; i++)
	{
		int j = i - 1;
		while (j >= 0 && a[j] > a[j + 1])
		{
			std::swap(a[j], a[j + 1]);
			j--;
		}
	}
}
