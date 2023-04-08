#pragma warning(disable:4996) // ���־� ��Ʃ������� sacnf ���� �������ִ� ����
// 3�� 23�� �����ͱ��� ����
// 19�й� 2�г� �̵��� 201911079
// 
// ����
// ��ȣ�˻� ���α׷� ���� 3.3

#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100

typedef int Element;

Element data[MAX_STACK_SIZE];

int top;


void error(char str[])
{

	printf("%s\n", str);
	exit(1);

}

void init_stack() { top = -1; }
int is_empty() { return top == -1; }
int is_full() { return top == MAX_STACK_SIZE - 1; }
int size() { return top + 1; }

void push(Element e)
{

	if (is_full())
		error("���� ��ȭ ����");

	data[++top] = e;
}

Element pop()
{

	if (is_empty())
		error("���� ���� ����");

	return data[top--];
}

Element peek()
{

	if (is_empty())
		error("���� ���� ����");

	return data[top];
}

int check_maching(char expr[])
{

	int i = 0, prev;
	char ch;

	init_stack();

	while (expr[i] != '\0')
	{
		ch = expr[i++];

		if (ch == '[' || ch == '(' || ch == '{')
			push(ch);

		else if (ch == ']' || ch == ')' || ch == '}')
		{
			if (is_empty())
				return 2;                              // ���� 2 ����

			prev = pop();

			if ((ch == ']' && prev != '[')
				|| (ch == ')' && prev != '(')
				|| (ch == '}' && prev != '{')) {
				return 3;                              // ���� 3 ����
			}
			
		}
	}

	if (is_empty() == 0)
		return 1;                                     // ���� 1 ����

	return 0;
}

void main()
{
	
	char expr[4][80] = { "{A[(i+1)]=0;}", "if((i==0) && (j==0)",
	"A[(i+1])=0;", "A[i] =f)(;" };

	int err, i;

	for (i = 0; i < 4; i++) 
	{
		err = check_maching(expr[i]);

		if (err == 0)
			printf(" ��ȣ����: %s\n", expr[i]);

		else
			printf(" ��ȣ����: %s (����%d ����)\n", expr[i], err);
	}
}