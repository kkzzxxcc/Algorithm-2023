#pragma warning(disable:4996) // ���־� ��Ʃ������� sacnf ���� �������ִ� ����
// 3�� 23�� �����ͱ��� ����
// 19�й� 2�г� �̵��� 201911079
// 
// ����
// ǥ�� ���� ��� ���� 3.4

#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100

typedef double Element;

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

double calc_postfix(char expr[])
{

	char c;
	int i = 0;
	double val, val1, val2;

	init_stack();

	while (expr[i] != '\0')
	{
		c = expr[i++];

		if (c >= '0' && c <= '9')
		{
			val = c - '0';
			push(val);
		}
		else if (c == '+' || c == '-' || c == '*' || c == '/')
		{
			val2 = pop();
			val1 = pop();

			switch (c)
			{
			case '+': push(val1 + val2); break;
			case '-': push(val1 - val2); break;
			case '*': push(val1 * val2); break;
			case '/': push(val1 / val2); break;

			}
		}

	}

}
			
void main()
{
    
	char expr[2][80] = { "8 2 / 3- 3 2 * +", "1 2 / 4 * 1 4 / *" };

	printf("����: %s = %lf\n", expr[0], calc_postfix(expr[0]));
	printf("����: %s = %lf\n", expr[1], calc_postfix(expr[1]));

}
