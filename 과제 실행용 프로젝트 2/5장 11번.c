#pragma warning(disable:4996) // ���־� ��Ʃ������� sacnf ���� �������ִ� ����

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Queue {
    struct Node* front;
    struct Node* rear;
};

// ť �ʱ�ȭ �Լ�
void initQueue(struct Queue* q) {
    q->front = q->rear = NULL;
}

// ť�� ����ִ��� Ȯ���ϴ� �Լ�
int isQueueEmpty(struct Queue* q) {
    return q->front == NULL;
}

// ť�� ���ο� ��带 �����ϴ� �Լ�
void enqueue(struct Queue* q, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (isQueueEmpty(q)) {
        q->front = q->rear = newNode;
    }
    else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

// ť�� ��� ��带 ����ϴ� �Լ�
void printQueue(struct Queue* q) {
    struct Node* curr = q->front;

    while (curr != NULL) {
        printf("%d", curr->data);
        curr = curr->next;

        if (curr != NULL) {
            printf(" -> ");
        }
    }

    printf(" -> NULL\n");
}

int main() {
    struct Queue q;
    initQueue(&q);
    int input;

    while (1) {
        printf("���� ������ �Է��ϼ���(���� -1) : ");
        scanf("%d", &input);

        if (input == -1) {
            break;
        }

        enqueue(&q, input);
    }

    printQueue(&q);

    return 0;
}
