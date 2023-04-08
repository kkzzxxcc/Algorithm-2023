#pragma warning(disable:4996) // ���־� ��Ʃ������� sacnf ���� �������ִ� ����
// 4�� 4�� �����ͱ��� ����
// 19�й� 2�г� �̵���
// 4�� ť
// ���� ť ���α׷� 4.1

#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 100

typedef double Element;

Element data[MAX_QUEUE_SIZE]; // ����� �迭

int front;                    // ����
int rear;                     // �Ĵ�

void error(char str[])
{

	printf("%s\n", str);
	exit(1);

}

// ť�� �ֿ� ���� : ����
void init_queue() { front = rear = 0; ; }
int is_empty() { return front == rear; }
int is_full() { return front == (rear + 1) % MAX_QUEUE_SIZE; }
int size() { return (rear - front + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE; }

void enqueue( Element val )
{

	if (is_full())
		error(" ť ��ȭ ����");

	rear = (rear + 1) % MAX_QUEUE_SIZE;
	data[rear] = val;
}

Element dequeue()
{

	if (is_empty())
		error(" ť ���� ����");

	front = (front + 1) % MAX_QUEUE_SIZE;

	return data[front];
}

Element peek()
{

	if (is_empty())
		error(" ť ���� ����");

	return data[(front + 1) % MAX_QUEUE_SIZE];
}

// ť �׽�Ʈ�� ���� �ڵ� : ��� �������� ����
void print_queue(char msg[])
{
	int i, maxi = rear;

	if (front >= rear)
	{
		maxi += MAX_QUEUE_SIZE;
		printf("%s[%2d] = ", msg, size());
	}

	for (i = front + 1; i <= maxi; i++)
		printf("%2d ", data[i % MAX_QUEUE_SIZE]);

	printf("\n");
}

void main()
{
	int i;

	init_queue();

	for (i = 1; i < 10; i++)
		enqueue(i);

	print_queue("����ť enqueue 9ȸ");
	printf("\tdequeue() --> %d\n", dequeue());
	printf("\tdequeue() --> %d\n", dequeue());
	printf("\tdequeue() --> %d\n", dequeue());
	print_queue("����ť dequeue 3ȸ");
}