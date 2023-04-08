#pragma warning(disable:4996) // 비주얼 스튜디오에서 sacnf 오류 무시해주는 정의

// 4월 4일 알고리즘 실습
// 201911079 이동근
// 유클리드 알고리즘을 함수로 정의

#include <stdio.h>


// 재귀적 최대공약수 알고리즘
int euclidRecursive(int a, int b)
{
	// If(b = 0) return a // 종료조건 of 재귀호출!
	if (b == 0)
		return a;

	// return euclidRecursive(b, a mod b)
	return euclidRecursive(b, a % b);
	
}

// 반복적 최대공약수 알고리즘
int euclidRepeatitive(int a, int b)
{
	return 0;
}