#pragma warning(disable:4996) // 비주얼 스튜디오에서 sacnf 오류 무시해주는 정의

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

// 큐 초기화 함수
void initQueue(struct Queue* q) {
    q->front = q->rear = NULL;
}

// 큐가 비어있는지 확인하는 함수
int isQueueEmpty(struct Queue* q) {
    return q->front == NULL;
}

// 큐에 새로운 노드를 삽입하는 함수
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

// 큐의 모든 노드를 출력하는 함수
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
        printf("양의 정수를 입력하세요(종료 -1) : ");
        scanf("%d", &input);

        if (input == -1) {
            break;
        }

        enqueue(&q, input);
    }

    printQueue(&q);

    return 0;
}
