#pragma warning(disable:4996) // ���־� ��Ʃ������� sacnf ���� �������ִ� ����
#define _CRT_SECURE_NO_WARNINGS
// 4�� 25�� �����ͱ��� ����
// 19�й� 2�г� �̵���
// 7�� ��ȯ
// ��ȯ�� ���丮�� ���, �ݺ��� ���丮�� ���

#include <stdio.h>
#include <stdlib.h>

int factorial(int n)   // ��ȯ�� ���丮�� ��� �Լ�
{
	printf("factorial(%d)\n", n);       // ��ȯȣ�� ���� Ȯ���� ���� ��¹�

	if (n == 1)
		return 1;

	else
		return (n * factorial(n - 1));
}

int factorial_iter(int n)  // �ݺ��� ���丮�� ��� �Լ�
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