#pragma warning(disable:4996) // ���־� ��Ʃ������� sacnf ���� �������ִ� ����
#define _CRT_SECURE_NO_WARNINGS
// 4�� 11�� �����ͱ��� ����
// 19�й� 2�г� �̵���
// 5�� �����Ϳ� ���Ḯ��Ʈ
// ����� ���� �׽�Ʈ ���α׷� ���� 5.5

#include <stdio.h>
#include <stdlib.h>

typedef int Element;
typedef struct LinkedNode
{
	Element data;                            // ������ ����
	struct LickedNode* link;                 // ���� ��带 ����Ű�� ������ ����
} Node;

Node *top = NULL;                           // ���� ����Ʈ�� ��� ������

void error(char* str)
{

	fprintf(stderr, "%s\n", str);
	exit(1);

};

int is_empty() { return top == NULL; }
void init_stack() { top = NULL; }

int size()
{

	Node* p;
	int count = 0;

	for (p = top; p != NULL; p = p->link)
		count++;

	return count;
}

void push(Element e)
{

	Node* p = (Node*)malloc(sizeof(Node));  // ��� ���� �Ҵ�

	p->data = e;                            // ������ �ʵ� �ʱ�ȭ

	p->link = top;
	top = p;

}

Element pop()
{

	Node* p;
	Element e;

	if (is_empty())
		error("���� ���� ����");

	p = top;
	top = p->link;
	e = p->data;      // �׸� �����͸� �����صд�

	free(p);          // ��� ���� ����.

	return e;         // ������ �׸��� �����͸� ��ȯ.

}

Element peek()
{

	if (is_empty())
		error("���� ���� ����");

	return top->data;

}

void destroy_stack()
{

	while (is_empty() == 0)
		pop();

}

void print_stack(char* msg)
{

	Node* p;

	printf("%s[%2d] = ", msg, size());

	for (p = top; p != NULL; p = p->link)
		printf("%2d ", p->data);

	printf("\n");

}

void main()
{

	int i;

	init_stack();

	for (i = 1; i < 10; i++)
		push(i);

	print_stack("����� ���� push 9ȸ");
	printf("\tpop() --> %d\n", pop());
	printf("\tpop() --> %d\n", pop());
	printf("\tpop() --> %d\n", pop());
	print_stack("����� ���� pop  3ȸ");
	
	destroy_stack();

	print_stack("����� ���� destroy ");

}