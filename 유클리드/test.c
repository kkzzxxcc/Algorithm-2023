// ��Ŭ���� �Լ��� ������Ͽ��� �ҷ��ͼ� �׽�Ʈ

#include <stdio.h>
#include "euclid.h"

int testEuclid()
{

	int gcd = 0;

	printf("�ȳ��ϼ���. �׽�Ʈ�Դϴ�. \n");

	gcd = euclidRecursive(121, 130);

	printf("%d �� %d�� �ִ������� %d�Դϴ�.\n", 121, 130, gcd);

	return 0;
}
