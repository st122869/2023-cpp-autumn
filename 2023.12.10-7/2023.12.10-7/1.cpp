#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<cstdlib>

void ReadLines(char* filename, char** lines, int maxlen)
{
    FILE* f = fopen("in.txt", "r");

    int ind = 0;
    while (!feof(f))
    {
        fgets(lines[ind], maxlen, f);
    }

    fclose(f);
}

int sstrlen(char* str)
{
    int count = 0;
    while (str[count++] != '\0');
    return count;
}

void CountSize(char* filename, int & lines, int & maxLine)
{
	FILE* f = fopen("in.txt", "r");

	int currentLen = 0;
    while (!feof(f))
    {
        char c = 0;
        fscanf_s(f, "%c", &c);
        if (c == '\n')
        {
            lines++;
            maxLine = (maxLine > currentLen ? maxLine : currentLen);
            currentLen = 0;
        }
        else
        {
            currentLen++;
        }
    }
	
	fclose(f);
}

int main(int argc, char* argv[])
{
    
}