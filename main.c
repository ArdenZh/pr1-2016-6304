#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void* p1, const void* p2)	//���������� ������� ��������� ���
{								//�����
    return strcmp((char*)p1, (char*)p2);	
}

int main()
{
    int counter=0;
    int i=0;					//������� � ����������
    int max=0;

    char text[1000];			//������ ��� ������ �� ����
    char str[30];				//������ ��� �������� �����
    char words[500][1000];		//������ ��� ��������� ������ �� �����

    fgets(text, 1000, stdin);		//���� � �������� ������ � ������
    (*strstr(text, "\n"))='\0';		//��� �������
    fgets(str, 30, stdin);

    char* token=strtok(text, " .");		//���������� ������ �� �����
    while(token!=NULL)
    {
        int numb=strlen(token);			//������� ����� ������� �����
        strncpy(words[i], token, numb);		//����������� � ������ ����
        token=strtok(NULL, " ,");
        i++;
    }

    qsort(words, i, 1000, cmp);			//������� ������� ����������

    char* pointer=(char*)bsearch(str, words, i, 1000, cmp);	//������� ���������
											//������
    if(pointer!=NULL)
    {
        printf("exists\n");
    }
    else								//����� ���������� ������
    {
        printf("doesn't exist");
    }

    return 0;
}
