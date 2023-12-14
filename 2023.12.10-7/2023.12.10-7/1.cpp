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
    FILE* fp, * out;
    char ch;
    if ((fp = fopen("in.txt", "r")) == NULL) {
        printf("���������� ������� ���� ��� ������");
        exit(1);
    }
    if ((out = fopen("out.txt", "wb")) == NULL) {
        printf("���������� ������� ���� ��� ������");
        exit(1);
    }

    int count = 0;//���������� ����
    int len_word = 0;//����� �����, ����������� ������� ������
    int count_words = 0;//���������� ���� � �����������
    int maxSent = 0; // ���� ���������� ���� � ������������
    int begin = 0;//������ �����������
    int begin_max = 0;//������ �����������
    int end_max = 0;//����� �����������
    int pos = 0;

    while (!feof(fp)) {
        ch = getc(fp);
        pos++;
        if ((ch == ' ') && (len_word != 0)) {
            count++;
            len_word = 0;
            count_words++;
        }
        else if ((ch == '.') && (len_word != 0)) {

            if (count_words > maxSent) {
                maxSent = count_words;
                end_max = pos;
                begin_max = begin;
            }
            count_words = 0;
            begin = pos + 1;
        }
        else {
            len_word++;
        }
    }
    if (len_word > 0) { //������������ ��������� ����� � �����
        count++;
        count_words++;
        if (count_words > maxSent) {
            maxSent = count_words;
            end_max = pos;
            begin_max = begin;
        }
    }


    fprintf(out, "Words in file % d\n", count);
    fprintf(out, "More longest sen % d\n", maxSent);
    //������� ����� ������� �����������
    if (fseek(fp, begin_max, SEEK_SET) == 0) {
        for (int i = 0; i < (end_max - begin_max); i++)

            fprintf(out, "%c", getc(fp));
    }

    fclose(fp);
    fclose(out);

	return EXIT_SUCCESS;
}