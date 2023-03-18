// 3�� 7�� �����ͱ��� ����
// 19�й� 2�г� �̵��� 201911079
// 
// �ִ밪�� ã�� ����ϴ� �ڵ�



#pragma warning(disable:4996) // ���־� ��Ʃ������� sacnf ���� �������ִ� ����

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define MAX_ELEMENTS 10000

int score[MAX_ELEMENTS] = { 100, 23, 300 };

int find_max_score(int n)
{
	int i, tmp;
	tmp = score[0];

	for (i = 1; i < n; i++) {
		if (score[i] > tmp) {
			tmp = score[i];
		}
	}
	return tmp;
}

int main(void)
{

	int i, res;
	long seed;

	seed = time(NULL);
	srand(seed);

	for (i = 0; i < MAX_ELEMENTS; i++) {

		score[i] = rand();

	}

	res = find_max_score(MAX_ELEMENTS);

	printf("res = %d \n", res);

	return 0;

}