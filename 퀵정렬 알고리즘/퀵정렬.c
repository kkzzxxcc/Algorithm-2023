#pragma warning(disable:4996) // 비주얼 스튜디오에서 sacnf 오류 무시해주는 정의
#define _CRT_SECURE_NO_WARNINGS
// 5월 5일 알고리즘 과제
// 19학번 2학년 이동근
// 퀵정렬 알고리즘 구현하기
// 입력 데이터는 수기로 data.txt 로 저장, 파일을 읽은 후 알고리즘 수행, 결과는 result.txt로 저장

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100000 // 배열의 최대 크기

void quicksort(int arr[], int left, int right);

int main() {
    int arr[MAX_SIZE];
    int n = 0;  
    int i;

    // 파일 열기
    FILE* fp;
    fp = fopen("data.txt", "r");
    if (fp == NULL)
    {
        printf("파일을 여는데 실패했습니다. \n");
        return 1;
    }
    
    // 파일에서 배열 읽어오기
    while (fscanf(fp, "%d", &arr[n]) != EOF) 
    {
        n++;
    }
    fclose(fp);

    // 퀵 정렬 함수 수행
    quicksort(arr, 0, n - 1);

    // 결과 저장
    fp = fopen("result.txt", "w");

    if (fp == NULL) 
    {
        printf("파일을 여는데 실패했습니다.\n");
        return 1;
    }
    for (i = 0; i < n; i++) 
    {
        fprintf(fp, "%d\n", arr[i]);
    }
    fclose(fp);

    return 0;
}

// 퀵정렬 함수
void quicksort(int arr[], int left, int right) 
{
    if (left < right) 
    {
        int pivot = arr[left];  // 첫번째 원소를 pivot으로 선택
        int i = left + 1;       // pivot보다 작은 값들을 왼쪽에 저장하기 위한 배열의 인덱스
        int j = right;          // pivot보다 큰 값들을 오른쪽애 저장하기 위한 배열의 인덱스
        int temp;

        while (i <= j) 
        {
            while (arr[i] < pivot) // pivot보다 작은 값을 찾을 때까지 i 증가
            {  
                i++;
            }
            while (arr[j] > pivot) // pivot보다 큰 값을 찾을 때까지 j 감소
            {  
                j--;
            }
            if (i <= j)          // i와 j가 교차하지 않았으면 i와 j의 위치를 바꿈 
            {            
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                i++;
                j--;
            }
        }

        // pivot값을 i-1 위치에 넣어줌
        arr[left] = arr[i - 1];
        arr[i - 1] = pivot;

        // pivot을 기준으로 왼쪽 부분배열과 오른쪽 부분배열에 대해 재귀호출
        quicksort(arr, left, i - 2);
        quicksort(arr, i, right);
    }
}

