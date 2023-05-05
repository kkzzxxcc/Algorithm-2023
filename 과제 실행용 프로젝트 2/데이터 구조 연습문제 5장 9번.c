#pragma warning(disable:4996) // 비주얼 스튜디오에서 sacnf 오류 무시해주는 정의

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* arr;  // 동적 배열을 저장할 포인터
int size;  // 동적 배열의 크기

// 크기가 n인 동적 배열 생성
void createArray() {
    printf("동적 배열의 크기를 입력하세요: ");
    scanf("%d", &size);
    arr = (int*)malloc(sizeof(int) * size);  // 동적 메모리 할당
    printf("크기가 %d인 동적 배열이 생성되었습니다.\n", size);
}

// 배열을 난수로 채움
void fillArray() {
    srand(time(NULL));  // 난수 발생기 초기화
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100;  // 0~99 범위의 난수
    }
    printf("배열이 난수로 채워졌습니다.\n");
}

// 배열의 각 원소 출력
void printArray() {
    printf("배열의 각 원소: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// 배열의 각 원소 합 출력
void sumArray() {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    printf("배열의 원소들의 합: %d\n", sum);
}

// 동적 할당 공간 반납
void releaseMemory() {
    free(arr);  // 동적 메모리 해제
    printf("동적 할당 공간이 반납되었습니다.\n");
}

int main() {
    int menu;

    while (1) {
        printf("===========================\n");
        printf("1.크기가 n인 동적 배열을 생성\n");
        printf("2.배열을 난수로 채운다\n");
        printf("3.배열의 각 원소를 출력한다.\n");
        printf("4.배열의 각 원소들의 합을 출력한다.\n");
        printf("5.동적 할당 공간을 반납한다.\n");
        printf("===========================\n");

        printf("메뉴를 선택하세요: ");
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
            printf("잘못된 메뉴입니다. 다시 선택하세요.\n");
            break;
        }
    }

    return 0;
}



