#pragma warning(disable:4996) // 비주얼 스튜디오에서 sacnf 오류 무시해주는 정의
#define _CRT_SECURE_NO_WARNINGS
// 데이터구조 수업 예비군 공결로 강의를 못들어서 따로 했습니다.
// 19학번 2학년 이동근
// 6장 리스트 
// 이중 연결 리스트를 이용한 리스트 프로그램 예제 6.16

#include <stdio.h>
#include <stdlib.h>

typedef int Element;

typedef struct DLinkedNode
{
	Element data;
	struct DLinkedNode* prev;
	struct DLinkedNode* next;

} Node;
Node org;   // 헤드 노드 (헤드 포인토가 아님)

void init_list() { org.next = NULL; }
Node* get_head() { return org.next; }
int is_empty() { return get_head() == NULL; }

Node* get_entry(int pos)
{

	Node* n = &org;
	int i = -1;

	for (i = 1; i < pos; i++, n = n->next)
		if (n == NULL)
			break;

	return n;
}

void replace(int pos, Element e)
{
	Node* node = get_entry(pos);

	if (node != NULL)
		node->data = e;
}

int size()
{
	Node* p;

	int count = 0;

	for (p = get_head(); p != NULL; p = p->next)
		count++;

	return count;
}

Node* find(Element e)
{
	Node* p;

	for (p = get_head(); p != NULL; p = p->next)
		if (p->data == e)
			return p;

	return NULL;
}

void print_list(char* msg)
{
	Node* p;

	printf("%s[%2d] : ", msg, size());

	for (p = get_head(); p != NULL; p = p->next)
		printf("%2d ", p->data);

	printf("\n");
}

void insert_next(Node* before, Node* n)
{
	n->prev = before;
	n->next = before->next;

	if (before->next != NULL)
		before->next->prev = n;

	before->next = n;
}

void insert(int pos, Element e)
{
	Node *new_node, *prev;

	prev = get_entry(pos - 1);

	if (prev != NULL)
	{
		new_node = (Node*)malloc(sizeof(Node));
		new_node->data = e;
		new_node->prev = NULL;
		new_node->next = NULL;

		insert_next(prev, new_node);
	}
}

void remove_curr(Node* n)
{
	if (n->prev != NULL)
		n->prev->next = n->next;

	if (n->next != NULL)
		n->next->prev = n->prev;

}

void delete(int pos)
{
	Node* n = get_entry(pos);

	if (n != NULL)
		remove_curr(n);
}

void clear_list()
{
	while (is_empty() == 0)
		delete(0);
}

void main()
{

	init_list();
	insert(0, 10);
	insert(0, 20);
	insert(1, 30);
	insert(size(), 40);
	insert(2, 50);

	print_list("이중연결리스트로 구현한 List(삽입x5)");
	
	replace(2, 90);
	print_list("이중연결리스트로 구현한 List(교체x1)");

	delete(2);
	delete(size() - 1);
	delete(0);
	print_list("이중연결리스트로 구현한 List(삽입x3)");

	clear_list();
	print_list("이중연결리스트로 구현한 List(정리후)");
}