#pragma warning(disable:4996) // ���־� ��Ʃ������� sacnf ���� �������ִ� ����
#define _CRT_SECURE_NO_WARNINGS
// 5�� 5�� �˰��� ����
// 19�й� 2�г� �̵���
// ������ �˰��� �����ϱ�
// �Է� �����ʹ� ����� data.txt �� ����, ������ ���� �� �˰��� ����, ����� result.txt�� ����

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100000 // �迭�� �ִ� ũ��

void quicksort(int arr[], int left, int right);

int main() {
    int arr[MAX_SIZE];
    int n = 0;  
    int i;

    // ���� ����
    FILE* fp;
    fp = fopen("data.txt", "r");
    if (fp == NULL)
    {
        printf("������ ���µ� �����߽��ϴ�. \n");
        return 1;
    }
    
    // ���Ͽ��� �迭 �о����
    while (fscanf(fp, "%d", &arr[n]) != EOF) 
    {
        n++;
    }
    fclose(fp);

    // �� ���� �Լ� ����
    quicksort(arr, 0, n - 1);

    // ��� ����
    fp = fopen("result.txt", "w");

    if (fp == NULL) 
    {
        printf("������ ���µ� �����߽��ϴ�.\n");
        return 1;
    }
    for (i = 0; i < n; i++) 
    {
        fprintf(fp, "%d\n", arr[i]);
    }
    fclose(fp);

    return 0;
}

// ������ �Լ�
void quicksort(int arr[], int left, int right) 
{
    if (left < right) 
    {
        int pivot = arr[left];  // ù��° ���Ҹ� pivot���� ����
        int i = left + 1;       // pivot���� ���� ������ ���ʿ� �����ϱ� ���� �迭�� �ε���
        int j = right;          // pivot���� ū ������ �����ʾ� �����ϱ� ���� �迭�� �ε���
        int temp;

        while (i <= j) 
        {
            while (arr[i] < pivot) // pivot���� ���� ���� ã�� ������ i ����
            {  
                i++;
            }
            while (arr[j] > pivot) // pivot���� ū ���� ã�� ������ j ����
            {  
                j--;
            }
            if (i <= j)          // i�� j�� �������� �ʾ����� i�� j�� ��ġ�� �ٲ� 
            {            
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                i++;
                j--;
            }
        }

        // pivot���� i-1 ��ġ�� �־���
        arr[left] = arr[i - 1];
        arr[i - 1] = pivot;

        // pivot�� �������� ���� �κй迭�� ������ �κй迭�� ���� ���ȣ��
        quicksort(arr, left, i - 2);
        quicksort(arr, i, right);
    }
}

