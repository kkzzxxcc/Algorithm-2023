#pragma warning(disable:4996) // 비주얼 스튜디오에서 sacnf 오류 무시해주는 정의
#define _CRT_SECURE_NO_WARNINGS
// 5월 9일 알고리즘
// 201911079 이동근
// 포인터 트리만들기 실습 tree파일

#include <stdio.h>
#include <stdlib.h>

#include "tree.h"


Node* root;


Node* createNode(int val)
{
	// 1. sizeof(Node) malloc
	Node* pNode = (Node*)malloc(sizeof(Node));

	// 2. 초기화 n->value =val, left, right(NULL)
	pNode->value = val;
	pNode->left = NULL;
	pNode->right = NULL;

	// 3. 만든 Node 객체(변수) 포인터 변환
	return pNode;
}


Node * connectChild(Node* parent, Node* left, Node* right)
{
	if (parent == NULL)
		return NULL;

	parent->left = left;
	parent->right = right;

	return parent;
}


Node* makeTree()
{
	Node* pRoot = NULL;
	Node* pLeft = NULL;
	Node* pRight = NULL;


	pRoot = createNode(100);
	pLeft = createNode(200);
	pRight = createNode(300);


	connectChild(pRoot, pLeft, pRight);
	connectChild(pRight, createNode(400), createNode(500));


	return pRoot;
}


void printTree(Node* root)
{
	// 종료조건
	if (root == NULL)
		return;

	printf("Node : %d", root->value);

	printTree(root->left);
	printTree(root->right);

}


Node* findNode(Node* root, int value) 
{
	if (root == NULL || root->value == value) 
		return root;
	

	Node* leftResult = findNode(root->left, value);

	if (leftResult != NULL) 
		return leftResult;
	

	Node* rightResult = findNode(root->right, value);

	if (rightResult != NULL) 
		return rightResult;
	

	return NULL;
}

Node* insertLeftNode(Node* where, Node* p_node) 
{
	if (where == NULL) 
		return NULL;
	
	where->left = p_node;

	return where;
}

Node* insertRightNode(Node* where, Node* p_node) 
{
	if (where == NULL) 
		return NULL;
	

	where->right = p_node;

	return where;
}