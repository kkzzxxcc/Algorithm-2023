#pragma once
#pragma warning(disable:4996) // ���־� ��Ʃ������� sacnf ���� �������ִ� ����
#define _CRT_SECURE_NO_WARNINGS
// 5�� 9�� �˰���
// 201911079 �̵���
// ������ Ʈ������� �ǽ� tree.h �������

typedef int _Node;

typedef struct _Node
{
	int value;
	struct _Node *left;
	struct _Node *right;
} Node;

extern Node* connectChild(Node* parent, Node* left, Node* right);
extern Node* createNode(int val);

Node* makeTree();
void printTree(Node* root);
Node* findNode(Node* root, int value);
Node* insertLeftNode(Node* where, Node* new_node);
Node* insertRightNode(Node* where, Node* new_node);