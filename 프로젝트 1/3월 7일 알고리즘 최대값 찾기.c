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
		printf("찾았습니다. %d \n", xret);

	}
	else
	{

		printf("%d 값을 찾지 못했습니다. %d \n", fva, xret);
	}
}

// 함수는 find K from array A[]
// return;
//     -1 : if K is not found
//      K : if K is found
int searchK(int k)
{
	// 1. 배열을 임의의 숫자로 초기화한다.
	int A[10] = { 5, 7, 3, 0, 80, 95, 42, 31, 23, 15 };
	int ret = -1;

	// 2. K값을 순차적으로 찾는다.
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