// 3월 15일 데이터구조 수업(보강)
// 19학번 2학년 이동근
// 배열과 구조체
// 문자열

#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)

int main(void)
{

	char s1[60] = "C 언어는 ";
	char s2[60] = "좋은 프로그래밍 언어입니다.";
	char s3[60];
	char s[4][50];

	int length, i;

	length = strlen(s1);
	printf("String 길이는 %d \n", length);  // 쓰트링 길이는 14

	strcpy(s3, s1);
	printf("s3 = %s \n", s3); // s3 = C 언어는

	if (strcmp(s1, s3) == 0) // string compare
		printf("s1 은 s3과 같습니다 \n"); // s1은 s3와 같다

	else
		printf("s1은 s3와 같지 않습니다.\n");

	if (strcmp(s1, s2) == 0)
		printf("s1은 s2와 같습니다\n");

	else
		printf("s1과 s2는 같지 않습니다.\n"); // s1은 s2와 같지 않다.

	strcat(s1, s2);
	printf("s1 = %s \n", s1);

	for (i = 0; i < 4; i++) {
		printf("이름을 입력하세요 ");
		scanf("%s", s[i]);
	}

	for (i = 0; i < 4; i++) {
		printf("\n 이름은 %s ", s[i]);

	}


	return 0;
}