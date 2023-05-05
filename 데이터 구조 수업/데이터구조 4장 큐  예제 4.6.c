#pragma warning(disable:4996) // 비주얼 스튜디오에서 sacnf 오류 무시해주는 정의
// 4월 4일 데이터구조 수업
// 19학번 2학년 이동근
// 4장 큐
// 원형 큐 프로그램 4.6

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_QUEUE_SIZE 100

typedef int Element;

typedef struct CircularQueue
{

	Element data[MAX_QUEUE_SIZE];  // 요소의 배열
	int front;                    // 전단
	int rear;                     // 후단

} Queue;

typedef struct BankCustomer
{
	int id;
	int tArrival;
	int tService;
} Customer;

typedef Customer Element;

void error(char* str[])
{

	printf("%s\n", str);
	exit(1);

}

// 큐의 주요 연산 : 공통
void init_queue(Queue *q) { q -> front = q -> rear = 0; ; }
int is_empty(Queue *q) { return q -> front == q -> rear; }
int is_full(Queue *q) { return q -> front == (q -> rear + 1) % MAX_QUEUE_SIZE; }
int size(Queue *q) { return (q -> rear - q -> front + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE; }

void enqueue( Queue *q, Element val )
{

	if (is_full(q))
		error(" 큐 포화 에러");

	q -> rear = (q -> rear + 1) % MAX_QUEUE_SIZE;
	q -> data[q->rear] = val;

}

Element dequeue(Queue *q)
{

	if (is_empty(q))
		error(" 큐 공백 에러");

	q -> front = (q -> front + 1) % MAX_QUEUE_SIZE;

	return q -> data[q->front];

}

Element peek(Queue *q)
{

	if (is_empty(q))
		error(" 큐 공백 에러");

	return q -> data[(q->front + 1) % MAX_QUEUE_SIZE];

}

int nSimulation;         // 시뮬레이션 시간
double probArrival;      // 단위시간에 도착하는 평균 고객 수
int tMaxService;         // 한 고객에 대한 최대 서비스 시간
int totalWaitTime;       // 전체 대기 시간
int nCustomers;          // 전체 고객의 수
int nServerCustomers;    // 서비스를 받은 전체 고객 수

double rand0t01() { return rand() / (double)RAND_MAX; }

void insert_customer(int arrivalTime)
{

	Customer a;
	a.id = ++nCustomers;
	a.tArrival = arrivalTime;
	a.tService = (int)(tMaxService * rand0t01()) + 1;

	printf("  고객 %d 방문 (서비스 시간 : %d분) \n", a.id, a.tService);
	enqueue(&, a);

}

void read_sim_params()
{

	print("시뮬레이션 할 최대 시간 (예:10) = ");
	scanf("%d", &nSimulation);
	print("단위 시간에 도착하는 고객 수 (예:0.5) = ");
	scanf("%lf", &probArrival);
	print("한 고객에 대한 최대 서비스 시간 (예:5) = ");
	scanf("%d", &tMaxService);
	printf("===============================================================\n");

}

void run_simulation()
{

	Customer a;
	int clock = 0;
	int serviceTime = -1;

	init_queue(&a);
	nCustomers = totalWaitTime = nServerCustomers = 0;

	while (clock < nServerCustomers)
	{
		clock++;
		printf("현재 시각 = %d\n", clock);

		if (rand0t01() < probArrival)
			insert_customer(clock);

		if (serviceTime > 0)
			serviceTime--;

		else
		{
			if (is_empty(&a))
				continue;

			a = dequeue(&a);
			nServerCustomers++;
			totalWaitTime += clock - a.tArrival;

			printf("  고객 %d 서비스 시작 (대기시간 : %d분)\n", a.id, clock - a.tArrival);
			serviceTime = a.tService - 1;
		}

	}



}

void print_result()
{

	printf("========================================================\n");
	printf("  서비스 받은 고객수          = %d\n", nServerCustomers);
	printf("  전체 대기 시간              = %d\n", totalWaitTime);
	printf("  서비스 고객 평균대기시간    = %-5.2f\n", (double)totalWaitTime / nServerCustomers);
	printf("  현재 대기 고객 수           = %d\n", nCustomers - nServerCustomers);

}

void main()
{

	srand((unsigned int)time(NULL));
	read_sim_params();
	run_simulation();
	print_result();

}


/* // 큐 테스트를 위한 코드 : 요소 종류마다 수정
void print_queue(Queue *q, char msg[])
{
	int i, maxi = q -> rear;

	if (q -> front >= q -> rear)
	{
		maxi += MAX_QUEUE_SIZE;
		printf("%s[%2d] = ", msg, size(q));
	}

	for (i = q -> front + 1; i <= maxi; i++)
		printf("%2d ", q -> data[i % MAX_QUEUE_SIZE]);

	printf("\n");
}
*/
