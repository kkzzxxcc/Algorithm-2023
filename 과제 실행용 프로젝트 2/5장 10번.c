#pragma warning(disable:4996) // ���־� ��Ʃ������� sacnf ���� �������ִ� ����

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char data;
    struct Node* next;
};

struct Stack {
    struct Node* top;
};

struct Stack* createStack() {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = NULL;
    return stack;
}

void push(struct Stack* stack, char data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = stack->top;
    stack->top = node;
}

char pop(struct Stack* stack) {
    if (stack->top == NULL) {
        return '\0';
    }
    char data = stack->top->data;
    struct Node* temp = stack->top;
    stack->top = stack->top->next;
    free(temp);
    return data;
}

char peek(struct Stack* stack) {
    if (stack->top == NULL) {
        return '\0';
    }
    return stack->top->data;
}

int isPalindrome(char* str) {
    int length = strlen(str);
    struct Stack* stack = createStack();
    int i;
    for (i = 0; i < length / 2; i++) {
        push(stack, str[i]);
    }
    if (length % 2 != 0) {
        i++;
    }
    while (str[i] != '\0') {
        if (peek(stack) == str[i]) {
            pop(stack);
        }
        else {
            return 0;
        }
        i++;
    }
    return 1;
}

int main() {
    char str[100];
    printf("���ڿ��� �Է��ϼ��� : ");
    scanf("%s", str);
    if (isPalindrome(str)) {
        printf("%s ��(��) ȸ���Դϴ�.\n", str);
    }
    else {
        printf("%s ��(��)ȸ���� �ƴմϴ�.\n", str);
    }
    return 0;
}
