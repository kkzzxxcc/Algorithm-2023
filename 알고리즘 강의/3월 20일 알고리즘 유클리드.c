// 3월 20일 알고리즘 실습
// 201911079 이동근
// 유클리드의 최대공약수 알고리즘 짜보기

#include <stdio.h>

// int main(int argc, char *argv[])


int eUclid(int a, int b)
{
	
	// If(b = 0) return a // 종료조건 of 재귀호출!
	if (b == 0)
		return a;

    // return Euclid(b, a mod b)
	return eUclid(b, a % b);


}

int test_eUclid()
{

	int gcd = 0;

	gcd = eUclid(34, 48);

	printf("Hello World %d \n", gcd);

	return 0;
}


int main()

{
	test_eUclid();
	
}