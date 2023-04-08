// 유클리드 함수를 헤더파일에서 불러와서 테스트

#include <stdio.h>
#include "euclid.h"

int testEuclid()
{

	int gcd = 0;

	printf("안녕하세요. 테스트입니다. \n");

	gcd = euclidRecursive(121, 130);

	printf("%d 와 %d의 최대공약수는 %d입니다.\n", 121, 130, gcd);

	return 0;
}
