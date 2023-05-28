#define _CRT_SECURE_NO_WARNINGS  // ���־� ��Ʃ������� sacnf ���� �������ִ� ����
// 5�� 28��
// �˰��� ���ػ� ������
// 20191179 �̵���
// ������ ����

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ������ Ʈ�� ��� ����ü
typedef struct Node 
{
    char ch;
    int freq;
    struct Node* left;
    struct Node* right;
} Node;

// ������ Ʈ�� ��� ���� �Լ�
Node* createNode(char ch, int freq) 
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->ch = ch;
    newNode->freq = freq;
    newNode->left = newNode->right = NULL;

    return newNode;
}

// ������ Ʈ�� ��� �켱���� �� �Լ�
int compareNodes(const void* a, const void* b) 
{
    Node* node1 = *(Node**)a;
    Node* node2 = *(Node**)b;

    return (node1->freq - node2->freq);
}

// ������ Ʈ�� ���� �Լ�
Node* buildHuffmanTree(char* text) 
{
    int freq[256] = { 0 };

    // ���ں� �󵵼� ���
    int i = 0;

    while (text[i] != '\0') 
    {
        freq[(int)text[i]]++;
        i++;
    }

    // ������ Ʈ�� ��� ����
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

    // ������ Ʈ�� ����
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

// ������ �ڵ� ���� �Լ�
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

    // ���� ����Ʈ�� Ž��
    code[depth] = '0';
    code[depth + 1] = '\0';
    generateHuffmanCodes(root->left, code, depth + 1, file);

    // ������ ����Ʈ�� Ž��
    code[depth] = '1';
    code[depth + 1] = '\0';
    generateHuffmanCodes(root->right, code, depth + 1, file);
}

int main() 
{
    // 1. �Է� ���� ����
    FILE* inputFile = fopen("input.txt", "r");

    if (inputFile == NULL) 
    {
        printf("�Է� ������ �� �� �����ϴ�.\n");
        return 1;
    }

    // 2. �Է� ���Ͽ��� �ؽ�Ʈ �б�
    fseek(inputFile, 0, SEEK_END);
    long fileSize = ftell(inputFile);
    rewind(inputFile);
    char* text = (char*)malloc((fileSize + 1) * sizeof(char));
    fread(text, sizeof(char), fileSize, inputFile);
    text[fileSize] = '\0';
    fclose(inputFile);

    // 3. ������ Ʈ�� ����
    Node* huffmanTree = buildHuffmanTree(text);

    // 4. ������ �ڵ带 ������ ���� ����
    FILE* statsFile = fopen("stats.txt", "w");

    if (statsFile == NULL) 
    {
        printf("��� ������ �� �� �����ϴ�.\n");
        free(text);
        free(huffmanTree);

        return 1;
    }

    // 5. ������ �ڵ� ���� �� ��� ���Ͽ� ����
    char code[256];
    generateHuffmanCodes(huffmanTree, code, 0, statsFile);
    fclose(statsFile);

    // 6. �Է� ������ ������ �����Ͽ� ��� ���� ����
    FILE* compressedFile = fopen("output.huf", "wb");

    if (compressedFile == NULL) 
    {
        printf("���� ������ �� �� �����ϴ�.\n");
        free(text);
        free(huffmanTree);

        return 1;
    }

  
    fclose(compressedFile);

    // 7. ������ Ʈ���� �̿��Ͽ� ���� �����Ͽ� ���� ���� ����
    FILE* decompressedFile = fopen("output.txt", "w");

    if (decompressedFile == NULL) 
    {
        printf("���� ���� ������ �� �� �����ϴ�.\n");
        free(text);
        free(huffmanTree);

        return 1;
    }

    fclose(decompressedFile);

    free(text);
    free(huffmanTree);

    return 0;
}