// 3�� 16�� �����ͱ��� ����
// 19�й� 2�г� �̵���
// �迭�� ����ü, �Լ�
// �迭�� Ŭ����

#define _CRT_SECURE_NO_WARNINGS  // ���־� ��Ʃ������� sacnf ���� �������ִ� ����

// 3�� 16�� ��ü ���׽� ���α׷� ���� 2.7 �ǽ��ڵ�

#include <stdio.h>
#define MAX_DEGREE 101 // ���׽��� �ְ� ���� + 1


typedef struct 
{
	int degree;
	float coef[MAX_DEGREE];

} Polynomial;

void print_poly(Polynomial p, char str[]) // ���׽��� ȭ�� ��� �Լ�
{
	int i;

	printf("\t%s", str);

	for (i = 0; i < p.degree; i++)
		printf("%5.1f x^%d + ", p.coef[i], p.degree - i);

	printf("%4.1f\n", p.coef[p.degree]);
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