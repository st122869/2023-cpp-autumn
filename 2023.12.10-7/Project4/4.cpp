#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<cstdlib>

char* ssubstr(const char* str, int b, int a)
{
	int len = a - b;
	char* sub = (char*)calloc(len + 1, sizeof(char));

	for (int i = b; i < a && (*(str + i) != '\0'); i++)
	{
		*sub = *(str + i);
		sub++;
	}

	return (sub - len);
}

int main(int argc, char** argv)
{
	FILE* f = fopen("in.txt", "r");

	char str[256] = { 0 };
	fgets(str, sizeof(str), f);

	fclose(f);

	char* res = ssubstr(str, 2, 5);

	f = fopen("out.txt", "w");
	fprintf(f, "%s", res);

	fclose(f);

	return EXIT_SUCCESS;
}