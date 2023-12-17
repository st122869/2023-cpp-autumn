#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<cstdlib>

int main(int argc, char** argv)
{
	int len_of_snt = 0;
	int words = 0;
	int max = 0;
	int max_start = 0;
	int max_end = 0;
	int start = 0;

	char ch = 0;
	int ind = 0;

	FILE* f = fopen("in.txt", "r");

	while (!feof(f))
	{
		ind++;
		ch = fgetc(f);
		if (ch == ' ')
		{
			words++;
			len_of_snt++;
		}
		else if (ch == '.' || ch == '?')
		{
			if (len_of_snt > max)
			{
				max = len_of_snt;
				max_end = ind;
				max_start = start;
			}
			len_of_snt = 0;
			start = ind + 1;
		}
	}

	FILE* f2 = fopen("out.txt", "w");
	fprintf(f2, "%d\n", words);

	fseek(f, max_start, SEEK_SET);

	for (int i = max_start; i < max_end + 1; i++)
	{
		fprintf(f2, "%c", fgetc(f));
	}

	fclose(f);
	fclose(f2);

	return EXIT_SUCCESS;
}