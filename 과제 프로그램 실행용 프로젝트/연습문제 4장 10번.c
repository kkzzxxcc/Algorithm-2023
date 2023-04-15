#pragma warning(disable:4996) // 비주얼 스튜디오에서 sacnf 오류 무시해주는 정의
// 4장 연습문제 10번
// 19학번 2학년 이동근 201911079

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int data[MAX_SIZE];
    int top;
} Stack;

void push(Stack* stack, int item) {
    if (stack->top == MAX_SIZE - 1) {
        printf("Error: Stack is full.\n");
        exit(EXIT_FAILURE);
    }
    stack->top++;
    stack->data[stack->top] = item;
}

int pop(Stack* stack) {
    if (stack->top == -1) {
        printf("Error: Stack is empty.\n");
        exit(EXIT_FAILURE);
    }
    int item = stack->data[stack->top];
    stack->top--;
    return item;
}

int empty(Stack* stack) {
    return stack->top == -1;
}

typedef struct {
    Stack stack1;
    Stack stack2;
} Queue;

void enqueue(Queue* queue, int item) {
    push(&(queue->stack1), item);
}

int dequeue(Queue* queue) {
    if (empty(&(queue->stack2))) {
        while (!empty(&(queue->stack1))) {
            int item = pop(&(queue->stack1));
            push(&(queue->stack2), item);
        }
    }
    return pop(&(queue->stack2));
}

int main() {
    Queue queue = { {0}, {0} };
    enqueue(&queue, 1);
    enqueue(&queue, 2);
    enqueue(&queue, 3);
    printf("%d\n", dequeue(&queue));
    enqueue(&queue, 4);
    printf("%d\n", dequeue(&queue));
    printf("%d\n", dequeue(&queue));
    printf("%d\n", dequeue(&queue));
    return 0;
}
