#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<cstdlib>

int sstrlen(char* str)
{
    int count = 0;
    while (str[count++] != '\0');
    return count;
}

char* sstrmult(const char* str, int n)
{
    
}

int main(int argc, char* argv[])
{
    FILE* f = fopen("in.txt", "r");

    char str[256] = { 0 };
    fgets(str, 100, f);

    fclose(f);

    char* res = sstrmult(str, 3);

    f = fopen("out.txt", "w");
    fprintf(f, "%s", res);
    fclose(f);

    return EXIT_SUCCESS;
}