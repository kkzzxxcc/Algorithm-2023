// 3�� 15�� �����ͱ��� ����(����)
// 19�й� 2�г� �̵���
// �迭�� ����ü

// ������ �迭�� ����
/* 
#include <stdio.h>

void main()
{

	int A[5] = { 10, 20, 30 };
	int B[5], i, x = 2018, y = 0;

	y = x;

	for (i = 0; i < 5; i++)
		B[i] = A[i];

	printf("���� ���� ���: x = %d, y = %d\n", x, y);
	printf("�迭 ���� ���: \n");

	for (i = 0; i < 5; i++) {

		printf("A[%d] = %d\t", i, A[i]);
		printf("B[%d] = %d\n", i, B[i]);

	}
	
	
} */

// �迭 a�� b�� ���ڸ� �Է¹ް� ������ ����ߴ� �Լ��� �̿��Ͽ� �ִ밪�� ���� �迭�� ����ϴ� �ǽ�

/*
#include <stdio.h>
#define MAX_ELEMENTS 50000

int find_max_score(int score[], int n)
{

	int i, tmp;
	tmp = score[0];

	for (i = 0; i < n; i++)
		if (score[i] > tmp)
			tmp = score[i];

	return tmp;
}


int main(void)
{
	int A[5], B[5];
	int i, maxA, maxB;

	for (i = 0; i < 5; i++) {

		printf("���� 2���� �Է��ϼ��� >>");
		scanf_s("%d %d", &A[i], &B[i]);

	}

	maxA = find_max_score(A, 5);
	maxB = find_max_score(B, 5);

	if (maxA > maxB)
		printf(" �迭 A ");

	else if (maxA < maxB)
		printf(" �迭 B ");

	else
		printf(" �迭 A�� �迭 B�� ���� �ִ밪�� ������ �ֽ��ϴ�");


	return 0;
}
*/

// ���� �ǽ��� �����ͷ� �����ϴ� �ǽ�
#include <stdio.h>
#define MAX_ELEMENTS 50000

int find_max_score(int *score, int n)
{

	int i, tmp;
	tmp = *(score);

	for (i = 0; i < n; i++)
		if (*(score + i) > tmp)
			tmp = *(score + i);

	return tmp;
}


int main(void)
{
	int A[5], B[5];  // A[i] <==> *(A+i), & A[i] <==> A+i
	int i, maxA, maxB;

	for (i = 0; i < 5; i++) {

		printf("���� 2���� �Է��ϼ��� >>");
		scanf_s("%d %d", &A + i, &B + i);

	}

	maxA = find_max_score(A, 5);
	maxB = find_max_score(B, 5);

	if (maxA > maxB)
		printf(" �迭 A ");

	else if (maxA < maxB)
		printf(" �迭 B ");

	else
		printf(" �迭 A�� �迭 B�� ���� �ִ밪�� ������ �ֽ��ϴ�");


	return 0;

}

