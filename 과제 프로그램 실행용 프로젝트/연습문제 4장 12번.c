#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 100

int main() {
    char str[MAX_LEN], ch;
    int i, len, is_palindrome = 1; // is_palindrome 변수를 1로 초기화

    printf("문자열을 입력하세요: ");
    fgets(str, MAX_LEN, stdin);
    len = strlen(str) - 1; // fgets로 입력받은 문자열의 마지막에는 개행 문자('\n')이 포함되므로 길이에서 1을 빼줌

    // 문자열에서 공백과 특수문자를 제거하고 대문자를 소문자로 변환
    for (i = 0; i < len; i++) {
        ch = str[i];
        if (isalpha(ch)) {
            str[i] = tolower(ch);
        }
        else {
            memmove(&str[i], &str[i + 1], len - i);
            len--;
            i--;
        }
    }

    // 덱을 이용하여 회문인지 아닌지 판별
    int front = 0, rear = len - 1; // front와 rear 변수를 초기화
    while (front < rear) {
        if (str[front] != str[rear]) {
            is_palindrome = 0; // 회문이 아니면 is_palindrome을 0으로 변경
            break;
        }
        front++;
        rear--;
    }

    // 회문인지 아닌지 출력
    if (is_palindrome) {
        printf("입력한 문자열은 회문입니다.\n");
    }
    else {
        printf("입력한 문자열은 회문이 아닙니다.\n");
    }

    return 0;
}
