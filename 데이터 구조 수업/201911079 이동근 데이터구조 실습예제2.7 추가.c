// 3�� 16�� �����ͱ��� ����
// 19�й� 2�г� �̵���
// �迭�� ����ü, �Լ�
// �迭�� Ŭ����
// ��ü ���׽� ���α׷� 2.7 ���� double Cal_poly(Polynomial p, double x) �Լ� �߰�
// ������ ��쿡�� ��µǵ��� �߰�

#define _CRT_SECURE_NO_WARNINGS  // ���־� ��Ʃ������� sacnf ���� �������ִ� ����

// 3�� 16�� ��ü ���׽� ���α׷� ���� 2.7 �ǽ��ڵ�

#include <stdio.h>
#include <math.h>
#define MAX_DEGREE 101 // ���׽��� �ְ� ���� + 1


typedef struct 
{
	int degree;
	float coef[MAX_DEGREE];

} Polynomial;

/* void print_poly(Polynomial p, char str[]) // ���׽��� ȭ�� ��� �Լ�
{
	int i;

	printf("\t%s", str);

	for (i = 0; i < p.degree; i++)
		printf("%5.1f x^%d + ", p.coef[i], p.degree - i);

	printf("%4.1f\n", p.coef[p.degree]);
}
*/


void print_poly(Polynomial p, char str[])  // ���׽��� ȭ�� ��� �Լ�
{
	int i;

	printf("\t%s", str);

	for (i = p.degree; i > 1; i--)
	{
		if (p.coef[p.degree - i + 1] >= 0) // ����� ����� ���
		{
			if (p.coef[p.degree - i + 1] == 1) // ����� 1�� ���
				printf(" + x^%d", i - 1);

			else // �Ϲ����� ���
				printf(" + %.1f x^%d", p.coef[p.degree - i + 1], i - 1);
		}

		else // ����� ������ ���
		{
			if (p.coef[p.degree - i + 1] == -1) // ����� -1�� ���
				printf(" - x^%d", i - 1);

			else // �Ϲ����� ���
				printf(" - %.1f x^%d", -p.coef[p.degree - i + 1], i - 1);
		}
	}

	if (p.coef[p.degree - 1] >= 0) // 1������ ����� ����� ���
	{
		if (p.coef[p.degree - 1] == 1) // 1������ ����� 1�� ���
			printf(" + x");

		else // �Ϲ����� ���
			printf(" + %.1f x", p.coef[p.degree - 1]);
	}

	else // 1������ ����� ������ ���
	{
		if (p.coef[p.degree - 1] == -1) // 1������ ����� -1�� ���
			printf(" - x");

		else // �Ϲ����� ���
			printf(" - %.1f x", -p.coef[p.degree - 1]);
	}

	if (p.coef[p.degree] >= 0) // ������� ����� ���
		if (p.coef[p.degree] != 0)
		    printf(" + %.1f\n", p.coef[p.degree]);

	else // ������� ������ ���
		printf(" - %.1f\n", -p.coef[p.degree]);
}



Polynomial read_poly() // ���׽��� �Է� �Լ�
{
	int i;
	Polynomial p;

	printf("���׽��� �ְ� ������ �Է��Ͻÿ�: ");
	scanf("%d", &p.degree);

	printf("�� ���� ����� �Է��Ͻÿ� (�� %d��): ", p.degree + 1);

	for (i = 0; i <= p.degree; i++)
		scanf("%f", p.coef + i);

	return p;
}

Polynomial add_poly(Polynomial a, Polynomial b)  // ���׽��� ���� ���ϴ� �Լ�
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

double Cal_poly(Polynomial p, double x) // ���׽Ŀ� x ���� �����Ͽ� ����� ��ȯ
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

	printf("\n x ���� �Է��Ͻÿ�: ");
	scanf("%lf", &x);

	printf("A(x) = %lf\n", Cal_poly(a, x));
	printf("B(x) = %lf\n", Cal_poly(b, x));
	printf("A(x) + B(x) = %lf\n", Cal_poly(c, x));

	return 0;
}

