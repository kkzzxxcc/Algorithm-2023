// 3월 13일 알고리즘 실습문제
// 동전찾기 함수 생성
// 입력 : 거스름돈
// 출력 : 동전 갯수 500원 n개, 100원 n개, 50원 n개, 10원 n개
// 함수 f( int Change(거스름돈) )
// 정수지정 struct Nconins { int n500;, int n100;, int n50;, int n10; };
// // C = 730(거스름돈 예시)
// 1. C/500 = 1...230 > R = C%500
// 2. R/100 = 2....30 > R = R%100
// 3. R/50  = 0    > R = R%50
// 4. R/10  = 3    > R = R%10

// struct Nconin calculcoins { struct Ncount ret; ............ return 0; }

 


#include <stdio.h>