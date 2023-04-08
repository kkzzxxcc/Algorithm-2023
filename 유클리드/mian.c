// 프로그램을 실행하는 메인 함수

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "euclid.h"


int testEuclid();     // 재귀적 알고리즘 함수
int testEuclid_2();   // 반복적 알고리즘 함수


int main(void)
{
	int ret = 0;      // 재귀적 알고리즘 결과값
	int ret_2 = 0;    // 반복적 알고리즘 결과값
	int ret_3 = 0;    // 두 알고리즘의 실행시간 결과값

	printf("Hello World\n");

	ret = testEuclid();
	ret_2 = testEuclid_2();
	ret_3 = check_time();

    return 0;
}
	
