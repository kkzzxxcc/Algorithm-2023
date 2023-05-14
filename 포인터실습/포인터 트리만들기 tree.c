#pragma warning(disable:4996) // ���־� ��Ʃ������� sacnf ���� �������ִ� ����
#define _CRT_SECURE_NO_WARNINGS
// 5�� 9�� �˰���
// 201911079 �̵���
// ������ Ʈ������� �ǽ� tree����

#include <stdio.h>
#include <stdlib.h>

#include "tree.h"


Node* root;


Node* createNode(int val)
{
	// 1. sizeof(Node) malloc
	Node* pNode = (Node*)malloc(sizeof(Node));

	// 2. �ʱ�ȭ n->value =val, left, right(NULL)
	pNode->value = val;
	pNode->left = NULL;
	pNode->right = NULL;

	// 3. ���� Node ��ü(����) ������ ��ȯ
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
	// ��������
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