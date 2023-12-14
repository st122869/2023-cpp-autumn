#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<cstdlib>

int strcmp(char* a, char* b)
{
    while (*a)
    {
        if (*a != *b) 
        {
            break;
        }

        a++;
        b++;
    }

    return *a - *b;
}

int main(int argc, char** argv)
{
    FILE* f = fopen("in.txt", "r");

    char str1[256] = { 0 };
    char str2[256] = { 0 };
    fgets(str1, 100, f);
    fgets(str2, 100, f);

    fclose(f);

    int n = strcmp(str1, str2);
    f = fopen("out.txt", "w");

    if (n > 0) 
    {
        fprintf(f, "%s", "str1 > str2");
    }
    else if (n < 0) 
    {
        fprintf(f, "%s", "str1 < str2");
    }
    else 
    {
        fprintf(f, "%s", "str1 = str2");
    }

    fclose(f);

    return EXIT_SUCCESS;
}