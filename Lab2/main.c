#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int flag = -1;//��������� �������

void push(char ** stack, char * element){ //�������� �������
    strcpy(stack[++flag],element); //���� �������� �����������
}

void pop(char ** stack){ //������ �������
    flag--;
}

int is_empty(){ //�������� �� �������
   return (flag == -1) ? 0 : 1;
}

int main(){
    char c; //���������� ���������� ����� ������� ��������� �����
    char tag[15]; //����� ��� ����
    char **stack;
    stack = (char**)malloc(100 * sizeof(char*)); //�������� ������ ��� ����, ������ ������� �������� - ������
        for (int i = 0; i<100; i++)
                stack[i] = (char*)malloc(15 * sizeof(char)); //������ ���� - ���
    while (c != '\n' ){ //�� ��� ��� ���� �� ����� ������
        scanf("%c",&c);  //��������� c
        if (c == '<') { //���� � <
            scanf("%15[^>]",tag); //�� �������� ��������� � ���� �� > (15 ����������� ���, ��� ����� ������� ��� 10 ��������, �� 5 �� ��������)
            if (strcmp(tag,"hr") && strcmp(tag,"br")){ //���� ��� �� br ��� hr
                if (tag[0] != '/') //���� ��������� ��� �� �����������
                    push(stack,tag);  // ����� � ����       
                else{ //�����
                    if (is_empty() == 0){ // ���� ���� ����
                        printf("wrong"); //�� ������
                        return 0; //�������
                    }
                    else{ //�����
                        if (strcmp(stack[flag],tag+1)){//���� ����������� ������� �� ���������
                            printf("wrong");
                            return 0;
                        }
                        else
                            pop(stack);  
                    }
                }
            }
        }                                       
    }
    if (!is_empty()) //�������� ������� ��������
        printf("correct");//���� ����, �� ��� ���� �������
    else
        printf("wrong");//� ���� ���, �� �� ���
}