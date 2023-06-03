#define _CRT_SECURE_NO_WARNINGS  // 비주얼 스튜디오에서 sacnf 오류 무시해주는 정의
// UI

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

#define P 38
#define PP P+21
// ┫ ┃ ━ ┓ ┛ ┗ ┏ ┳ ┻ ┣ ╋
void gotoxy(int x, int y);
void main_UI();        // 메인 화면
void find_UI_1_1();    // 길찾기 메인화면
void find_UI_1_2();    // 출발지 도착지 입력하면 확인문
void find_UI_1_3();    // 입력한거 최종출력 출력
void admin_UI_2_1();   // 관리자 메인화면
void admin_UI_2_2();    // 지역추가 화면(작게 띄움)
void admin_UI_2_3();    // 지역삭제 화면(작게 띄움)
void record_UI_3_1();   // 최근기록 한번에 보여주는 화면
void bookmark_UI_4_1(); // 즐찾 메인화면
void bookmark_UI_4_2(); // 즐찾한 목록 출력하는 화면
void bookmark_UI_4_3(); // 즐찾 지역 추가 화면(작게 띄움)
void bookmark_UI_4_4(); // 즐찾 지역 삭제 화면(작게 띄움)

int main(void)
{
	
	main_UI();

	/*
	printf(" *******  ********* ********* *     **  **       **     *     ********  *     **   \n");
	printf(" *      * *       * *       * *   **    * *     * *    * *    *      *  *   **     \n");
	printf(" *******  *       * *       * * **      *  *   *  *   *****   *  ** *   * **       \n");
	printf(" *      * *       * *       * *   **    *   * *   *  *     *  *      *  *   **     \n");
	printf(" *******  ********* ********* *     **  *    *    * *       * *       * *     **   \n");
	*/
	
}

void gotoxy(int x, int y)
{
	COORD Pos = { x - 1, y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void main_UI()
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
	gotoxy(13, 3);
	printf("**      *     *    *       * ********* *********     *    ********* ********* ********* **      * \n");
	gotoxy(13, 4);
	printf("* *     *    * *    *     *      *     *            * *       *         *     *       * * *     * \n");
	gotoxy(13, 5);
	printf("*   *   *   *****    *   *       *     *   *****   *****      *         *     *       * *   *   * \n");
	gotoxy(13, 6);
	printf("*     * *  *     *    * *        *     *      **  *     *     *         *     *       * *     * * \n");
	gotoxy(13, 7);
	printf("*      ** *       *    *     ********* ********* *       *    *     ********* ********* *      ** \n");
	gotoxy(13, 8);



	gotoxy(10, 15);
	printf("1. 길찾기");
	gotoxy(10, 18);
	printf("2. 최근기록");
	gotoxy(10, 21);
	printf("3. 즐겨찾기");
	gotoxy(10, 24);
	printf("4. 종료");



	gotoxy(97, 29);
	printf("PG ver. B202305301752");


	gotoxy(3, 2);
	printf("UI MAIN: 1.0");
	gotoxy(2, 29);
	printf("원하시는 메뉴 번호를 입력하세요>>> ");
	_getch();

}

void find_UI_1_1()    // 길찾기 메인화면
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

	gotoxy(20, 3);
	printf("******** ********* **      * *******     ********  ********     *     *******  \n");
	gotoxy(20, 4);
	printf("*            *     * *     * *     **    *      *  *      *    * *    *     ** \n");
	gotoxy(20, 5);
	printf("*******      *     *   *   * *     **    *  ** *   *      *   *****   *     **  \n");
	gotoxy(20, 6);
	printf("*            *     *     * * *     **    *      *  *      *  *     *  *     **  \n");
	gotoxy(20, 7);
	printf("*        ********* *      ** *******     *       * ******** *       * *******   \n");
	gotoxy(20, 8);


	gotoxy(3, 2);
	printf("UI Find Road: 1.1");

	gotoxy(97, 29);
	printf("PG ver. B202305301752");

	gotoxy(10, 15);
	printf("1. 출발지를 입력하세요 >> ");
	_getch();

	gotoxy(10, 21);
	printf("2. 도착지를 입력하세요 >> ");
	_getch();

	gotoxy(2, 29);
	printf("다음 화면으로 가기 Enter ");
	_getch();

}

void find_UI_1_2()    // 출발지 도착지 입력하면 확인문
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

	gotoxy(20, 3);
	printf("******** ********* **      * *******     ********  ********     *     *******  \n");
	gotoxy(20, 4);
	printf("*            *     * *     * *     **    *      *  *      *    * *    *     ** \n");
	gotoxy(20, 5);
	printf("*******      *     *   *   * *     **    *  ** *   *      *   *****   *     **  \n");
	gotoxy(20, 6);
	printf("*            *     *     * * *     **    *      *  *      *  *     *  *     **  \n");
	gotoxy(20, 7);
	printf("*        ********* *      ** *******     *       * ******** *       * *******   \n");
	gotoxy(20, 8);


	gotoxy(3, 2);
	printf("UI Find Road: 1.1");

	gotoxy(97, 29);
	printf("PG ver. B202305301752");

	gotoxy(10, 15);
	printf("1. 출발지를 입력하세요 >> ");
	_getch();

	gotoxy(10, 21);
	printf("2. 도착지를 입력하세요 >> ");
	_getch();

	gotoxy(2, 29);
	printf("다음 화면으로 가기 Enter ");
	_getch();

	gotoxy(30, 11);
	for (i = 0; i < 60; i++)
	    printf("━");

	gotoxy(30, 25);
	for (i = 0; i < 60; i++)
		printf("━");

	gotoxy(30, 11);
	printf("┃\n");
	gotoxy(30, 12);
	printf("┃\n");
	gotoxy(30, 13);
	printf("┃\n");
	gotoxy(30, 14);
	printf("┃\n");
	gotoxy(30, 15);
	printf("┃\n");
	gotoxy(30, 16);
	printf("┃\n");
	gotoxy(30, 17);
	printf("┃\n");
	gotoxy(30, 18);
	printf("┃\n");
	gotoxy(30, 19);
	printf("┃\n");
	gotoxy(30, 20);
	printf("┃\n");
	gotoxy(30, 21);
	printf("┃\n");
	gotoxy(30, 22);
	printf("┃\n");
	gotoxy(30, 23);
	printf("┃\n");
	gotoxy(30, 24);
	printf("┃\n");

	gotoxy(90, 11);
	printf("┃\n");
	gotoxy(90, 12);
	printf("┃\n");
	gotoxy(90, 13);
	printf("┃\n");
	gotoxy(90, 14);
	printf("┃\n");
	gotoxy(90, 15);
	printf("┃\n");
	gotoxy(90, 16);
	printf("┃\n");
	gotoxy(90, 17);
	printf("┃\n");
	gotoxy(90, 18);
	printf("┃\n");
	gotoxy(90, 19);
	printf("┃\n");
	gotoxy(90, 20);
	printf("┃\n");
	gotoxy(90, 21);
	printf("┃\n");
	gotoxy(90, 22);
	printf("┃\n");
	gotoxy(90, 23);
	printf("┃\n");
	gotoxy(90, 24);
	printf("┃\n");
	

	

	gotoxy(30, 11);
	printf("┏");
	gotoxy(90, 11);
	printf("┓");
	gotoxy(30, 25);
	printf("┗");
	gotoxy(90, 25);
	printf("┛");

	gotoxy(42, 15);
	printf("1. 출발지 >> ### 확인되었습니다. ");

	gotoxy(42, 20);
	printf("2. 도착지 >> ### 확인되었습니다. ");

	gotoxy(31, 24);
	printf("다음으로 넘어가기 Enter ");
	_getch();

	
}

void find_UI_1_3()    // 입력한거 최종출력 출력
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

	gotoxy(20, 3);
	printf("******** ********* **      * *******     ********  ********     *     *******  \n");
	gotoxy(20, 4);
	printf("*            *     * *     * *     **    *      *  *      *    * *    *     ** \n");
	gotoxy(20, 5);
	printf("*******      *     *   *   * *     **    *  ** *   *      *   *****   *     **  \n");
	gotoxy(20, 6);
	printf("*            *     *     * * *     **    *      *  *      *  *     *  *     **  \n");
	gotoxy(20, 7);
	printf("*        ********* *      ** *******     *       * ******** *       * *******   \n");
	gotoxy(20, 8);


	gotoxy(3, 2);
	printf("UI Find Road: 1.3");

	gotoxy(97, 29);
	printf("PG ver. B202305301752");

	gotoxy(10, 12);
	printf("1. 출발지 >> ### ");

	gotoxy(10, 16);
	printf("2. 도착지 >> ### ");

	gotoxy(10, 20);
	printf("3. 경로   >> ### ");

	gotoxy(10, 24);
	printf("4. 도착 예정 시간  >> ### ");

	gotoxy(2, 29);
	printf("다음 화면으로 가기 Enter ");
	_getch();
}

void admin_UI_2_1()   // 관리자 메인화면
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
	gotoxy(30, 3);
	printf("     *      *******   **       **  *********  **      * \n");
	gotoxy(30, 4);
	printf("    * *     *     **  * *     * *      *      * *     * \n");
	gotoxy(30, 5);
	printf("   *****    *     **  *  *   *  *      *      *   *   * \n");
	gotoxy(30, 6);
	printf("  *     *   *     **  *   * *   *      *      *     * * \n");
	gotoxy(30, 7);
	printf(" *       *  *******   *    *    *  *********  *      ** \n");
	gotoxy(30, 8);



	gotoxy(10, 15);
	printf("1. 지역 추가 >> ");
	gotoxy(10, 21);
	printf("2. 지역 삭제 >> ");
	


	gotoxy(97, 29);
	printf("PG ver. B202305301752");


	gotoxy(3, 2);
	printf("UI ADMIN: 2.1");
	gotoxy(2, 29);
	printf("원하시는 메뉴 번호를 입력하세요>>> ");
	_getch();
}

void admin_UI_2_2()   // 지역추가 화면(작게 띄움)
{
	int i;

	gotoxy(30, 11);
	for (i = 0; i < 60; i++)
		printf("━");

	gotoxy(30, 25);
	for (i = 0; i < 60; i++)
		printf("━");

	gotoxy(30, 11);
	printf("┃\n");
	gotoxy(30, 12);
	printf("┃\n");
	gotoxy(30, 13);
	printf("┃\n");
	gotoxy(30, 14);
	printf("┃\n");
	gotoxy(30, 15);
	printf("┃\n");
	gotoxy(30, 16);
	printf("┃\n");
	gotoxy(30, 17);
	printf("┃\n");
	gotoxy(30, 18);
	printf("┃\n");
	gotoxy(30, 19);
	printf("┃\n");
	gotoxy(30, 20);
	printf("┃\n");
	gotoxy(30, 21);
	printf("┃\n");
	gotoxy(30, 22);
	printf("┃\n");
	gotoxy(30, 23);
	printf("┃\n");
	gotoxy(30, 24);
	printf("┃\n");

	gotoxy(90, 11);
	printf("┃\n");
	gotoxy(90, 12);
	printf("┃\n");
	gotoxy(90, 13);
	printf("┃\n");
	gotoxy(90, 14);
	printf("┃\n");
	gotoxy(90, 15);
	printf("┃\n");
	gotoxy(90, 16);
	printf("┃\n");
	gotoxy(90, 17);
	printf("┃\n");
	gotoxy(90, 18);
	printf("┃\n");
	gotoxy(90, 19);
	printf("┃\n");
	gotoxy(90, 20);
	printf("┃\n");
	gotoxy(90, 21);
	printf("┃\n");
	gotoxy(90, 22);
	printf("┃\n");
	gotoxy(90, 23);
	printf("┃\n");
	gotoxy(90, 24);
	printf("┃\n");




	gotoxy(30, 11);
	printf("┏");
	gotoxy(90, 11);
	printf("┓");
	gotoxy(30, 25);
	printf("┗");
	gotoxy(90, 25);
	printf("┛");

	gotoxy(42, 15);
	printf("추가할 지역을 입력하십시오 >>  ");
	_getch();

	gotoxy(42, 20);
	printf("### 지역을 추가하였습니다. ");

	gotoxy(31, 24);
	printf("다음으로 넘어가기 Enter ");
	_getch();
}

void admin_UI_2_3()    // 지역삭제 화면(작게 띄움)
{
	int i;

	gotoxy(30, 11);
	for (i = 0; i < 60; i++)
		printf("━");

	gotoxy(30, 25);
	for (i = 0; i < 60; i++)
		printf("━");

	gotoxy(30, 11);
	printf("┃\n");
	gotoxy(30, 12);
	printf("┃\n");
	gotoxy(30, 13);
	printf("┃\n");
	gotoxy(30, 14);
	printf("┃\n");
	gotoxy(30, 15);
	printf("┃\n");
	gotoxy(30, 16);
	printf("┃\n");
	gotoxy(30, 17);
	printf("┃\n");
	gotoxy(30, 18);
	printf("┃\n");
	gotoxy(30, 19);
	printf("┃\n");
	gotoxy(30, 20);
	printf("┃\n");
	gotoxy(30, 21);
	printf("┃\n");
	gotoxy(30, 22);
	printf("┃\n");
	gotoxy(30, 23);
	printf("┃\n");
	gotoxy(30, 24);
	printf("┃\n");

	gotoxy(90, 11);
	printf("┃\n");
	gotoxy(90, 12);
	printf("┃\n");
	gotoxy(90, 13);
	printf("┃\n");
	gotoxy(90, 14);
	printf("┃\n");
	gotoxy(90, 15);
	printf("┃\n");
	gotoxy(90, 16);
	printf("┃\n");
	gotoxy(90, 17);
	printf("┃\n");
	gotoxy(90, 18);
	printf("┃\n");
	gotoxy(90, 19);
	printf("┃\n");
	gotoxy(90, 20);
	printf("┃\n");
	gotoxy(90, 21);
	printf("┃\n");
	gotoxy(90, 22);
	printf("┃\n");
	gotoxy(90, 23);
	printf("┃\n");
	gotoxy(90, 24);
	printf("┃\n");




	gotoxy(30, 11);
	printf("┏");
	gotoxy(90, 11);
	printf("┓");
	gotoxy(30, 25);
	printf("┗");
	gotoxy(90, 25);
	printf("┛");

	gotoxy(42, 15);
	printf("삭제할 지역을 입력하십시오 >>  ");
	_getch();

	gotoxy(42, 20);
	printf("### 지역을 삭제하였습니다. ");

	gotoxy(31, 24);
	printf("다음으로 넘어가기 Enter ");
	_getch();
}

void record_UI_3_1()   // 최근기록 한번에 보여주는 화면
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
	gotoxy(29, 3);
	printf(" ********  ********* ********* ********* ********  *******   \n");
	gotoxy(29, 4);
	printf(" *      *  *         *         *       * *      *  *     **   \n");
	gotoxy(29, 5);
	printf(" *  ** *   ********  *         *       * *  ** *   *     **  \n");
	gotoxy(29, 6);
	printf(" *      *  *         *         *       * *      *  *     **  \n");
	gotoxy(29, 7);
	printf(" *       * ********* ********* ********* *       * *******   \n");


	gotoxy(10, 10);
	printf("최근 검색 기록 >> ");


	gotoxy(97, 29);
	printf("PG ver. B202305301752");


	gotoxy(3, 2);
	printf("UI RC_RECORD: 3.1");
	gotoxy(2, 29);
	_getch();
}

void bookmark_UI_4_1() // 즐찾 메인화면
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
	gotoxy(20, 3);
	printf(" *******  ******** ******** *     **  **       **     *     ********  *     **   \n");
	gotoxy(20, 4);
	printf(" *      * *      * *      * *   **    * *     * *    * *    *      *  *   **     \n");
	gotoxy(20, 5);
	printf(" *******  *      * *      * * **      *  *   *  *   *****   *  ** *   * **       \n");
	gotoxy(20, 6);
	printf(" *      * *      * *      * *   **    *   * *   *  *     *  *      *  *   **     \n");
	gotoxy(20, 7);
	printf(" *******  ******** ******** *     **  *    *    * *       * *       * *     **   \n");
	gotoxy(20, 8);



	gotoxy(10, 13);
	printf("1. 즐겨찾기 조회 ");
	gotoxy(10, 18);
	printf("2. 즐겨찾기 추가");
	gotoxy(10, 23);
	printf("3. 즐겨찾기 삭제");


	gotoxy(97, 29);
	printf("PG ver. B202305301752");


	gotoxy(3, 2);
	printf("UI BOOKMARK: 4.1");
	gotoxy(2, 29);
	printf("원하시는 메뉴 번호를 입력하세요>>> ");
	_getch();

}

void bookmark_UI_4_2() // 즐찾한 목록 출력하는 화면
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
	gotoxy(20, 3);
	printf(" *******  ******** ******** *     **  **       **     *     ********  *     **   \n");
	gotoxy(20, 4);
	printf(" *      * *      * *      * *   **    * *     * *    * *    *      *  *   **     \n");
	gotoxy(20, 5);
	printf(" *******  *      * *      * * **      *  *   *  *   *****   *  ** *   * **       \n");
	gotoxy(20, 6);
	printf(" *      * *      * *      * *   **    *   * *   *  *     *  *      *  *   **     \n");
	gotoxy(20, 7);
	printf(" *******  ******** ******** *     **  *    *    * *       * *       * *     **   \n");
	gotoxy(20, 8);



	gotoxy(10, 10);
	printf(" 즐겨찾기 목록 >> ");


	gotoxy(97, 29);
	printf("PG ver. B202305301752");


	gotoxy(3, 2);
	printf("UI BOOKMARK: 4.2");
	gotoxy(2, 29);
	printf("원하시는 메뉴 번호를 입력하세요>>> ");
	_getch();
}

void bookmark_UI_4_3() // 즐찾 지역 추가 화면(작게 띄움)
{
	int i;

	gotoxy(30, 11);
	for (i = 0; i < 60; i++)
		printf("━");

	gotoxy(30, 25);
	for (i = 0; i < 60; i++)
		printf("━");

	gotoxy(30, 11);
	printf("┃\n");
	gotoxy(30, 12);
	printf("┃\n");
	gotoxy(30, 13);
	printf("┃\n");
	gotoxy(30, 14);
	printf("┃\n");
	gotoxy(30, 15);
	printf("┃\n");
	gotoxy(30, 16);
	printf("┃\n");
	gotoxy(30, 17);
	printf("┃\n");
	gotoxy(30, 18);
	printf("┃\n");
	gotoxy(30, 19);
	printf("┃\n");
	gotoxy(30, 20);
	printf("┃\n");
	gotoxy(30, 21);
	printf("┃\n");
	gotoxy(30, 22);
	printf("┃\n");
	gotoxy(30, 23);
	printf("┃\n");
	gotoxy(30, 24);
	printf("┃\n");

	gotoxy(90, 11);
	printf("┃\n");
	gotoxy(90, 12);
	printf("┃\n");
	gotoxy(90, 13);
	printf("┃\n");
	gotoxy(90, 14);
	printf("┃\n");
	gotoxy(90, 15);
	printf("┃\n");
	gotoxy(90, 16);
	printf("┃\n");
	gotoxy(90, 17);
	printf("┃\n");
	gotoxy(90, 18);
	printf("┃\n");
	gotoxy(90, 19);
	printf("┃\n");
	gotoxy(90, 20);
	printf("┃\n");
	gotoxy(90, 21);
	printf("┃\n");
	gotoxy(90, 22);
	printf("┃\n");
	gotoxy(90, 23);
	printf("┃\n");
	gotoxy(90, 24);
	printf("┃\n");




	gotoxy(30, 11);
	printf("┏");
	gotoxy(90, 11);
	printf("┓");
	gotoxy(30, 25);
	printf("┗");
	gotoxy(90, 25);
	printf("┛");

	gotoxy(38, 15);
	printf("즐겨찾기에 추가할 지역을 입력하십시오 >>  ");
	_getch();

	gotoxy(38, 20);
	printf("즐겨찾기에 ### 지역을 추가하였습니다. ");

	gotoxy(31, 24);
	printf("다음으로 넘어가기 Enter ");
	_getch();
}

void bookmark_UI_4_4() // 즐찾 지역 삭제 화면(작게 띄움)
{
	int i;

	gotoxy(30, 11);
	for (i = 0; i < 60; i++)
		printf("━");

	gotoxy(30, 25);
	for (i = 0; i < 60; i++)
		printf("━");

	gotoxy(30, 11);
	printf("┃\n");
	gotoxy(30, 12);
	printf("┃\n");
	gotoxy(30, 13);
	printf("┃\n");
	gotoxy(30, 14);
	printf("┃\n");
	gotoxy(30, 15);
	printf("┃\n");
	gotoxy(30, 16);
	printf("┃\n");
	gotoxy(30, 17);
	printf("┃\n");
	gotoxy(30, 18);
	printf("┃\n");
	gotoxy(30, 19);
	printf("┃\n");
	gotoxy(30, 20);
	printf("┃\n");
	gotoxy(30, 21);
	printf("┃\n");
	gotoxy(30, 22);
	printf("┃\n");
	gotoxy(30, 23);
	printf("┃\n");
	gotoxy(30, 24);
	printf("┃\n");

	gotoxy(90, 11);
	printf("┃\n");
	gotoxy(90, 12);
	printf("┃\n");
	gotoxy(90, 13);
	printf("┃\n");
	gotoxy(90, 14);
	printf("┃\n");
	gotoxy(90, 15);
	printf("┃\n");
	gotoxy(90, 16);
	printf("┃\n");
	gotoxy(90, 17);
	printf("┃\n");
	gotoxy(90, 18);
	printf("┃\n");
	gotoxy(90, 19);
	printf("┃\n");
	gotoxy(90, 20);
	printf("┃\n");
	gotoxy(90, 21);
	printf("┃\n");
	gotoxy(90, 22);
	printf("┃\n");
	gotoxy(90, 23);
	printf("┃\n");
	gotoxy(90, 24);
	printf("┃\n");




	gotoxy(30, 11);
	printf("┏");
	gotoxy(90, 11);
	printf("┓");
	gotoxy(30, 25);
	printf("┗");
	gotoxy(90, 25);
	printf("┛");

	gotoxy(38, 15);
	printf("즐겨찾기에서 삭제할 지역을 입력하십시오 >>  ");
	_getch();

	gotoxy(38, 20);
	printf("즐겨찾기에서 ### 지역을 삭제하였습니다. ");

	gotoxy(31, 24);
	printf("다음으로 넘어가기 Enter ");
	_getch();
}