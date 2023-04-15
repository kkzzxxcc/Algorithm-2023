#pragma warning(disable:4996) // 비주얼 스튜디오에서 sacnf 오류 무시해주는 정의
#define _CRT_SECURE_NO_WARNINGS
// 4월 11일 데이터구조 수업
// 19학번 2학년 이동근
// 5장 포인터와 연결리스트
// 연결된 스택 테스트 프로그램 예제 5.8

#include <stdio.h>
#include <stdlib.h>

typedef int Element;
typedef struct LinkedNode
{
	Element data;                            // 데이터 영역
	struct LickedNode* link;                 // 다음 노드를 가리키는 포인터 변수
} Node;

Node* front = NULL;                           // 연결 리스트의 헤드 포인터
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

	Node* p = (Node*)malloc(sizeof(Node));   // 노드 동적 할당
	p->data = e;                             // 데이터 필드 초기화
	p->link = NULL;                          // 링크 필드 초기화

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
		error(" 큐 공백 에러");

	p = front;
	front = front->link;

	if (front == NULL)
		rear = NULL;

	e = p->data;                  // p의 항목 복사
	free(p);                      // p를 동적 해제
	
	return e;                     // 복사된 항목을 반환

}

Element peek()
{

	if (is_empty())
		error("스택 공백 에러");

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
		printf("%2d ", p->data);

	printf("\n");

}

void main()
{

	int i;

	init_queue();

	for (i = 1; i < 10; i++)
		enqueue(i);

	print_queue("연결된 큐 enqueue 9회");
	printf("\tdequeue() --> %d\n", dequeue());
	printf("\tdequeue() --> %d\n", dequeue());
	printf("\tdequeue() --> %d\n", dequeue());
	print_queue("연결된 큐 dequeue  3회");

	destroy_queue();

	print_queue("연결된 큐 destroy ");

}