#define _CRT_SECURE_NO_WARNINGS  // ���־� ��Ʃ������� sacnf ���� �������ִ� ����
// �˰��� ���ػ� ������
// 20191179 �̵���
// TUI �ǽ�
// 5�� 23�� �˰���

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

	printf("��"); //��Ƽ�ڵ� : HWP Ư������ Ctrl+F10 �Ͽ� ����ǥ���� �ٿ��ֱ�

	return 0;
}

void gotoxy(int x, int y)
{
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}