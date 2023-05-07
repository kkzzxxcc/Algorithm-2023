#pragma warning(disable:4996) // 비주얼 스튜디오에서 sacnf 오류 무시해주는 정의
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 8

int main()
{
	FILE *fp = NULL;
    fp = fopen("data.txt", "r");
    int result;
    int num;
    if (fp == NULL)
    {
        printf("파일을 여는데 실패했습니다. \n");
        return 1;
    }
    else
	{
		printf("파일을 여는데 성공했습니다. \n");
	} 
    int arr[MAX];
    int i = 0;
    // 파일에서 배열 읽어오기  
    while (fscanf(fp, "%d", &arr[i]) != EOF) 
    {
    	i++;
	}
    fclose(fp);
	printf("몇 번째로 작은 값을 원하십니까? ");
	scanf("%d", &num);
    // 퀵 정렬 함수 수행 
    result = Selection(arr, 0, MAX-1, num);

    // 결과 저장 
    fp = fopen("result.txt", "w");

    if (fp == NULL) 
    {
        printf("파일을 여는데 실패했습니다.\n");
        return 1;
    }
    
    fprintf(fp, "%d ", result);
    printf("%d번재로 작은 값은 %d입니다", num, result);

    return 0;
	
}

int Selection(int arr[], int left, int right, int k)
{
	
	
	srand(time(NULL));
	int p = rand() % (right - left + 1) + left;
	int pivot = arr[p];  // 첫번째 원소를 pivot으로 선택 
    int i = left + 1;       // pivot보다 작은 값들을 왼쪽에 저장하기 위한 배열의 인덱스 
    int j = right;          // pivot보다 큰 값들을 오른쪽애 저장하기 위한 배열의 인덱스 
    int tmp1, tmp2;
    tmp1 = arr[left];
    arr[left] = arr[p];
    arr[p] = tmp1;
	int S;
    while (i <= j) 
    {
        while (i <= right && arr[i] <= pivot) 
        {  
            i++;
        }
        while (j > left && arr[j] >= pivot)  
        {  
            j--;
        }
        if (i > j)          
        {            
        	tmp2 = arr[left];
        	arr[left] = arr[j];
        	arr[j] = tmp2;
        }
        else
        {
        	tmp2 = arr[i];
        	arr[i] = arr[j];
        	arr[j] = tmp2;
		}
	}
	
	S = (j-1) -left + 1;
	
	if(k <= S) {
		Selection(arr, left, j-1, k);
	}
	else if(k = S + 1) {
		return arr[j];
	}
	else {
		Selection(arr, j+1, right, k-S-1);
	}
}


