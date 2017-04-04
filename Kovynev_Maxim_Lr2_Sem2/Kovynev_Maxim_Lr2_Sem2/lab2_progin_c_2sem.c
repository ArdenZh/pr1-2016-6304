#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Stack				 // ���������, ����������� ����
{
	int value;			 // ��������
	struct Stack* next;		 // ��������� �� ��������� ������� �����
};

typedef struct Stack Stack;  // ���������� ���� ������ Stack

int go = 1;			// ���������� ������ �� ���������
				// 1 - ������ �� ����������, 0 - ������������ ������

/* ���������� �������� � ���� */
void push(struct Stack **head)
{
	int value = 0;
	scanf(" %d", &value);     // ���������� ������������ ��������
	struct Stack *tmp = (Stack*)malloc(sizeof(struct Stack));

	tmp->value = value;		  // ���������� �������� � ����� ���������
	tmp->next = *head;		  // ������������� �����
	*head = tmp;
	
	printf("ok\n");

}

/* �������� �������� �� ����� */
void pop(struct Stack **head)
{
	if (*head)                            // �������� �� ������������� �����
	{
		struct Stack *tmp = *head;
		printf("%d\n", (*head)->value);   // ����� ���������� �������� �� �����
		*head = (*head)->next;		  // �������� ��������� �� ����� �������� ������
		free(tmp);
	}
	else
	{
		printf("error\n");	 // ���� ����������� -> �������� ����������
		go = 0;                  // ������, ��������� ������ ���������
	}
}

/* ����� �������� �������� ����� */
void top(struct Stack *head)
{
	if (head == NULL)
	{
		printf("error\n");		// ���� ����������� -> �������� ����������
		go = 0;                         // ������, ��������� ������ ���������
		
	}
	else
	{
		printf("%d\n", head->value);    // ����� �������� �������� �����
	}
}

/* ���������� ��������� � ����� */
void size(Stack* head)  
{
	int count = 0;			    // ������������� �������� - ���������� ���������
	while (head != NULL)                // ���� ���������� ����, ����������� �������
	{
		count++;
		head = head->next;
	}

	printf("%d\n", count);             // ����� ��������

}

int main()
{
	Stack* head = NULL;
	char* string = (char*)malloc(sizeof(char) * 5);    // ��������� ������ ��� ������

	while (go == 1)					   // �������� �� ������� ������
	{
		fgets(string, 5, stdin);

		if (!(strcmp(string, "push")))
		{
			push(&head);			 // ���� ������� push - ��������� push();
		}
		else if (!(strcmp(string, "pop\n")))
		{
			pop(&head);			// ���� ������� pop - ��������� pop();
		}
		else if (!(strcmp(string, "top\n")))
		{
			top(head);			// ���� ������� top - ��������� top();
		}
		else if (!(strcmp(string, "size")))
		{
			size(head);			// ���� ������� size - ��������� size();
		}

		else if (!(strcmp(string, "exit")))
		{
			printf("bye\n");		// ��������� ������ ��������� 
			return 0;
		}

	}
	return 0;
}
