#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<cstdlib>

char* ssstrcat(char* str1, char* str2)
{
	int a = 0;
	int b = 0;
	char* res = str1;

	while (str1[a])
	{
		str1++;
	}

	while (str1[a++] = str2[b++]);

	return res;
}

int main(int argc, char** argv)
{
	FILE* f = fopen("in.txt", "r");

	char str1[256] = { 0 };
	char str2[256] = { 0 };
	fgets(str1, sizeof(str1), f);
	fgets(str2, sizeof(str2), f);

	fclose(f);

	char* res = ssstrcat(str1, str2);

	f = fopen("out.txt", "w");
	fprintf(f, "%s", res);

	fclose(f);

	return EXIT_SUCCESS;
}