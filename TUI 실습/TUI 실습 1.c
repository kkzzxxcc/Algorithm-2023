#define _CRT_SECURE_NO_WARNINGS  // ���־� ��Ʃ������� sacnf ���� �������ִ� ����
// �˰��� ���ػ� ������
// 20191179 �̵���
// TUI �ǽ�
// 5�� 23�� �˰���

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

#define P 38
#define PP P+21
// �� �� �� �� �� �� �� �� �� �� ��

void gotoxy(int x, int y);

int main(void)
{
	int i;

	for (i = 0; i < 120; i++)
		printf("��");
	for (i = 0; i < 28; i++)
		printf("��\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t��\n");
	for (i = 0; i < 120; i++)
		printf("��");
	gotoxy(1, 8);
	for (i = 0; i < 120; i++)
		printf("��");

	gotoxy(1, 1);
	printf("��");
	gotoxy(120, 1);
	printf("��");
	gotoxy(1, 8);
	printf("��");
	gotoxy(120, 8);
	printf("��");
	gotoxy(1, 30);
	printf("��");
	gotoxy(120, 30);
	printf("��");

	// ��
	gotoxy(12, 3);
	printf("**      *  *       *  *********  *********      *      *********  *********  *********  **      * \n");
	gotoxy(12, 4);
	printf("* *     *   *     *       *      *             * *         *          *      *       *  * *     * \n");
	gotoxy(12, 5);
	printf("*   *   *    *   *        *      *   *****    *****        *          *      *       *  *   *   * \n");
	gotoxy(12, 6);
	printf("*     * *     * *         *      *      **   *     *       *          *      *       *  *     * * \n");
	gotoxy(12, 7);
	printf("*      **      *      *********  *********  *       *      *      *********  *********  *      ** \n");
	gotoxy(12, 8);
	


	gotoxy(10, 15);
	printf("1. ��ã��");
	gotoxy(10, 18);
	printf("2. �ֱٱ��");
	gotoxy(10, 21);
	printf("3. ���ã��");
	gotoxy(10, 24);
	printf("4. ����");



	gotoxy(90, 29);
	printf("PG ver. B202305301752");


	gotoxy(3, 2);
	printf("UI S/N: U 0.1");
	gotoxy(2, 29);
	printf("���Ͻô� �޴� ��ȣ�� �Է��ϼ���>>> ");
	_getch();

	return 0;
}

void gotoxy(int x, int y)
{
	COORD Pos = { x - 1, y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}