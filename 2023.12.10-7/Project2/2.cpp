#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<cstdlib>

char* sstrcat(char* str1, char* str2)
{
	int a = 0;
	int b = 0;
		for (a = 0; str1[a] != '\0'; a++)
		{
			for (b = 0; str2[b] != '\0'; b++)
			{
				str1[a + b] = str2[b];
			}
		}
		str1[a + b] = '\0';
		return str1;
}

int main(int argc, char** argv)
{
	FILE* f = fopen("in.txt", "r");

	char str1[256] = { 0 };
	char str2[256] = { 0 };
	fgets(str1, 10, f);
	fgets(str2, 10, f);

	fclose(f);

	char* res = sstrcat(str1, str2);

	f = fopen("out.txt", "w");
	fprintf(f, "%s", res);
	fclose(f);

	return EXIT_SUCCESS;
}

