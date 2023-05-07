#pragma warning(disable:4996) // 비주얼 스튜디오에서 sacnf 오류 무시해주는 정의

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#define INFN (99127312386)

typedef struct _Nodeinfo
{
	int id;
	char* name[20];

} Node;

// const char* nodeName[4] = { "n0", "n1", "n2", "n3" }; // Node 집합

const Node nodeSet[4] = { {2332, "n0"}, {9933, "n1"}, {332, "n2"}, {234, "n3"} };

// const Node nodeSet[4]; // Node 집합

// 가중치 그래프 2차원 배열 표기
int G[4][4] = {
	{0, 3, INFN, INFN},
	{INFN, 0, 4, INFN},
	{INFN, INFN, 0, 5},
	{INFN, INFN, 2, 0},
};

typedef struct _Bnode
{
	int id;
	Bnode* left;
	Bnode* right;

} Bnode;

/* void initGraph()
{
	Node n1;
	srtcpy(n1.name, "n1");
	nodeSet[0] = n1;
}
*/

// 반환 초기화된 이진 트리의 루트노드
Bnode * initTree()
{
	Bnode* b0 = (Bnode*)maclloc(sizeof(Bnode));

	Bnode* b1 = (Bnode*)maclloc(sizeof(Bnode));
	Bnode* b2 = (Bnode*)maclloc(sizeof(Bnode));
	Bnode* b3 = (Bnode*)maclloc(sizeof(Bnode));
	Bnode* b4 = (Bnode*)maclloc(sizeof(Bnode));

	b0->left  = b1;
	b1->right = b2;
	b2->left  = b3;
	b2->right = b4;

	// ,......

	return b0;

}