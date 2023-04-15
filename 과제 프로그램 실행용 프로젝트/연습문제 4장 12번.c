#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 100

int main() {
    char str[MAX_LEN], ch;
    int i, len, is_palindrome = 1; // is_palindrome ������ 1�� �ʱ�ȭ

    printf("���ڿ��� �Է��ϼ���: ");
    fgets(str, MAX_LEN, stdin);
    len = strlen(str) - 1; // fgets�� �Է¹��� ���ڿ��� ���������� ���� ����('\n')�� ���ԵǹǷ� ���̿��� 1�� ����

    // ���ڿ����� ����� Ư�����ڸ� �����ϰ� �빮�ڸ� �ҹ��ڷ� ��ȯ
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

    // ���� �̿��Ͽ� ȸ������ �ƴ��� �Ǻ�
    int front = 0, rear = len - 1; // front�� rear ������ �ʱ�ȭ
    while (front < rear) {
        if (str[front] != str[rear]) {
            is_palindrome = 0; // ȸ���� �ƴϸ� is_palindrome�� 0���� ����
            break;
        }
        front++;
        rear--;
    }

    // ȸ������ �ƴ��� ���
    if (is_palindrome) {
        printf("�Է��� ���ڿ��� ȸ���Դϴ�.\n");
    }
    else {
        printf("�Է��� ���ڿ��� ȸ���� �ƴմϴ�.\n");
    }

    return 0;
}
