// 3�� 14�� ������ ���� ����ð� ���� Ŭ���Լ�
// 19�й� 2�г� �̵���

#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 


/*  void main(void)
{
    clock_t start, finish;
    double duration;

    start = clock();

    // ���� �ð��� �����ϰ��� �ϴ� �ڵ�.... 
    // ....

    finish = clock();

    duration = (double)(finish - start) / CLOCKS_PER_SEC; 
    printf("%f ���Դϴ�.\n", duration);

} */

#define MAX_ELEMENTS 50000

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
	clock_t start, finish;
	double duration;

	seed = time(NULL);
	srand(seed);
	

	for (i = 0; i < MAX_ELEMENTS; i++) {

		score[i] = rand();

	}

	start = clock();

	res = find_max_score(MAX_ELEMENTS);

	finish = clock();
	duration = (double)(finish - start) / CLOCKS_PER_SEC;

	printf("res = %d \n", res);

	printf("%f ���Դϴ�.\n", duration);

	return 0;

}