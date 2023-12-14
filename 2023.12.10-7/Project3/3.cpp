#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<cstdlib>

int sstrstr(char* a, char* b)
{
    int res = 0;
    int i = 0;
    int j = 0;
    while (a[i] != '\0')
    {
        if (a[i] == b[i + j])
        {
            res = j;
            i++;
        }
        else
        {
            i = 0;
            j++;
        }
    }

    return res;
}

int main(int argc, char** argv)
{
    FILE* f = fopen("in.txt", "r");

    char str1[256] = { 0 };
    char str2[256] = { 0 };
    fgets(str1, 100, f);
    fgets(str2, 100, f);

    fclose(f);

    char res = sstrstr(str1, str2);

    f = fopen("out.txt", "w");
    fprintf(f, "%s", res);
    fclose(f);

    return EXIT_SUCCESS;
}