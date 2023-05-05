#pragma warning(disable:4996) // ���־� ��Ʃ������� sacnf ���� �������ִ� ����
#define _CRT_SECURE_NO_WARNINGS
// 4�� 11�� �����ͱ��� ����
// 19�й� 2�г� �̵���
// 5�� �����Ϳ� ���Ḯ��Ʈ
// �л� ���� ť �׽�Ʈ ���α׷� ���� 5.8
// ť�� ���������� �ƴ� ����ü Ÿ������ �����Ͽ� ���� ���� ť�� ����� �� �ִ� ���α׷�

#include <stdio.h>
#include <stdlib.h>

typedef int Element;

typedef struct LinkedNode
{
    Element data;
    struct LinkedNode* link;
} Node;

typedef struct Queue
{
    Node* front;
    Node* rear;
} Queue;

void error(char* str)
{
    fprintf(stderr, "%s\n", str);
    exit(1);
}

int is_empty(Queue* q)
{
    return q->front == NULL;
}

void init_queue(Queue* q)
{
    q->front = q->rear = NULL;
}

int size(Queue* q)
{
    Node* p;
    int count = 0;

    for (p = q->front; p != NULL; p = p->link)
        count++;

    return count;
}

void enqueue(Queue* q, Element e)
{
    Node* p = (Node*)malloc(sizeof(Node));
    p->data = e;
    p->link = NULL;

    if (is_empty(q))
        q->front = q->rear = p;
    else
    {
        q->rear->link = p;
        q->rear = p;
    }
}

Element dequeue(Queue* q)
{
    Node* p;
    Element e;

    if (is_empty(q))
        error(" ť ���� ����");

    p = q->front;
    q->front = q->front->link;

    if (q->front == NULL)
        q->rear = NULL;

    e = p->data;
    free(p);

    return e;
}

Element peek(Queue* q)
{
    if (is_empty(q))
        error(" ť ���� ����");

    return q->front->data;
}

void destroy_queue(Queue* q)
{
    while (is_empty(q) == 0)
        dequeue(q);
}

void print_queue(Queue* q, char* msg)
{
    Node* p;

    printf("%s[%2d] = ", msg, size(q));

    for (p = q->front; p != NULL; p = p->link)
        printf("%2d ", p->data);

    printf("\n");
}

int main()
{
    Queue q1, q2;
    int i;

    init_queue(&q1);
    init_queue(&q2);

    for (i = 1; i < 10; i++)
    {
        enqueue(&q1, i);
        enqueue(&q2, 2 * i);
    }

    print_queue(&q1, "Queue 1:");
    print_queue(&q2, "Queue 2:");

    printf("\nDequeue from Queue 1: %d\n", dequeue(&q1));
    printf("Dequeue from Queue 2: %d\n", dequeue(&q2));

    print_queue(&q1, "Queue 1:");
    print_queue(&q2, "Queue 2:");

    destroy_queue(&q1);
    destroy_queue(&q2);

    return 0;
}
