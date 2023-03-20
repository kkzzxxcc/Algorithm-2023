// 3월 15일 데이터구조 수업(보강)
// 19학번 2학년 이동근
// 배열과 구조체

// 변수와 배열의 복사
/* 
#include <stdio.h>

void main()
{

	int A[5] = { 10, 20, 30 };
	int B[5], i, x = 2018, y = 0;

	y = x;

	for (i = 0; i < 5; i++)
		B[i] = A[i];

	printf("변수 복사 결과: x = %d, y = %d\n", x, y);
	printf("배열 복사 결과: \n");

	for (i = 0; i < 5; i++) {

		printf("A[%d] = %d\t", i, A[i]);
		printf("B[%d] = %d\n", i, B[i]);

	}
	
	
} */

// 배열 a와 b에 숫자를 입력받고 이전에 사용했던 함수를 이용하여 최대값을 가진 배열을 출력하는 실습

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

		printf("숫자 2개를 입력하세요 >>");
		scanf_s("%d %d", &A[i], &B[i]);

	}

	maxA = find_max_score(A, 5);
	maxB = find_max_score(B, 5);

	if (maxA > maxB)
		printf(" 배열 A ");

	else if (maxA < maxB)
		printf(" 배열 B ");

	else
		printf(" 배열 A와 배열 B가 같은 최대값을 가지고 있습니다");


	return 0;
}
*/

// 위의 실습을 포인터로 변경하는 실습
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

		printf("숫자 2개를 입력하세요 >>");
		scanf_s("%d %d", &A + i, &B + i);

	}

	maxA = find_max_score(A, 5);
	maxB = find_max_score(B, 5);

	if (maxA > maxB)
		printf(" 배열 A ");

	else if (maxA < maxB)
		printf(" 배열 B ");

	else
		printf(" 배열 A와 배열 B가 같은 최대값을 가지고 있습니다");


	return 0;

}

