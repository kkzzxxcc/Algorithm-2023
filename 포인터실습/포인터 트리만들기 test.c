#pragma warning(disable:4996) // ���־� ��Ʃ������� sacnf ���� �������ִ� ����
#define _CRT_SECURE_NO_WARNINGS
// 5�� 9�� �˰���
// 201911079 �̵���
// ������ Ʈ������� �ǽ� �׽�Ʈ����

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#include "tree.h"


void testTree()
{

	printf("Hello World \n");

    Node* root = makeTree();

    printf("Preorder : ");
    printTree(root);
    printf("\n");

    int searchValue = 400;

    Node* foundNode = findNode(root, searchValue);

    if (foundNode != NULL)
        printf("���� %d�� ��带 ã�ҽ��ϴ�. \n", searchValue);
    else
        printf("���� %d�� ��带 ã�� ���Ͽ����ϴ�. \n", searchValue);

    Node* pNode = createNode(500);

    Node* insertedNode = insertRightNode(foundNode, pNode);

    if (insertedNode != NULL)
        printf("���� %d�� ��尡 ���� %d�� ��� �����ʿ� ���ԵǾ����ϴ�. \n", pNode->value, foundNode->value);
    else
        printf("��� ������ �����Ͽ����ϴ�. \n");

    printf("Preorder ��ȸ ���� �� : ");
    printTree(root);
    printf("\n");

	return 0;
}
