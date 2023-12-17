#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<cstdlib>

int sstrlen(char* str)
{
    int res = 0;
    while (str[res++] != '\0');
    return res;
}

char* sstrmult(char* str, int n)
{
    int len = (sstrlen(str)) * n;
    char* res = (char*)calloc(len, sizeof(char*));
    int a = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < sstrlen(str); j++)
        {
            res[a] = str[j];
            a++;
        }
    }

    return res;
}

int main(int argc, char** argv)
{
    FILE* f = fopen("in.txt", "r");

    char str[256] = { 0 };
    fgets(str, sizeof(str), f);
    fclose(f);

    char* res = sstrmult(str, 3);

    f = fopen("out.txt", "w");
    fprintf(f, "%s", res);
    fclose(f);

    return EXIT_SUCCESS;
}