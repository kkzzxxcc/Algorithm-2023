#pragma warning(disable:4996) // 비주얼 스튜디오에서 sacnf 오류 무시해주는 정의
#define _CRT_SECURE_NO_WARNINGS
// 4월 25일 데이터구조 수업
// 19학번 2학년 이동근
// 7장 순환
// 순환적 팩토리얼 계산, 반복적 팩토리얼 계산

#include <stdio.h>
#include <stdlib.h>

int factorial(int n)   // 순환적 팩토리얼 계산 함수
{
	printf("factorial(%d)\n", n);       // 순환호출 순서 확인을 위한 출력문

	if (n == 1)
		return 1;

	else
		return (n * factorial(n - 1));
}

int factorial_iter(int n)  // 반복적 팩토리얼 계산 함수
{
	int k, result = 1;

	for (k = n; k > 0; k--)
		result = result * k;

	printf("%d", result);

	return result;
}

void main()
{
	factorial(200);
	factorial_iter(8);
}