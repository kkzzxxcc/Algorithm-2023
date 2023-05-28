#define _CRT_SECURE_NO_WARNINGS  // 비주얼 스튜디오에서 sacnf 오류 무시해주는 정의
// 5월 24일
// 알고리즘 송해상 교수님
// 20191179 이동근
// 플로이드 워샬

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define num 5
#define INF  1000000

double a[5][5] = {
	{0, 3, INF , 2 , 1},
	{INF , 0 , 1 , INF , 1},
	{INF , 1 , 0 , 3 , 5},
	{3 , INF , 6 , 0 , INF},
	{INF , INF , INF , 0.5 , 0}
};

void floyd()
{
	int i, j, k;
	double d[num][num];

	for (i = 0; i < num; i++)
	{
		for (j = 0; j < num; j++)
		{
			d[i][j] = a[i][j];
		}
	}

	for (k = 0; k < num; k++)
	{
		for (i = 0; i < num; i++)
		{
			for (j = 0; j < num; j++)
			{
				if (d[i][k] + d[k][j] < d[i][j])
				{
					d[i][j] = d[i][k] + d[k][j];
				}
			}
		}
	}
	for (i = 0; i < num; i++) {
		for (j = 0; j < num; j++) {
			printf("%5.1lf ", d[i][j]);
		}
		printf("\n");
	}
}


int main(void)
{
	floyd();

	return 0;
}