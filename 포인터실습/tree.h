#pragma once
#pragma warning(disable:4996) // 비주얼 스튜디오에서 sacnf 오류 무시해주는 정의
#define _CRT_SECURE_NO_WARNINGS
// 5월 9일 알고리즘
// 201911079 이동근
// 포인터 트리만들기 실습 tree.h 헤더파일

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