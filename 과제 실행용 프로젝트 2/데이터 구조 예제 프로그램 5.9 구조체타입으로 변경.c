#pragma warning(disable:4996) // ���־� ��Ʃ������� sacnf ���� �������ִ� ����
#define _CRT_SECURE_NO_WARNINGS
// 4�� 11�� �����ͱ��� ����
// 19�й� 2�г� �̵���
// 5�� �����Ϳ� ���Ḯ��Ʈ
// ����� ���� �׽�Ʈ ���α׷� ���� 5.9 �л� ���� ť �׽�Ʈ ���α׷� 
// ť�� ���������� �ƴ� ����ü Ÿ������ �����Ͽ� ���� ���� ť�� ����� �� �ִ� ���α׷����� ����

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUEUE_SIZE 100

typedef struct Student {
    int id;
    char name[32];
    char dept[32];
} Student;

typedef struct LinkedQueue {
    Student* data;
    int front;
    int rear;
} Queue;

void error(char* str) 
{
    fprintf(stderr, "%s\n", str);
    exit(1);
}

void init_queue(Queue* q) 
{
    q->data = (Student*)malloc(sizeof(Student) * MAX_QUEUE_SIZE);
    q->front = 0;
    q->rear = 0;
}

int is_empty(Queue* q) 
{
    return q->front == q->rear;
}

int is_full(Queue* q)
{
    return (q->rear + 1) % MAX_QUEUE_SIZE == q->front;
}

int size(Queue* q) 
{
    return (q->rear - q->front + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
}

void enqueue(Queue* q, Student e) 
{
    if (is_full(q)) {
        error("ť�� ��ȭ �����Դϴ�.");
    }
    q->data[q->rear] = e;
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
}

Student dequeue(Queue* q) 
{
    if (is_empty(q)) 
    {
        error("ť�� ���� �����Դϴ�.");
    }
    Student e = q->data[q->front];
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    return e;
}

Student peek(Queue* q) 
{
    if (is_empty(q)) 
    {
        error("ť�� ���� �����Դϴ�.");
    }
    return q->data[q->front];
}

void destroy_queue(Queue* q) 
{
    free(q->data);
    q->data = NULL;
    q->front = q->rear = 0;
}

void print_queue(Queue* q, char* msg) 
{
    printf("%s[%2d] = ", msg, size(q));
    int i;

    for (i = q->front; i != q->rear; i = (i + 1) % MAX_QUEUE_SIZE) 
    {
        printf("\n\t%-15d %-10s %-20s ", q->data[i].id, q->data[i].name, q->data[i].dept);
    }

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

int main()
{
    Queue q1, q2; // ť �� �� ����
    init_queue(&q1);
    init_queue(&q2);

    enqueue(&q1, get_student(2018130007, "ȫ�浿", "��ǻ�Ͱ��а�"));
    enqueue(&q1, get_student(2018130100, "�̼���", "�����а�"));
    enqueue(&q2, get_student(2018130135, "�迬��", "ü����"));
    enqueue(&q2, get_student(2018130135, "Ȳ��", "���а�"));

    print_queue(&q1, "ù ��° �л� ť(2�� ����)");
    print_queue(&q2, "�� ��° �л� ť(2�� ����)");

    dequeue(&q1);
    dequeue(&q2);

    print_queue(&q1, "ù ��° �л� ť(1�� ����)");
    print_queue(&q2, "�� ��° �л� ť(1�� ����)");

    destroy_queue(&q1);
    destroy_queue(&q2);

    return 0;
}
