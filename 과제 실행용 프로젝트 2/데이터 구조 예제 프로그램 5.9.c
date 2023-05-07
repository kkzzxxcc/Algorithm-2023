#pragma warning(disable:4996) // ���־� ��Ʃ������� sacnf ���� �������ִ� ����
#define _CRT_SECURE_NO_WARNINGS
// 4�� 11�� �����ͱ��� ����
// 19�й� 2�г� �̵���
// 5�� �����Ϳ� ���Ḯ��Ʈ
// ����� ���� �׽�Ʈ ���α׷� ���� 5.9
// �л� ���� ť �׽�Ʈ ���α׷�

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student
{
	int id;
	char name[32];
	char dept[32];
} Student;

typedef Student Element;

typedef struct LinkedNode
{
	Element data;                            // ������ ����
	struct LickedNode* link;                 // ���� ��带 ����Ű�� ������ ����
} Node;

Node* front = NULL;                           // ���� ����Ʈ�� ��� ������
Node* rear = NULL;

void error(char* str)
{

	fprintf(stderr, "%s\n", str);
	exit(1);

};

int is_empty() { return front == NULL; }
void init_queue() { front = rear = NULL; }

int size()
{

	Node* p;
	int count = 0;

	for (p = front; p != NULL; p = p->link)
		count++;

	return count;
}

void enqueue(Element e)
{

	Node* p = (Node*)malloc(sizeof(Node));   // ��� ���� �Ҵ�
	p->data = e;                             // ������ �ʵ� �ʱ�ȭ
	p->link = NULL;                          // ��ũ �ʵ� �ʱ�ȭ

	if (is_empty())
		front = rear = p;

	else
	{
		rear->link = p;
		rear = p;
	}
}

Element dequeue()
{

	Node* p;
	Element e;

	if (is_empty())
		error(" ť ���� ����");

	p = front;
	front = front->link;

	if (front == NULL)
		rear = NULL;

	e = p->data;                  // p�� �׸� ����
	free(p);                      // p�� ���� ����

	return e;                     // ����� �׸��� ��ȯ

}

Element peek()
{

	if (is_empty())
		error("���� ���� ����");

	return front->data;

}

void destroy_queue()
{

	while (is_empty() == 0)
		dequeue();

}

void print_queue(char* msg)
{

	Node* p;

	printf("%s[%2d] = ", msg, size());

	for (p = front; p != NULL; p = p->link)
		printf("\n\t%-15d %-10s %-20s ", p->data.id, p->data.name, p->data.dept);

	printf("\n");

}

Student get_student(int id, char* name, char* dept)
{

	Student s;
	s.id = id;
	strcpy(s.name, name);
	strcpy(s.dept, dept);

	return s;

}

void main()
{

	init_queue();

	enqueue(get_student(2018130007, "ȫ�浿", "��ǻ�Ͱ��а�"));
	enqueue(get_student(2018130100, "�̼���", "�����а�"));
	enqueue(get_student(2018130135, "�迬��", "ü����"));
	enqueue(get_student(2018130135, "Ȳ��", "���а�"));

	print_queue("����� �л� ť(4�� ����)");
	dequeue();
	print_queue("����� �л� ť(1�� ����)");
	destroy_queue();


}