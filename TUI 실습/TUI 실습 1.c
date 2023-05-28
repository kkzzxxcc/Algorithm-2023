#define _CRT_SECURE_NO_WARNINGS  // 비주얼 스튜디오에서 sacnf 오류 무시해주는 정의
// 알고리즘 송해상 교수님
// 20191179 이동근
// TUI 실습
// 5월 23일 알고리즘

#include <stdio.h>
#include <conio.h>
#include <Windows.h>

void gotoxy(int x, int y);

int main(void)
{
	system("cls");

	gotoxy(4, 4);

	putchar('A');

	gotoxy(1, 1);

	printf("□"); //유티코드 : HWP 특수문자 Ctrl+F10 하여 문자표에서 붙여넣기

	return 0;
}

void gotoxy(int x, int y)
{
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}