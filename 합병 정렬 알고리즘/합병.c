#pragma warning(disable:4996) // ���־� ��Ʃ������� sacnf ���� �������ִ� ����
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#define MAX 8

void mergeSort(int data[], int p, int r);
void merge(int data[], int p, int q, int r);

int main() {
	
	int data[MAX];
	int i;
	FILE *fp = NULL;
	// ���� ��� �б� 
	fp = fopen("data.txt", "r");
	
	if (fp == NULL)
    {
        printf("������ ���µ� �����߽��ϴ�. \n");
        return 1;
    }
    else
	{
		printf("������ ���µ� �����߽��ϴ�. \n");
	} 
	
	// ���Ͽ��� ������ �о�� data �迭�� �����Ѵ�. 
	while (fscanf(fp, "%d", &data[i]) != EOF) 
    {
        i++;
    }
    fclose(fp);
	
    printf("���� ��\n");    
    for(i = 0; i < MAX; i++) {
        printf("%d ", data[i]);
    }
    // �պ� ���� ���� 
    mergeSort(data, 0, MAX-1);
    
    // ������ ����� ���Ͽ� ����. 
    fp = fopen("result.txt", "w");
    
    for(i = 0; i < MAX; i++) {
        fprintf(fp, "%d ", data[i]);
    }
    
    printf("\n���� ��\n");
    for(i = 0; i < MAX; i++) {
        printf("%d ", data[i]);
    }
    
    return 0;
}


void mergeSort(int data[], int p, int r) {
	
    int q;
    
    if(p<r) {
        q = (p+r)/2;
        mergeSort(data, p , q);
        mergeSort(data, q+1, r);
        merge(data, p, q, r);
    }
}
void merge(int data[], int p, int q, int r) {
	
    int i = p, j = q+1, k = p;	// 
    int tmp[8]; // �� �迭
    int a; 
    
    // data[i]�� data[j]�� ���� ���� ���� ���� tmp �迭�� �����Ѵ�. 
    while(i<=q && j<=r) {
        if(data[i] <= data[j]) tmp[k++] = data[i++];
        else tmp[k++] = data[j++];
    }
    // i�� q���� ���� ������ ��� 
    while(i<=q) tmp[k++] = data[i++];
    // j�� r���� ���� ������ ��� 
    while(j<=r) tmp[k++] = data[j++];
    
    // �ӽù迭�� ���� �����迭�� �����Ѵ�. 
    for(a = p; a<=r; a++) data[a] = tmp[a];
}

