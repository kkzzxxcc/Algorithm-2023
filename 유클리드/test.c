#pragma warning(disable:4996) // ���־� ��Ʃ������� sacnf ���� �������ִ� ����
// ��Ŭ���� �Լ��� ������Ͽ��� �ҷ��ͼ� �׽�Ʈ

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "euclid.h"

#define N 100000

int testEuclid()  // ����� �˰������� ����ϴ� �ִ����� �˰��� �Լ�
{

    int a, b;
    int gcd = 0;

	printf("�ȳ��ϼ���. �׽�Ʈ�Դϴ�. ����� �˰������� ����� �ִ����� �Դϴ�. \n");

    // �� �� �Է�
    printf("�� ������ �Է��ϼ���: ");
    scanf("%d %d", &a, &b);

    // ����� �˰������� �ִ����� ���
    gcd = euclidRecursive(a, b);
    printf("����� �˰������� ���� �ִ�����: %d\n", gcd);


	return 0;
}

int testEuclid_2()  // �ݺ��� �˰������� ����ϴ� �ִ����� �˰��� �Լ�
{

    int a, b;
	int gcd_2 = 0;

	printf("�ȳ��ϼ��� �׽�Ʈ2 �Դϴ�. �ݺ��� �˰������� ����� �ִ����� �Դϴ�.\n");

    // �� �� �Է�
    printf("�� ������ �Է��ϼ���: ");
    scanf("%d %d", &a, &b);

    // �ݺ��� �˰������� �ִ����� ���
    gcd_2 = euclidRecursive(a, b);
    printf("�ݺ��� �˰������� ���� �ִ�����: %d\n", gcd_2);

	return 0;
}

int check_time()
{
  
    int a[N], b[N];
    int i, gcd1, gcd2;
    double time1, time2;
    clock_t start, end;

    // N���� �׽�Ʈ ���̽� ����
    srand((unsigned int)time(NULL));

    for (i = 0; i < N; i++) 
    {
        a[i] = rand();
        b[i] = rand();
    }

    // ����� �˰����� ����ð� ����
    start = clock();
    for (i = 0; i < N; i++) 
    {
        gcd1 = euclidRecursive(a[i], b[i]);
    }
    end = clock();

    time1 = (double)(end - start) / CLOCKS_PER_SEC;

    // �ݺ��� �˰����� ����ð� ����
    start = clock();
    for (i = 0; i < N; i++) 
    {
        gcd2 = euclidRepeatitive(a[i], b[i]);
    }
    end = clock();

    time2 = (double)(end - start) / CLOCKS_PER_SEC;

    // ��� ���
    if (gcd1 == gcd2)
        printf("����� ����� �ݺ��� ����� �ִ����� ���� �����ϴ�\n"); // ���� ���Ƶ� ����Ƚ���� �ٸ��� �ٸ��ٰ� ��� �� ���� ����

    else
        printf("����� ����� �ݺ��� ����� �ִ����� ���� �ٸ��ϴ�\n");
   
    printf("����� �˰����� ����ð�: %.6f��\n", time1);
    printf("�ݺ��� �˰����� ����ð�: %.6f��\n", time2);

    return 0;
} 
