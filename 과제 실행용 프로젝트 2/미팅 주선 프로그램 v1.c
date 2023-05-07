#pragma warning(disable:4996) // ���־� ��Ʃ������� sacnf ���� �������ִ� ����
// 4�� 17�� �����ͱ��� ����
// 19�й� 2�г� �̵���
// ����ť�� ����ü Ÿ������ ������ ���� ���α׷�

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_QUEUE_SIZE 100

typedef struct meeting_customer 
{
    char name[20];
    char gender;

} Customer;

typedef struct CircularQueue
{

    Customer data[MAX_QUEUE_SIZE];
    int front;
    int rear;

} Queue;

void error(char* msg)
{
    printf("%s\n", msg);
    exit(1);
}

void init_queue(Queue* q)
{
    q->front = q->rear = 0;
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

void enqueue(Queue* q, Customer c)
{

    if (is_full(q))
        error("ť�� ��ȭ �����Դϴ�.");

    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    q->data[q->rear] = c;

}

Customer dequeue(Queue* q)
{

    if (is_empty(q))
        error("ť�� ���� �����Դϴ�.");

    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    return q->data[q->front];

}


int main()
{

    Queue male_queue, female_queue;
    Customer c;
    char name[20];
    char gender;

    srand(time(NULL));

    init_queue(&male_queue);
    init_queue(&female_queue);

    while (1) 
    {

        printf("���� �̸���? (����� -1) >> ");
        scanf("%s", name);

        if (strcmp(name, "-1") == 0)
            break;

        strcpy(c.name, name);
        printf("������ �Է��ϼ���. (���ڴ� m, ���ڴ� f) >> ");
        scanf(" %c", &gender);

        c.gender = gender;

        if (gender == 'm')
            enqueue(&male_queue, c);

        else if (gender == 'f')
            enqueue(&female_queue, c);

        else 
        {
            printf("�߸��� �Է��Դϴ�.\n");
            continue;
        }

        int male_size = size(&male_queue);
        int female_size = size(&female_queue);

        if (male_size > 0 && female_size > 0) 
        {

            Customer male_customer = dequeue(&male_queue);
            Customer female_customer = dequeue(&female_queue);

            printf("Ŀ�� ź�� : %s��(��) %s\n", male_customer.name, female_customer.name);

        }
        else 
            printf("���� ����ڰ� �����ϴ�.\n");

    }

    printf("���� �ּ� ���α׷��� �����մϴ�.\n");

    return 0;

}
