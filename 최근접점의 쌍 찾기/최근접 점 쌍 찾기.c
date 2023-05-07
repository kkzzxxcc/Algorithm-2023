#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 99999.0     //임시 최댓값

//점의 좌표
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

//x 좌표를 기준으로 오름차순 정렬
//int Mycmp(const void* a, const void* b) {return (*(int*)a - *(int*)b);} 오름차순 정렬
int CompareX(const void* a, const void* b) 
{
    Points* p1 = (Points*)a;
    Points* p2 = (Points*)b;
    return (p1->x - p2->x);
}

//거리 구하는 함수 sqrt: 제곱근, pow: n제곱근
double Distance(Points p1, Points p2) { return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2)); }

double ClosestPair(Points* points, int n)
{
    //IF (i <= 3) return (2~3개의 점들 사이의 최근접 쌍)
    if (n <= 3) 
    {
        double min_dist = MAX;      
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                double dist = Distance(points[i], points[j]);
                if (dist < min_dist)
                    min_dist = dist;
            }
        }
        return min_dist;
    }

    //x 좌표를 기준으로 정렬된 배열을 두 개로 분할
    int mid = n / 2;
    double mid_x = points[mid].x;
    double dl = ClosestPair(points, mid);
    double dr = ClosestPair(points + mid, n - mid);
    
    //왼쪽과 오른쪽의 최솟값 double fmin: double a, double b의 최솟값
    double d = fmin(dl, dr);

    //중앙 영역에서 최단 거리의 점의 쌍이 있는 지 찾기
    Points strip[100];
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if (fabs(points[i].x - mid_x) < d)  //fabs: 부동 소수점 절댓값 연산함수
        {
            strip[j] = points[i];
            j++;
        }
    }

    //중앙 영역에서 최단 거리
    for (int i = 0; i < j - 1; i++)
    {
        for (int k = i + 1; k < j && (strip[k].y - strip[i].y) < d; k++)
        {
            double dist = Distance(strip[i], strip[k]);
            if (dist < d)
                d = dist;
        }
    }

    return d;
}

void testClosetPair_File()
{
    Points points[100];
    FILE* fp = NULL;

    //점의 좌표들을 읽을 파일 열기
    fp = fopen("D:\CPdata.txt", "r");
    if (fp == NULL)
    {
        printf("CPdata 파일을 여는데 실패했습니다. \n");
        return 0;
    }
    else
        printf("CPdata 파일을 여는데 성공했습니다. \n");

    //점의 좌표들 읽어 구조체 변수에 저장
    int i = 0;
    while (fscanf(fp, "%lf %lf\n", &points[i].x, &points[i].y) != EOF)
    {
        //printf("x = %.2lf, y = %.2lf\n", points[i].x, points[i].y); 정상적으로 저장되는 지 확인하기 위함
        i++;
    }
    fclose(fp);

    //qsort: 퀵정렬(정렬하고자 하는 배열의 포인터, 배열 각 원소들의 총 개수, 배열안에 원소의 하나의 크기, 비교 수행할 함수 포인터)
    qsort(points, 4, sizeof(Points), CompareX);

    //정렬된 배열을 가지고 최근접 점의 쌍의 거리 구하기
    double min_dist = ClosestPair(points, 4);

    //구한 결과 저장할 파일 열기
    fp = fopen("D:\CPresult.txt", "w");
    if (fp == NULL)
    {
        printf("CPresult 파일을 생성하는데 실패했습니다. \n");
        return 0;
    }
    else
        printf("CPresult 파일을 생성하는데 성공했습니다. \n");

    //result.txt파일에 결과값 저장
    fprintf(fp, "최근접 점 쌍의 거리는 %.2lf\n", min_dist);
}