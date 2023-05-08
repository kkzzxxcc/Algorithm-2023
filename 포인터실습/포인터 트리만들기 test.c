#pragma warning(disable:4996) // 비주얼 스튜디오에서 sacnf 오류 무시해주는 정의
#define _CRT_SECURE_NO_WARNINGS
// 5월 9일 알고리즘
// 201911079 이동근
// 포인터 트리만들기 실습 테스트파일

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
        printf("값이 %d인 노드를 찾았습니다. \n", searchValue);
    else
        printf("값이 %d인 노드를 찾지 못하였습니다. \n", searchValue);

    Node* pNode = createNode(500);

    Node* insertedNode = insertRightNode(foundNode, pNode);

    if (insertedNode != NULL)
        printf("값이 %d인 노드가 값이 %d인 노드 오른쪽에 삽입되었습니다. \n", pNode->value, foundNode->value);
    else
        printf("노드 삽입을 실패하였습니다. \n");

    printf("Preorder 순회 삽입 후 : ");
    printTree(root);
    printf("\n");

	return 0;
}
