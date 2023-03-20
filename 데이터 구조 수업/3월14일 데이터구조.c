// 3월 14일 데이터 구조 실행시간 측정 클락함수
// 19학번 2학년 이동근

#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 


/*  void main(void)
{
    clock_t start, finish;
    double duration;

    start = clock();

    // 실행 시간을 측정하고자 하는 코드.... 
    // ....

    finish = clock();

    duration = (double)(finish - start) / CLOCKS_PER_SEC; 
    printf("%f 초입니다.\n", duration);

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

	printf("%f 초입니다.\n", duration);

	return 0;

}