#pragma warning(disable:4996) // 비주얼 스튜디오에서 sacnf 오류 무시해주는 정의
// 3월 23일 데이터구조 수업
// 19학번 2학년 이동근 201911079
// 
// 스택
// 괄호검사 프로그램 예제 3.3

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
		error("스택 포화 에러");

	data[++top] = e;
}

Element pop()
{

	if (is_empty())
		error("스택 공백 에러");

	return data[top--];
}

Element peek()
{

	if (is_empty())
		error("스택 공백 에러");

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
				return 2;                              // 조건 2 위반

			prev = pop();

			if ((ch == ']' && prev != '[')
				|| (ch == ')' && prev != '(')
				|| (ch == '}' && prev != '{')) {
				return 3;                              // 조건 3 위반
			}
			
		}
	}

	if (is_empty() == 0)
		return 1;                                     // 조건 1 위반

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
			printf(" 괄호정상: %s\n", expr[i]);

		else
			printf(" 괄호오류: %s (조건%d 위반)\n", expr[i], err);
	}
}