#pragma warning(disable:4996) // 비주얼 스튜디오에서 sacnf 오류 무시해주는 정의
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Point {
    double x, y;
}Points;

int CompareX(const void* a, const void* b);
double Distance(Points p1, Points p2);
double ClosestPair(Points* points, int n);
void testClosetPair_File();

int main(void) 
{
    testClosetPair_File();

    return 0;
}

int CompareX(const void* a, const void* b) // x 좌표를 기준으로 오름차순 정렬
{
    Points* p1 = (Points*)a;
    Points* p2 = (Points*)b;
    return (p1->x - p2->x);
}

double Distance(Points p1, Points p2) { return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2)); }

double ClosestPair(Points* points, int n)
{
	int i, j, k;
    if (n <= 3) { // 기저 사례 
        double min_dist = 99999.0;
        for (i = 0; i < n - 1; i++)
        {
            for (j = i + 1; j < n; j++)
            {
                double dist = Distance(points[i], points[j]);
                if (dist < min_dist)
                    min_dist = dist;
            }
        }
        return min_dist;
    }

    // x 좌표를 기준으로 정렬된 배열을 두 개로 분할
    int mid = n / 2;
    double mid_x = points[mid].x;
    double dl = ClosestPair(points, mid);
    double dr = ClosestPair(points + mid, n - mid);
    double d = fmin(dl, dr);

    // 중앙 영역에서 최단 거리를 갱신할 수 있는 후보점들을 찾음
    Points strip[100];
    j = 0;
    for (i = 0; i < n; i++)
    {
        if (fabs(points[i].x - mid_x) < d)
        {
            strip[j] = points[i];
            j++;
        }
    }

    // 중앙 영역에서 최단 거리 갱신 
    for (i = 0; i < j - 1; i++)
    {
        for (k = i + 1; k < j && (strip[k].y - strip[i].y) < d; k++)
        {
            double dist = Distance(strip[i], strip[k]);
            if (dist < d)
                d = dist;
        }
    }
    return d;
}

int testClosetPair_File()
{
    int i = 0;
    Points points[100];
    FILE* fp = NULL;

    fp = fopen("CPdata.txt", "r");
    if (fp == NULL)
    {
        printf("CPdata 파일을 여는데 실패했습니다. \n");
        return 0;
    }
    else {
        printf("CPdata 파일을 여는데 성공했습니다. \n");
    } 
    while (fscanf(fp, "%lf %lf\n", &points[i].x, &points[i].y) != EOF)
    {
        printf("x = %.2lf, y = %.2lf\n", points[i].x, points[i].y);
        i++;
    }
    fclose(fp);

    qsort(points, 4, sizeof(Points), CompareX);

    double min_dist = ClosestPair(points, 4);

    printf("최근접 점 쌍의 거리는 %.2lf\n", min_dist);
}
