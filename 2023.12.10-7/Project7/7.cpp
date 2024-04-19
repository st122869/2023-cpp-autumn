#include<iostream>
#include<fstream>
#include<string>

int main(int argc, char* argv[])
{
	std::ifstream fin("in.txt");
	std::string text = { 0 };
	std::string str = { 0 };

	while (!fin.eof())
	{
		std::getline(fin, str);
		text += str + ' ';
	}
	fin.close();

	int words = 0;
	int j = 0;
	char c = 0;

	for (c = ' '; j < text.size(); c = text[j++])
	{
		if (text[j] != ' ' && c == ' ')
		{
			words++;
		}
	}

	int* a = new int[words];
	int* b = new int[words];
	int* n = new int[words];
	int* r = new int[words];
	int k = 0;
	int ind = 0;
	int l = 0;
	int t = 0;
	for (j = 0; j < words; n[j++] = 0);
	for (k = 0, c = ' ', j = 0; j < text.size(); c = text[j++])
	{
		if (text[j] != ' ' && c == ' ')
		{
			a[k++] = j;
		}
		else if (text[j] == ' ' && c != ' ')
		{
			b[k - 1] = j;
		}
	}

	if (c != ' ')
	{
		b[k - 1] = j;
	}
	for (j = 0; j < words; j++)
	{
		if (n[j])
		{
			continue;
		}
		n[j] = 1;
		for (k = j + 1; k < words; k++)
		{
			if (n[k])
			{
				continue;
			}
			if (b[k] - a[k] == b[j] - a[j])
			{
				for (ind = 1, t = a[j], l = a[k]; l < b[k]; l++, t++)
				{
					if (text[t] != text[l])
					{
						ind = 0;
						break;
					}
				}
				if (ind)
				{
					n[k] = -1;
				    n[j]++;
				}
			}
		}
	}

	int max = 0;
	for (j = 0; j < words; j++)
	{
		if (n[j] > max)
		{
			max = n[j];
		}
	}
	int rm = 0;
	for (j = 0; j < words; j++)
	{
		if (max == n[j])
		{
			r[rm++] = j;
		}
	}

	std::ofstream fout("out.txt");
	for (k = 0; k < rm; k++)
	{
		for (j = a[r[k]]; j < b[r[k]]; j++)
		{
			fout << text[j];
		}
	}

	fout.close();

	delete[] a;
	delete[] b;
	delete[] n;
	delete[] r;

	return EXIT_SUCCESS;
}