// 3월 16일 데이터구조 수업
// 19학번 2학년 이동근
// 배열과 구조체, 함수
// 배열과 클래스
// 전체 다항식 프로그램 2.7 예제 double Cal_poly(Polynomial p, double x) 함수 추가
// 음수인 경우에도 출력되도록 추가

#define _CRT_SECURE_NO_WARNINGS  // 비주얼 스튜디오에서 sacnf 오류 무시해주는 정의

// 3월 16일 전체 다항식 프로그램 예제 2.7 실습코드

#include <stdio.h>
#include <math.h>
#define MAX_DEGREE 101 // 다항식의 최고 차수 + 1


typedef struct 
{
	int degree;
	float coef[MAX_DEGREE];

} Polynomial;

/* void print_poly(Polynomial p, char str[]) // 다항식의 화면 출력 함수
{
	int i;

	printf("\t%s", str);

	for (i = 0; i < p.degree; i++)
		printf("%5.1f x^%d + ", p.coef[i], p.degree - i);

	printf("%4.1f\n", p.coef[p.degree]);
}
*/


void print_poly(Polynomial p, char str[])  // 다항식의 화면 출력 함수
{
	int i;

	printf("\t%s", str);

	for (i = p.degree; i > 1; i--)
	{
		if (p.coef[p.degree - i + 1] >= 0) // 계수가 양수인 경우
		{
			if (p.coef[p.degree - i + 1] == 1) // 계수가 1인 경우
				printf(" + x^%d", i - 1);

			else // 일반적인 경우
				printf(" + %.1f x^%d", p.coef[p.degree - i + 1], i - 1);
		}

		else // 계수가 음수인 경우
		{
			if (p.coef[p.degree - i + 1] == -1) // 계수가 -1인 경우
				printf(" - x^%d", i - 1);

			else // 일반적인 경우
				printf(" - %.1f x^%d", -p.coef[p.degree - i + 1], i - 1);
		}
	}

	if (p.coef[p.degree - 1] >= 0) // 1차항의 계수가 양수인 경우
	{
		if (p.coef[p.degree - 1] == 1) // 1차항의 계수가 1인 경우
			printf(" + x");

		else // 일반적인 경우
			printf(" + %.1f x", p.coef[p.degree - 1]);
	}

	else // 1차항의 계수가 음수인 경우
	{
		if (p.coef[p.degree - 1] == -1) // 1차항의 계수가 -1인 경우
			printf(" - x");

		else // 일반적인 경우
			printf(" - %.1f x", -p.coef[p.degree - 1]);
	}

	if (p.coef[p.degree] >= 0) // 상수항이 양수인 경우
		if (p.coef[p.degree] != 0)
		    printf(" + %.1f\n", p.coef[p.degree]);

	else // 상수항이 음수인 경우
		printf(" - %.1f\n", -p.coef[p.degree]);
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

double Cal_poly(Polynomial p, double x) // 다항식에 x 값을 대입하여 결과값 반환
{
	int i;
	double result = 0.0;

	for (i = 0; i <= p.degree; i++)
		result += p.coef[i] * pow(x, p.degree - i);

	return result;
}

void main()
{

	Polynomial a, b, c;
	double x;

	a = read_poly();
	b = read_poly();
	c = add_poly(a, b);

	print_poly(a, " \nA = ");
	print_poly(b, " \nB = ");
	print_poly(c, "\nA + B = ");

	printf("\n x 값을 입력하시오: ");
	scanf("%lf", &x);

	printf("A(x) = %lf\n", Cal_poly(a, x));
	printf("B(x) = %lf\n", Cal_poly(b, x));
	printf("A(x) + B(x) = %lf\n", Cal_poly(c, x));

	return 0;
}

