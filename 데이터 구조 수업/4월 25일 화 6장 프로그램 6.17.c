#pragma warning(disable:4996) // ���־� ��Ʃ������� sacnf ���� �������ִ� ����
#define _CRT_SECURE_NO_WARNINGS
// 4�� 25�� �����ͱ��� ����
// 19�й� 2�г� �̵���
// 6�� ���Ḯ��Ʈ
// ���� ����Ʈ�� ���� : ���� ������

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

Node* head;                                 // ��� �����͸� �����.

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
	char search_str[MAX_CHAR_PER_LINE]; // �˻��� �ܾ ������ ���ڿ� ����

	init_list();

	do
	{
		printf("[�޴� ����] i - �Է�, d - ����, r - ����,f - �˻�,  p - ���, l - ���� �б�, s - ����, q - ���� => ");
		command = getchar();

		switch (command)
		{

		case 'i':

			printf("  �Է��� ��ȣ :  ");
			scanf("%d", &pos);
			printf("  �Է��� ���� :  ");
			my_fflush();                      // �Է� ����(Ű����)���� '\n'�� ���
			fgets(line.str, MAX_CHAR_PER_LINE, stdin);
			insert(pos, line);

			break;

		case 'd':

			printf("  ������ ��ȣ :  ");
			scanf("%d", &pos);
			delete(pos);

			break;

		case 'r':

			printf("  ������ ��ȣ :  ");
			scanf("%d", &pos);
			printf("  ������ ���� :  ");
			my_fflush();
			fgets(line.str, MAX_CHAR_PER_LINE, stdin);
			replace(pos, line);

			break;

		case 'f':

			printf("  �˻��� �ܾ� : ");
			my_fflush();
			fgets(search_str, MAX_CHAR_PER_LINE, stdin);
			search_str[strcspn(search_str, "\n")] = 0; // fgets�� �Է¹��� ���ڿ� ���� �ִ� '\n'�� ����

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