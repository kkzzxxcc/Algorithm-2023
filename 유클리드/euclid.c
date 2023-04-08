
// 4월 4일 알고리즘 실습
// 201911079 이동근
// 유클리드 알고리즘을 함수로 정의

#include <stdio.h>
#include <stdlib.h>


// 재귀적 최대공약수 알고리즘
int euclidRecursive(int a, int b)
{
	// If(b = 0) return a // 종료조건 of 재귀호출!
	if (b == 0)
		return a;

	// return euclidRecursive(b, a mod b)
	else 
	    return euclidRecursive(b, a % b);
	
}

// 반복적 최대공약수 알고리즘
int euclidRepeatitive(int a, int b)
{
	if (a < b) 
		return 0; // 입력확인

	int bsav;    // 임시 기억

	while(b != 0)
	{
		bsav = b;

		b = a % b;
		a = bsav;
	}

	return a;
	
}
