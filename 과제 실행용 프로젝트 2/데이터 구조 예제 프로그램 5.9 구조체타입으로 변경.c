#pragma warning(disable:4996) // 비주얼 스튜디오에서 sacnf 오류 무시해주는 정의
#define _CRT_SECURE_NO_WARNINGS
// 4월 11일 데이터구조 수업
// 19학번 2학년 이동근
// 5장 포인터와 연결리스트
// 연결된 스택 테스트 프로그램 예제 5.9 학생 정보 큐 테스트 프로그램 
// 큐를 전역변수가 아닌 구조체 타입으로 선언하여 여러 개의 큐를 사용할 수 있는 프로그램으로 변경

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
        error("큐가 포화 상태입니다.");
    }
    q->data[q->rear] = e;
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
}

Student dequeue(Queue* q) 
{
    if (is_empty(q)) 
    {
        error("큐가 공백 상태입니다.");
    }
    Student e = q->data[q->front];
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    return e;
}

Student peek(Queue* q) 
{
    if (is_empty(q)) 
    {
        error("큐가 공백 상태입니다.");
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
    Queue q1, q2; // 큐 두 개 선언
    init_queue(&q1);
    init_queue(&q2);

    enqueue(&q1, get_student(2018130007, "홍길동", "컴퓨터공학과"));
    enqueue(&q1, get_student(2018130100, "이순신", "기계공학과"));
    enqueue(&q2, get_student(2018130135, "김연아", "체육과"));
    enqueue(&q2, get_student(2018130135, "황희", "법학과"));

    print_queue(&q1, "첫 번째 학생 큐(2명 삽입)");
    print_queue(&q2, "두 번째 학생 큐(2명 삽입)");

    dequeue(&q1);
    dequeue(&q2);

    print_queue(&q1, "첫 번째 학생 큐(1명 삭제)");
    print_queue(&q2, "두 번째 학생 큐(1명 삭제)");

    destroy_queue(&q1);
    destroy_queue(&q2);

    return 0;
}
