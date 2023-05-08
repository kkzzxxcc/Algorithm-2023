#pragma warning(disable:4996) // 비주얼 스튜디오에서 sacnf 오류 무시해주는 정의
#define _CRT_SECURE_NO_WARNINGS
// 4월 25일 데이터구조 수업
// 19학번 2학년 이동근
// 6장 연결리스트
// 연결 리스트의 응용 : 라인 편집기

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHAR_PER_LINE 1000

typedef struct Line
{
	char str[MAX_CHAR_PER_LINE];
} Line;

typedef Line Element;

typedef struct LinkedNode
{
	Element data;
	struct LinkedNode* link;
} Node;

Node* head;                                 // 헤더 포인터를 사용함.

void init_list()
{
	head = NULL;
}

int is_empty()
{
	return head == NULL;
}

Node* get_entry(int pos)
{
	Node* p = head;
	int i;

	for (i = 0; i < pos; i++, p = p->link)
		if (p == NULL)
			return NULL;

	return p;
}

int size()
{
	Node* p;
	int count = 0;

	for (p = head; p != NULL; p = p->link)
		count++;

	return count;
}

void replace(int pos, Element e)
{
	Node* node = get_entry(pos);

	if (node != NULL)
		node->data = e;
}

void insert_next(Node* before, Node* node)
{
	if (node != NULL)
	{
		node->link = before->link;
		before->link = node;
	}
}

void insert(int pos, Element e)
{
	Node* new_node, * prev;

	new_node = (Node*)malloc(sizeof(Node));

	new_node->data = e;
	new_node->link = NULL;

	if (pos == 0)
	{
		new_node->link = head;
		head = new_node;
	}

	else
	{
		prev = get_entry(pos - 1);

		if (prev != NULL)
			insert_next(prev, new_node);

		else
			free(new_node);
	}

}

Node* remove_next(Node* before)
{
	Node* removed = before->link;

	if (removed != NULL)
		before->link = removed->link;

	return removed;
}

void delete(int pos)
{
	Node* prev, * removed;

	if (pos == 0 && is_empty() == 0)
	{
		removed = head;
		head = head->link;

		free(removed);
	}

	else
	{
		prev = get_entry(pos - 1);

		if (prev != NULL)
		{
			removed = remove_next(prev);
			free(removed);
		}
	}
}

void clear_list()
{
	while (is_empty() == 0)
		delete(0);
}

void display(FILE* fp)
{
	int i = 0;
	Node* p;

	for (p = head; p != NULL; p = p->link, i++)
	{
		fprintf(stderr, "%3d: ", i);
		fprintf(fp, "%s", p->data.str);
	}
}

void my_fflush()
{
	while (getchar() != '\n');
}

void main()
{
	char command;
	int pos;
	Line line;
	FILE* fp;
	char search_str[MAX_CHAR_PER_LINE]; // 검색할 단어를 저장할 문자열 변수

	init_list();

	do
	{
		printf("[메뉴 선택] i - 입력, d - 삭제, r - 변경,f - 검색,  p - 출력, l - 파일 읽기, s - 저장, q - 종료 => ");
		command = getchar();

		switch (command)
		{

		case 'i':

			printf("  입력행 번호 :  ");
			scanf("%d", &pos);
			printf("  입력행 내용 :  ");
			my_fflush();                      // 입력 버퍼(키보드)에서 '\n'을 비움
			fgets(line.str, MAX_CHAR_PER_LINE, stdin);
			insert(pos, line);

			break;

		case 'd':

			printf("  삭제행 번호 :  ");
			scanf("%d", &pos);
			delete(pos);

			break;

		case 'r':

			printf("  변경행 번호 :  ");
			scanf("%d", &pos);
			printf("  변경행 내용 :  ");
			my_fflush();
			fgets(line.str, MAX_CHAR_PER_LINE, stdin);
			replace(pos, line);

			break;

		case 'f':

			printf("  검색할 단어 : ");
			my_fflush();
			fgets(search_str, MAX_CHAR_PER_LINE, stdin);
			search_str[strcspn(search_str, "\n")] = 0; // fgets로 입력받은 문자열 끝에 있는 '\n'을 제거

			Node* p;
			int i = 0;
			for (p = head; p != NULL; p = p->link, i++) 
			{
				if (strstr(p->data.str, search_str) != NULL) 
				{
					fprintf(stderr, "%3d: %s", i, p->data.str);
				}
			}
			break;

		case 'l':

			fp = fopen("Test.txt", "r");

			if (fp != NULL)
			{
				while (fgets(line.str, MAX_CHAR_PER_LINE, fp))
				insert(size(), line);

				fclose(fp);
			}

			break;

		case 's':

			fp = fopen("Test.txt", "w");

			if (fp != NULL)
			{
				display(fp);
				fclose(fp);
			}

		case 'p': 
			display(stdout);

		}

		my_fflush();

	}

	while (command != 'q');

}