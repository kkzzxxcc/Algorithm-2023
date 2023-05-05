#pragma warning(disable:4996) // 비주얼 스튜디오에서 sacnf 오류 무시해주는 정의

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
    printf("문자열을 입력하세요 : ");
    scanf("%s", str);
    if (isPalindrome(str)) {
        printf("%s 은(는) 회문입니다.\n", str);
    }
    else {
        printf("%s 은(는)회문이 아닙니다.\n", str);
    }
    return 0;
}
