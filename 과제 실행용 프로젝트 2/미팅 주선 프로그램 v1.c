#pragma warning(disable:4996) // 비주얼 스튜디오에서 sacnf 오류 무시해주는 정의
// 4월 17일 데이터구조 과제
// 19학번 2학년 이동근
// 원형큐와 구조체 타입으로 선언한 미팅 프로그램

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
        error("큐가 포화 상태입니다.");

    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    q->data[q->rear] = c;

}

Customer dequeue(Queue* q)
{

    if (is_empty(q))
        error("큐가 공백 상태입니다.");

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

        printf("고객의 이름은? (종료는 -1) >> ");
        scanf("%s", name);

        if (strcmp(name, "-1") == 0)
            break;

        strcpy(c.name, name);
        printf("성별을 입력하세요. (남자는 m, 여자는 f) >> ");
        scanf(" %c", &gender);

        c.gender = gender;

        if (gender == 'm')
            enqueue(&male_queue, c);

        else if (gender == 'f')
            enqueue(&female_queue, c);

        else 
        {
            printf("잘못된 입력입니다.\n");
            continue;
        }

        int male_size = size(&male_queue);
        int female_size = size(&female_queue);

        if (male_size > 0 && female_size > 0) 
        {

            Customer male_customer = dequeue(&male_queue);
            Customer female_customer = dequeue(&female_queue);

            printf("커플 탄생 : %s과(와) %s\n", male_customer.name, female_customer.name);

        }
        else 
            printf("아직 대상자가 없습니다.\n");

    }

    printf("미팅 주선 프로그램을 종료합니다.\n");

    return 0;

}
