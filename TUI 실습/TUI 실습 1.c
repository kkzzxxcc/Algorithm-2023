#define _CRT_SECURE_NO_WARNINGS  // 비주얼 스튜디오에서 sacnf 오류 무시해주는 정의
// 알고리즘 송해상 교수님
// 20191179 이동근
// TUI 실습
// 5월 23일 알고리즘

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

#define P 38
#define PP P+21
// ┫ ┃ ━ ┓ ┛ ┗ ┏ ┳ ┻ ┣ ╋

void gotoxy(int x, int y);

int main(void)
{
	int i;

	for (i = 0; i < 120; i++)
		printf("━");
	for (i = 0; i < 28; i++)
		printf("┃\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t┃\n");
	for (i = 0; i < 120; i++)
		printf("━");
	gotoxy(1, 8);
	for (i = 0; i < 120; i++)
		printf("━");

	gotoxy(1, 1);
	printf("┏");
	gotoxy(120, 1);
	printf("┓");
	gotoxy(1, 8);
	printf("┣");
	gotoxy(120, 8);
	printf("┫");
	gotoxy(1, 30);
	printf("┗");
	gotoxy(120, 30);
	printf("┛");

	// ㄴ
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
	printf("1. 길찾기");
	gotoxy(10, 18);
	printf("2. 최근기록");
	gotoxy(10, 21);
	printf("3. 즐겨찾기");
	gotoxy(10, 24);
	printf("4. 종료");



	gotoxy(90, 29);
	printf("PG ver. B202305301752");


	gotoxy(3, 2);
	printf("UI S/N: U 0.1");
	gotoxy(2, 29);
	printf("원하시는 메뉴 번호를 입력하세요>>> ");
	_getch();

	return 0;
}

void gotoxy(int x, int y)
{
	COORD Pos = { x - 1, y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}