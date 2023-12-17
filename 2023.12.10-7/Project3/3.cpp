#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<cstdlib>

int sstrstr(char* str1, char* str2)
{
	int res = 0;
	int a = 0;
	int b = 0;
	while (str1[a] != '\0')
	{
		if (str1[a] == str2[b])
		{
			res = a;
		}
		a++;
	}

	return (res - 1);
}

int main(int argc, char** argv)
{
	FILE* f = fopen("in.txt", "r");

	char str1[256] = { 0 };
	char str2[256] = { 0 };
	fgets(str1, sizeof(str1), f);
	fgets(str2, sizeof(str2), f);

	fclose(f);

	int res = sstrstr(str1, str2);

	f = fopen("out.txt", "w");

	fprintf(f, "%d", res);
	fclose(f);

	return EXIT_SUCCESS;
}