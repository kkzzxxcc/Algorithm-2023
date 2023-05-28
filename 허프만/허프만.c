#define _CRT_SECURE_NO_WARNINGS  // 비주얼 스튜디오에서 sacnf 오류 무시해주는 정의
// 5월 28일
// 알고리즘 송해상 교수님
// 20191179 이동근
// 허프만 압축

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 허프만 트리 노드 구조체
typedef struct Node 
{
    char ch;
    int freq;
    struct Node* left;
    struct Node* right;
} Node;

// 허프만 트리 노드 생성 함수
Node* createNode(char ch, int freq) 
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->ch = ch;
    newNode->freq = freq;
    newNode->left = newNode->right = NULL;

    return newNode;
}

// 허프만 트리 노드 우선순위 비교 함수
int compareNodes(const void* a, const void* b) 
{
    Node* node1 = *(Node**)a;
    Node* node2 = *(Node**)b;

    return (node1->freq - node2->freq);
}

// 허프만 트리 구성 함수
Node* buildHuffmanTree(char* text) 
{
    int freq[256] = { 0 };

    // 문자별 빈도수 계산
    int i = 0;

    while (text[i] != '\0') 
    {
        freq[(int)text[i]]++;
        i++;
    }

    // 허프만 트리 노드 생성
    Node** nodes = (Node**)malloc(256 * sizeof(Node*));
    int nodeCount = 0;

    for (int i = 0; i < 256; i++) 
    {
        if (freq[i] > 0) 
        {
            nodes[nodeCount] = createNode((char)i, freq[i]);
            nodeCount++;
        }
    }

    // 허프만 트리 구성
    while (nodeCount > 1) 
    {
        qsort(nodes, nodeCount, sizeof(Node*), compareNodes);
        Node* left = nodes[0];
        Node* right = nodes[1];
        Node* parent = createNode('\0', left->freq + right->freq);

        parent->left = left;
        parent->right = right;
        nodes[0] = parent;

        for (int i = 1; i < nodeCount - 1; i++) 
        {
            nodes[i] = nodes[i + 1];
        }

        nodeCount--;
    }

    Node* root = nodes[0];
    free(nodes);

    return root;
}

// 허프만 코드 생성 함수
void generateHuffmanCodes(Node* root, char* code, int depth, FILE* file) 
{
    if (root == NULL) 
    {
        return;
    }

    if (root->left == NULL && root->right == NULL) 
    {
        fprintf(file, "%c\t%s\n", root->ch, code);

        return;
    }

    // 왼쪽 서브트리 탐색
    code[depth] = '0';
    code[depth + 1] = '\0';
    generateHuffmanCodes(root->left, code, depth + 1, file);

    // 오른쪽 서브트리 탐색
    code[depth] = '1';
    code[depth + 1] = '\0';
    generateHuffmanCodes(root->right, code, depth + 1, file);
}

int main() 
{
    // 1. 입력 파일 열기
    FILE* inputFile = fopen("input.txt", "r");

    if (inputFile == NULL) 
    {
        printf("입력 파일을 열 수 없습니다.\n");
        return 1;
    }

    // 2. 입력 파일에서 텍스트 읽기
    fseek(inputFile, 0, SEEK_END);
    long fileSize = ftell(inputFile);
    rewind(inputFile);
    char* text = (char*)malloc((fileSize + 1) * sizeof(char));
    fread(text, sizeof(char), fileSize, inputFile);
    text[fileSize] = '\0';
    fclose(inputFile);

    // 3. 허프만 트리 구성
    Node* huffmanTree = buildHuffmanTree(text);

    // 4. 허프만 코드를 저장할 파일 열기
    FILE* statsFile = fopen("stats.txt", "w");

    if (statsFile == NULL) 
    {
        printf("통계 파일을 열 수 없습니다.\n");
        free(text);
        free(huffmanTree);

        return 1;
    }

    // 5. 허프만 코드 생성 및 통계 파일에 저장
    char code[256];
    generateHuffmanCodes(huffmanTree, code, 0, statsFile);
    fclose(statsFile);

    // 6. 입력 파일을 허프만 압축하여 출력 파일 생성
    FILE* compressedFile = fopen("output.huf", "wb");

    if (compressedFile == NULL) 
    {
        printf("압축 파일을 열 수 없습니다.\n");
        free(text);
        free(huffmanTree);

        return 1;
    }

  
    fclose(compressedFile);

    // 7. 허프만 트리를 이용하여 압축 해제하여 원본 파일 생성
    FILE* decompressedFile = fopen("output.txt", "w");

    if (decompressedFile == NULL) 
    {
        printf("압축 해제 파일을 열 수 없습니다.\n");
        free(text);
        free(huffmanTree);

        return 1;
    }

    fclose(decompressedFile);

    free(text);
    free(huffmanTree);

    return 0;
}