#pragma warning(disable:4996) // ���־� ��Ʃ������� sacnf ���� �������ִ� ����
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
        printf("������ ���µ� �����߽��ϴ�. \n");
        return 1;
    }
    else
	{
		printf("������ ���µ� �����߽��ϴ�. \n");
	} 
    int arr[MAX];
    int i = 0;
    // ���Ͽ��� �迭 �о����  
    while (fscanf(fp, "%d", &arr[i]) != EOF) 
    {
    	i++;
	}
    fclose(fp);
	printf("�� ��°�� ���� ���� ���Ͻʴϱ�? ");
	scanf("%d", &num);
    // �� ���� �Լ� ���� 
    result = Selection(arr, 0, MAX-1, num);

    // ��� ���� 
    fp = fopen("result.txt", "w");

    if (fp == NULL) 
    {
        printf("������ ���µ� �����߽��ϴ�.\n");
        return 1;
    }
    
    fprintf(fp, "%d ", result);
    printf("%d����� ���� ���� %d�Դϴ�", num, result);

    return 0;
	
}

int Selection(int arr[], int left, int right, int k)
{
	
	
	srand(time(NULL));
	int p = rand() % (right - left + 1) + left;
	int pivot = arr[p];  // ù��° ���Ҹ� pivot���� ���� 
    int i = left + 1;       // pivot���� ���� ������ ���ʿ� �����ϱ� ���� �迭�� �ε��� 
    int j = right;          // pivot���� ū ������ �����ʾ� �����ϱ� ���� �迭�� �ε��� 
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


