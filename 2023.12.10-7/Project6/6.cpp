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
    char* res = (char*)malloc(sizeof(char*) * (len + 1));
    int a = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < sstrlen(str); j++)
        {
            res[a] = str[j];
            a++;
        }
    }
    res[len] = '\0';

    return res;
}

int main(int argc, char** argv)
{
    FILE* f = fopen("in.txt", "r");

    char str[256] = { 0 };
    fgets(str, 100, f);

    int n = 0;
    fscanf(f, "%s", &n);

    fclose(f);

    char* res = sstrmult(str, n);

    f = fopen("out.txt", "w");
    fprintf(f, "%s", res);
    fclose(f);

    return EXIT_SUCCESS;
}