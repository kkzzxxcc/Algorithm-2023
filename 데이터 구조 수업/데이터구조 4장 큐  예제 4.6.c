#pragma warning(disable:4996) // ���־� ��Ʃ������� sacnf ���� �������ִ� ����
// 4�� 4�� �����ͱ��� ����
// 19�й� 2�г� �̵���
// 4�� ť
// ���� ť ���α׷� 4.6

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_QUEUE_SIZE 100

typedef int Element;

typedef struct CircularQueue
{

	Element data[MAX_QUEUE_SIZE];  // ����� �迭
	int front;                    // ����
	int rear;                     // �Ĵ�

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

// ť�� �ֿ� ���� : ����
void init_queue(Queue *q) { q -> front = q -> rear = 0; ; }
int is_empty(Queue *q) { return q -> front == q -> rear; }
int is_full(Queue *q) { return q -> front == (q -> rear + 1) % MAX_QUEUE_SIZE; }
int size(Queue *q) { return (q -> rear - q -> front + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE; }

void enqueue( Queue *q, Element val )
{

	if (is_full(q))
		error(" ť ��ȭ ����");

	q -> rear = (q -> rear + 1) % MAX_QUEUE_SIZE;
	q -> data[q->rear] = val;

}

Element dequeue(Queue *q)
{

	if (is_empty(q))
		error(" ť ���� ����");

	q -> front = (q -> front + 1) % MAX_QUEUE_SIZE;

	return q -> data[q->front];

}

Element peek(Queue *q)
{

	if (is_empty(q))
		error(" ť ���� ����");

	return q -> data[(q->front + 1) % MAX_QUEUE_SIZE];

}

int nSimulation;         // �ùķ��̼� �ð�
double probArrival;      // �����ð��� �����ϴ� ��� �� ��
int tMaxService;         // �� ���� ���� �ִ� ���� �ð�
int totalWaitTime;       // ��ü ��� �ð�
int nCustomers;          // ��ü ���� ��
int nServerCustomers;    // ���񽺸� ���� ��ü �� ��

double rand0t01() { return rand() / (double)RAND_MAX; }

void insert_customer(int arrivalTime)
{

	Customer a;
	a.id = ++nCustomers;
	a.tArrival = arrivalTime;
	a.tService = (int)(tMaxService * rand0t01()) + 1;

	printf("  �� %d �湮 (���� �ð� : %d��) \n", a.id, a.tService);
	enqueue(&, a);

}

void read_sim_params()
{

	print("�ùķ��̼� �� �ִ� �ð� (��:10) = ");
	scanf("%d", &nSimulation);
	print("���� �ð��� �����ϴ� �� �� (��:0.5) = ");
	scanf("%lf", &probArrival);
	print("�� ���� ���� �ִ� ���� �ð� (��:5) = ");
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
		printf("���� �ð� = %d\n", clock);

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

			printf("  �� %d ���� ���� (���ð� : %d��)\n", a.id, clock - a.tArrival);
			serviceTime = a.tService - 1;
		}

	}



}

void print_result()
{

	printf("========================================================\n");
	printf("  ���� ���� ����          = %d\n", nServerCustomers);
	printf("  ��ü ��� �ð�              = %d\n", totalWaitTime);
	printf("  ���� �� ��մ��ð�    = %-5.2f\n", (double)totalWaitTime / nServerCustomers);
	printf("  ���� ��� �� ��           = %d\n", nCustomers - nServerCustomers);

}

void main()
{

	srand((unsigned int)time(NULL));
	read_sim_params();
	run_simulation();
	print_result();

}


/* // ť �׽�Ʈ�� ���� �ڵ� : ��� �������� ����
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
