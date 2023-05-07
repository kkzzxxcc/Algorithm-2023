#pragma warning(disable:4996) // ���־� ��Ʃ������� sacnf ���� �������ִ� ����

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* arr;  // ���� �迭�� ������ ������
int size;  // ���� �迭�� ũ��

// ũ�Ⱑ n�� ���� �迭 ����
void createArray() {
    printf("���� �迭�� ũ�⸦ �Է��ϼ���: ");
    scanf("%d", &size);
    arr = (int*)malloc(sizeof(int) * size);  // ���� �޸� �Ҵ�
    printf("ũ�Ⱑ %d�� ���� �迭�� �����Ǿ����ϴ�.\n", size);
}

// �迭�� ������ ä��
void fillArray() {
    srand(time(NULL));  // ���� �߻��� �ʱ�ȭ
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100;  // 0~99 ������ ����
    }
    printf("�迭�� ������ ä�������ϴ�.\n");
}

// �迭�� �� ���� ���
void printArray() {
    printf("�迭�� �� ����: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// �迭�� �� ���� �� ���
void sumArray() {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    printf("�迭�� ���ҵ��� ��: %d\n", sum);
}

// ���� �Ҵ� ���� �ݳ�
void releaseMemory() {
    free(arr);  // ���� �޸� ����
    printf("���� �Ҵ� ������ �ݳ��Ǿ����ϴ�.\n");
}

int main() {
    int menu;

    while (1) {
        printf("===========================\n");
        printf("1.ũ�Ⱑ n�� ���� �迭�� ����\n");
        printf("2.�迭�� ������ ä���\n");
        printf("3.�迭�� �� ���Ҹ� ����Ѵ�.\n");
        printf("4.�迭�� �� ���ҵ��� ���� ����Ѵ�.\n");
        printf("5.���� �Ҵ� ������ �ݳ��Ѵ�.\n");
        printf("===========================\n");

        printf("�޴��� �����ϼ���: ");
        scanf("%d", &menu);

        switch (menu) {
        case 1:
            createArray();
            break;
        case 2:
            fillArray();
            break;
        case 3:
            printArray();
            break;
        case 4:
            sumArray();
            break;
        case 5:
            releaseMemory();
            return 0;
        default:
            printf("�߸��� �޴��Դϴ�. �ٽ� �����ϼ���.\n");
            break;
        }
    }

    return 0;
}



