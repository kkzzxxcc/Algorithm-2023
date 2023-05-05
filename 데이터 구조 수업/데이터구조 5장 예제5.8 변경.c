#pragma warning(disable:4996) // 비주얼 스튜디오에서 sacnf 오류 무시해주는 정의
#define _CRT_SECURE_NO_WARNINGS
// 4월 11일 데이터구조 수업
// 19학번 2학년 이동근
// 5장 포인터와 연결리스트
// 학생 정보 큐 테스트 프로그램 예제 5.8
// 큐를 전역변수가 아닌 구조체 타입으로 선언하여 여러 개의 큐를 사용할 수 있는 프로그램

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
        error(" 큐 공백 에러");

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
        error(" 큐 공백 에러");

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
