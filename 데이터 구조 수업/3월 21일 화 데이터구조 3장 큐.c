// 3�� 21�� �����ͱ��� ����
// 19�й� 2�г� �̵��� 201911079
// 
// ����
// �迭�� �̿��� int ������ ����
// �迭�� �̿��� Student ������ ����
// �����ͷ� ����
// 

#pragma warning(disable:4996) // ���־� ��Ʃ������� sacnf ���� �������ִ� ����

#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100          // ���� ��� ������ ���� �迭�� ũ��

// typedef int Element;                // ���� ����� �ڷ��� ����

typedef struct Student
{
	int id;                     // �̸�
	char name[32];              // �й�
	char dept[32];              // �а�

} Student;                      // ���� ��� ������ ���� �迭�� ũ��

typedef Student Element;        // ���� ����� �ڷ��� ����

// Element data[MAX_STACK_SIZE];       // ���� ���� ����� �迭

// int top;                            // ���� ������ top

typedef struct stack                   // ������ ����ü ����
{
	Element data[MAX_STACK_SIZE];
	int top;
} Stack;

void init_stack(Stack* s);
int is_empty(Stack* s);
int is_full(Stack* s);
int size(Stack* s);
void push(Stack* s, Element e);
Element pop(Stack* s);
Element peek(Stack* s);
void print_stack(Stack s, char msg[]);


// ���� ��Ȳ ó���� ���� �Լ�. �޽����� ��� �� ���α׷� ����.
void error(char str[])
{
	printf("%s \n", str);
	exit(1);
}

// ������ �ֿ� ����
void init_stack(Stack *s) { s -> top = -1; }
int size(Stack *s) { return s -> top + 1; }
int is_empty(Stack *s) { return s -> top == -1; }
int is_full(Stack *s) { return s -> top == MAX_STACK_SIZE - 1; }


void push(Stack *s, Element e)
{
	if (is_full(s))
		error("���� ��ȭ ����");
	s -> data[++s -> top ]= e;
}


Element pop(Stack *s)
{
	if (is_empty(s))
		error("���� ���� ����");
	return s -> data[s -> top--];
}

Element peek(Stack *s)
{
	if (is_empty(s))
		error("���� ���� ����");
	return s -> data[s -> top];
}


// ���� �׽�Ʈ�� ���� �ڵ� : ��� �������� ����
void print_stack(Stack s, char msg[]) 
{
	int i;

	printf("%s[%1d]= ", msg, size(&s));

	for (i = 0; i < size(&s); i++)
		printf("\n\t %-15d  %-10s  %-20s", s.data[i].id, s.data[i].name, s.data[i].dept);

	printf("\n");

}

Student get_student(int id, char name[], char dept[])
{

	Student s;
	s.id = id;
	strcpy(s.name, name);  // ���ڿ� ����. s.name = name�� ����
	strcpy(s.dept, dept);  // ���ڿ� ����. s.dept = dept�� ����

	return s;

}

void main()
{
	Stack s;
	Element e;
	init_stack(&s);

	push(&s, get_student(201911079, "ȫ�浿", "��ǻ�Ͱ��а�"));
	push(&s, get_student(201231107, "�̼���", "�����а�"));
	push(&s, get_student(201494789, "�迬��", "ü����"));
	push(&s, get_student(209472079, "Ȳ��", "���а�"));

	print_stack(s, " ģ�� 4�� ���� �� ");
	pop(&s);
	print_stack(s, " ģ�� 1�� ���� �� ");
	e = peek(&s);

	printf("ID = %d, Name = %s, Dept.Name = %s \n", e.id, e.name, e.dept);
	print_stack(s, "After peek()");

	return 0;

}

/* void main()
{
	int i;
	init_stack();

	for (i = 1; i < 10; i++)
		push(i);

	print_stack("���� push 9ȸ");
	printf("\tpop() --> %d\n", pop());
	printf("\tpop() --> %d\n", pop());
	printf("\tpop() --> %d\n", pop());
	print_stack("���� pop 3ȸ");

}

*/