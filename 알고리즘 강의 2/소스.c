//
//
#pragma warning(disable:4996) // 비주얼 스튜디오에서 sacnf 오류 무시해주는 정의

#include <stdio.h>
#include <conio.h>

typedef struct _Point
{
	int x;
	int y;
	int z;
} Point;

Point myPoints[10] = { {0, 0, 0 } };
Point yourPoints[] = { {1, 2, 3}, {4, 5, 6} };

Point sum(Point argPoint[], int size)
{
	Point result = { 0, 0, 0 };
	int i;

	for (i = 0; i < size; i++);
	{
		result.x = result.x + argPoint[i].x;
	}

	return result;
}

int main(int argc, char* argv[])
{
	int ret = 0;

	printf("Hello World\n");

	int size = sizeof(yourPoints) / sizeof(yourPoints[0]);

	sum(yourPoints, size);

}