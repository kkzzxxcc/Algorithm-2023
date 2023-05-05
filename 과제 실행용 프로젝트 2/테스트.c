#pragma warning(disable:4996) // 비주얼 스튜디오에서 sacnf 오류 무시해주는 정의
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h> 
int main(void)
{
	FILE* fp = NULL;
	fp = fopen("sample.txt", "w");
	if (fp == NULL)
		printf("파일 열기 실패\n");
	else
		printf("파일 열기 성공\n");
	fclose(fp);
	return 0; 
}