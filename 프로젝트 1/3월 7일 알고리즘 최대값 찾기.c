#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void testsearchK();
int searchK(int k);

int main()
{
	testsearchK();

}

void testsearchK()
{
	int fva = 15;
	int xret = -2;

	xret = searchK(fva);
	if (xret == fva)
	{
		printf("ã�ҽ��ϴ�. %d \n", xret);

	}
	else
	{

		printf("%d ���� ã�� ���߽��ϴ�. %d \n", fva, xret);
	}
}

// �Լ��� find K from array A[]
// return;
//     -1 : if K is not found
//      K : if K is found
int searchK(int k)
{
	// 1. �迭�� ������ ���ڷ� �ʱ�ȭ�Ѵ�.
	int A[10] = { 5, 7, 3, 0, 80, 95, 42, 31, 23, 15 };
	int ret = -1;

	// 2. K���� ���������� ã�´�.
	for (int i = 0; i < 10; i++)
	{
		if (A[i] == k)
		{
			ret = k;
			break;
		}
	}

	return ret;
}