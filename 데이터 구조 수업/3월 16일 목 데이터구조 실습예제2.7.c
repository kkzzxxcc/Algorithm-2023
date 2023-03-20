// 3월 16일 데이터구조 수업
// 19학번 2학년 이동근
// 배열과 구조체, 함수
// 배열과 클래스

#define _CRT_SECURE_NO_WARNINGS  // 비주얼 스튜디오에서 sacnf 오류 무시해주는 정의

// 3월 16일 전체 다항식 프로그램 예제 2.7 실습코드

#include <stdio.h>
#define MAX_DEGREE 101 // 다항식의 최고 차수 + 1


typedef struct 
{
	int degree;
	float coef[MAX_DEGREE];

} Polynomial;

void print_poly(Polynomial p, char str[]) // 다항식의 화면 출력 함수
{
	int i;

	printf("\t%s", str);

	for (i = 0; i < p.degree; i++)
		printf("%5.1f x^%d + ", p.coef[i], p.degree - i);

	printf("%4.1f\n", p.coef[p.degree]);
}

Polynomial read_poly() // 다항식의 입력 함수
{
	int i;
	Polynomial p;

	printf("다항식의 최고 차수를 입력하시오: ");
	scanf("%d", &p.degree);

	printf("각 항의 계수를 입력하시오 (총 %d개): ", p.degree + 1);

	for (i = 0; i <= p.degree; i++)
		scanf("%f", p.coef + i);

	return p;
}

Polynomial add_poly(Polynomial a, Polynomial b)  // 다항식의 합을 구하는 함수
{
	int i;
	Polynomial p;

	if (a.degree > b.degree) 
	{
		p = a;

		for (i = 0; i <= b.degree; i++)
			p.coef[i + (p.degree - b.degree)] += b.coef[i];
	}

	else 
	{
		p = b;

		for (i = 0; i <= a.degree; i++)
			p.coef[i + (p.degree - a.degree)] += a.coef[i];
	}

	return p;
}

void main()
{

	Polynomial a, b, c;

	a = read_poly();
	b = read_poly();
	c = add_poly(a, b);

	print_poly(a, " A = ");
	print_poly(b, " B = ");
	print_poly(c, " A + B = ");

}