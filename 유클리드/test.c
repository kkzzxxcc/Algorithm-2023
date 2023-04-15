#pragma warning(disable:4996) // 비주얼 스튜디오에서 sacnf 오류 무시해주는 정의
// 유클리드 함수를 헤더파일에서 불러와서 테스트

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "euclid.h"

#define N 100000

int testEuclid()  // 재귀적 알고리즘으로 출력하는 최대공약수 알고리즘 함수
{

    int a, b;
    int gcd = 0;

	printf("안녕하세요. 테스트입니다. 재귀적 알고리즘으로 출력한 최대공약수 입니다. \n");

    // 두 수 입력
    printf("두 정수를 입력하세요: ");
    scanf("%d %d", &a, &b);

    // 재귀적 알고리즘으로 최대공약수 계산
    gcd = euclidRecursive(a, b);
    printf("재귀적 알고리즘으로 구한 최대공약수: %d\n", gcd);


	return 0;
}

int testEuclid_2()  // 반복적 알고리즘으로 출력하는 최대공약수 알고리즘 함수
{

    int a, b;
	int gcd_2 = 0;

	printf("안녕하세요 테스트2 입니다. 반복적 알고리즘으로 출력한 최대공약수 입니다.\n");

    // 두 수 입력
    printf("두 정수를 입력하세요: ");
    scanf("%d %d", &a, &b);

    // 반복적 알고리즘으로 최대공약수 계산
    gcd_2 = euclidRecursive(a, b);
    printf("반복적 알고리즘으로 구한 최대공약수: %d\n", gcd_2);

	return 0;
}

int check_time()
{
  
    int a[N], b[N];
    int i, gcd1, gcd2;
    double time1, time2;
    clock_t start, end;

    // N개의 테스트 케이스 생성
    srand((unsigned int)time(NULL));

    for (i = 0; i < N; i++) 
    {
        a[i] = rand();
        b[i] = rand();
    }

    // 재귀적 알고리즘의 실행시간 측정
    start = clock();
    for (i = 0; i < N; i++) 
    {
        gcd1 = euclidRecursive(a[i], b[i]);
    }
    end = clock();

    time1 = (double)(end - start) / CLOCKS_PER_SEC;

    // 반복적 알고리즘의 실행시간 측정
    start = clock();
    for (i = 0; i < N; i++) 
    {
        gcd2 = euclidRepeatitive(a[i], b[i]);
    }
    end = clock();

    time2 = (double)(end - start) / CLOCKS_PER_SEC;

    // 결과 출력
    if (gcd1 == gcd2)
        printf("재귀적 방법과 반복적 방법의 최대공약수 값이 같습니다\n"); // 값이 같아도 연산횟수가 다르면 다르다고 출력 될 때가 있음

    else
        printf("재귀적 방법과 반복적 방법의 최대공약수 값이 다릅니다\n");
   
    printf("재귀적 알고리즘의 실행시간: %.6f초\n", time1);
    printf("반복적 알고리즘의 실행시간: %.6f초\n", time2);

    return 0;
} 
