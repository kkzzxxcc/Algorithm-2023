#define _CRT_SECURE_NO_WARNINGS  // ���־� ��Ʃ������� sacnf ���� �������ִ� ����
// UI

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

#define P 38
#define PP P+21
// �� �� �� �� �� �� �� �� �� �� ��
void gotoxy(int x, int y);
void main_UI();        // ���� ȭ��
void find_UI_1_1();    // ��ã�� ����ȭ��
void find_UI_1_2();    // ����� ������ �Է��ϸ� Ȯ�ι�
void find_UI_1_3();    // �Է��Ѱ� ������� ���
void admin_UI_2_1();   // ������ ����ȭ��
void admin_UI_2_2();    // �����߰� ȭ��(�۰� ���)
void admin_UI_2_3();    // �������� ȭ��(�۰� ���)
void record_UI_3_1();   // �ֱٱ�� �ѹ��� �����ִ� ȭ��
void bookmark_UI_4_1(); // ��ã ����ȭ��
void bookmark_UI_4_2(); // ��ã�� ��� ����ϴ� ȭ��
void bookmark_UI_4_3(); // ��ã ���� �߰� ȭ��(�۰� ���)
void bookmark_UI_4_4(); // ��ã ���� ���� ȭ��(�۰� ���)

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
	printf("1. ��ã��");
	gotoxy(10, 18);
	printf("2. �ֱٱ��");
	gotoxy(10, 21);
	printf("3. ���ã��");
	gotoxy(10, 24);
	printf("4. ����");



	gotoxy(97, 29);
	printf("PG ver. B202305301752");


	gotoxy(3, 2);
	printf("UI MAIN: 1.0");
	gotoxy(2, 29);
	printf("���Ͻô� �޴� ��ȣ�� �Է��ϼ���>>> ");
	_getch();

}

void find_UI_1_1()    // ��ã�� ����ȭ��
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
	printf("1. ������� �Է��ϼ��� >> ");
	_getch();

	gotoxy(10, 21);
	printf("2. �������� �Է��ϼ��� >> ");
	_getch();

	gotoxy(2, 29);
	printf("���� ȭ������ ���� Enter ");
	_getch();

}

void find_UI_1_2()    // ����� ������ �Է��ϸ� Ȯ�ι�
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
	printf("1. ������� �Է��ϼ��� >> ");
	_getch();

	gotoxy(10, 21);
	printf("2. �������� �Է��ϼ��� >> ");
	_getch();

	gotoxy(2, 29);
	printf("���� ȭ������ ���� Enter ");
	_getch();

	gotoxy(30, 11);
	for (i = 0; i < 60; i++)
	    printf("��");

	gotoxy(30, 25);
	for (i = 0; i < 60; i++)
		printf("��");

	gotoxy(30, 11);
	printf("��\n");
	gotoxy(30, 12);
	printf("��\n");
	gotoxy(30, 13);
	printf("��\n");
	gotoxy(30, 14);
	printf("��\n");
	gotoxy(30, 15);
	printf("��\n");
	gotoxy(30, 16);
	printf("��\n");
	gotoxy(30, 17);
	printf("��\n");
	gotoxy(30, 18);
	printf("��\n");
	gotoxy(30, 19);
	printf("��\n");
	gotoxy(30, 20);
	printf("��\n");
	gotoxy(30, 21);
	printf("��\n");
	gotoxy(30, 22);
	printf("��\n");
	gotoxy(30, 23);
	printf("��\n");
	gotoxy(30, 24);
	printf("��\n");

	gotoxy(90, 11);
	printf("��\n");
	gotoxy(90, 12);
	printf("��\n");
	gotoxy(90, 13);
	printf("��\n");
	gotoxy(90, 14);
	printf("��\n");
	gotoxy(90, 15);
	printf("��\n");
	gotoxy(90, 16);
	printf("��\n");
	gotoxy(90, 17);
	printf("��\n");
	gotoxy(90, 18);
	printf("��\n");
	gotoxy(90, 19);
	printf("��\n");
	gotoxy(90, 20);
	printf("��\n");
	gotoxy(90, 21);
	printf("��\n");
	gotoxy(90, 22);
	printf("��\n");
	gotoxy(90, 23);
	printf("��\n");
	gotoxy(90, 24);
	printf("��\n");
	

	

	gotoxy(30, 11);
	printf("��");
	gotoxy(90, 11);
	printf("��");
	gotoxy(30, 25);
	printf("��");
	gotoxy(90, 25);
	printf("��");

	gotoxy(42, 15);
	printf("1. ����� >> ### Ȯ�εǾ����ϴ�. ");

	gotoxy(42, 20);
	printf("2. ������ >> ### Ȯ�εǾ����ϴ�. ");

	gotoxy(31, 24);
	printf("�������� �Ѿ�� Enter ");
	_getch();

	
}

void find_UI_1_3()    // �Է��Ѱ� ������� ���
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
	printf("1. ����� >> ### ");

	gotoxy(10, 16);
	printf("2. ������ >> ### ");

	gotoxy(10, 20);
	printf("3. ���   >> ### ");

	gotoxy(10, 24);
	printf("4. ���� ���� �ð�  >> ### ");

	gotoxy(2, 29);
	printf("���� ȭ������ ���� Enter ");
	_getch();
}

void admin_UI_2_1()   // ������ ����ȭ��
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
	printf("1. ���� �߰� >> ");
	gotoxy(10, 21);
	printf("2. ���� ���� >> ");
	


	gotoxy(97, 29);
	printf("PG ver. B202305301752");


	gotoxy(3, 2);
	printf("UI ADMIN: 2.1");
	gotoxy(2, 29);
	printf("���Ͻô� �޴� ��ȣ�� �Է��ϼ���>>> ");
	_getch();
}

void admin_UI_2_2()   // �����߰� ȭ��(�۰� ���)
{
	int i;

	gotoxy(30, 11);
	for (i = 0; i < 60; i++)
		printf("��");

	gotoxy(30, 25);
	for (i = 0; i < 60; i++)
		printf("��");

	gotoxy(30, 11);
	printf("��\n");
	gotoxy(30, 12);
	printf("��\n");
	gotoxy(30, 13);
	printf("��\n");
	gotoxy(30, 14);
	printf("��\n");
	gotoxy(30, 15);
	printf("��\n");
	gotoxy(30, 16);
	printf("��\n");
	gotoxy(30, 17);
	printf("��\n");
	gotoxy(30, 18);
	printf("��\n");
	gotoxy(30, 19);
	printf("��\n");
	gotoxy(30, 20);
	printf("��\n");
	gotoxy(30, 21);
	printf("��\n");
	gotoxy(30, 22);
	printf("��\n");
	gotoxy(30, 23);
	printf("��\n");
	gotoxy(30, 24);
	printf("��\n");

	gotoxy(90, 11);
	printf("��\n");
	gotoxy(90, 12);
	printf("��\n");
	gotoxy(90, 13);
	printf("��\n");
	gotoxy(90, 14);
	printf("��\n");
	gotoxy(90, 15);
	printf("��\n");
	gotoxy(90, 16);
	printf("��\n");
	gotoxy(90, 17);
	printf("��\n");
	gotoxy(90, 18);
	printf("��\n");
	gotoxy(90, 19);
	printf("��\n");
	gotoxy(90, 20);
	printf("��\n");
	gotoxy(90, 21);
	printf("��\n");
	gotoxy(90, 22);
	printf("��\n");
	gotoxy(90, 23);
	printf("��\n");
	gotoxy(90, 24);
	printf("��\n");




	gotoxy(30, 11);
	printf("��");
	gotoxy(90, 11);
	printf("��");
	gotoxy(30, 25);
	printf("��");
	gotoxy(90, 25);
	printf("��");

	gotoxy(42, 15);
	printf("�߰��� ������ �Է��Ͻʽÿ� >>  ");
	_getch();

	gotoxy(42, 20);
	printf("### ������ �߰��Ͽ����ϴ�. ");

	gotoxy(31, 24);
	printf("�������� �Ѿ�� Enter ");
	_getch();
}

void admin_UI_2_3()    // �������� ȭ��(�۰� ���)
{
	int i;

	gotoxy(30, 11);
	for (i = 0; i < 60; i++)
		printf("��");

	gotoxy(30, 25);
	for (i = 0; i < 60; i++)
		printf("��");

	gotoxy(30, 11);
	printf("��\n");
	gotoxy(30, 12);
	printf("��\n");
	gotoxy(30, 13);
	printf("��\n");
	gotoxy(30, 14);
	printf("��\n");
	gotoxy(30, 15);
	printf("��\n");
	gotoxy(30, 16);
	printf("��\n");
	gotoxy(30, 17);
	printf("��\n");
	gotoxy(30, 18);
	printf("��\n");
	gotoxy(30, 19);
	printf("��\n");
	gotoxy(30, 20);
	printf("��\n");
	gotoxy(30, 21);
	printf("��\n");
	gotoxy(30, 22);
	printf("��\n");
	gotoxy(30, 23);
	printf("��\n");
	gotoxy(30, 24);
	printf("��\n");

	gotoxy(90, 11);
	printf("��\n");
	gotoxy(90, 12);
	printf("��\n");
	gotoxy(90, 13);
	printf("��\n");
	gotoxy(90, 14);
	printf("��\n");
	gotoxy(90, 15);
	printf("��\n");
	gotoxy(90, 16);
	printf("��\n");
	gotoxy(90, 17);
	printf("��\n");
	gotoxy(90, 18);
	printf("��\n");
	gotoxy(90, 19);
	printf("��\n");
	gotoxy(90, 20);
	printf("��\n");
	gotoxy(90, 21);
	printf("��\n");
	gotoxy(90, 22);
	printf("��\n");
	gotoxy(90, 23);
	printf("��\n");
	gotoxy(90, 24);
	printf("��\n");




	gotoxy(30, 11);
	printf("��");
	gotoxy(90, 11);
	printf("��");
	gotoxy(30, 25);
	printf("��");
	gotoxy(90, 25);
	printf("��");

	gotoxy(42, 15);
	printf("������ ������ �Է��Ͻʽÿ� >>  ");
	_getch();

	gotoxy(42, 20);
	printf("### ������ �����Ͽ����ϴ�. ");

	gotoxy(31, 24);
	printf("�������� �Ѿ�� Enter ");
	_getch();
}

void record_UI_3_1()   // �ֱٱ�� �ѹ��� �����ִ� ȭ��
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
	printf("�ֱ� �˻� ��� >> ");


	gotoxy(97, 29);
	printf("PG ver. B202305301752");


	gotoxy(3, 2);
	printf("UI RC_RECORD: 3.1");
	gotoxy(2, 29);
	_getch();
}

void bookmark_UI_4_1() // ��ã ����ȭ��
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
	printf("1. ���ã�� ��ȸ ");
	gotoxy(10, 18);
	printf("2. ���ã�� �߰�");
	gotoxy(10, 23);
	printf("3. ���ã�� ����");


	gotoxy(97, 29);
	printf("PG ver. B202305301752");


	gotoxy(3, 2);
	printf("UI BOOKMARK: 4.1");
	gotoxy(2, 29);
	printf("���Ͻô� �޴� ��ȣ�� �Է��ϼ���>>> ");
	_getch();

}

void bookmark_UI_4_2() // ��ã�� ��� ����ϴ� ȭ��
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
	printf(" ���ã�� ��� >> ");


	gotoxy(97, 29);
	printf("PG ver. B202305301752");


	gotoxy(3, 2);
	printf("UI BOOKMARK: 4.2");
	gotoxy(2, 29);
	printf("���Ͻô� �޴� ��ȣ�� �Է��ϼ���>>> ");
	_getch();
}

void bookmark_UI_4_3() // ��ã ���� �߰� ȭ��(�۰� ���)
{
	int i;

	gotoxy(30, 11);
	for (i = 0; i < 60; i++)
		printf("��");

	gotoxy(30, 25);
	for (i = 0; i < 60; i++)
		printf("��");

	gotoxy(30, 11);
	printf("��\n");
	gotoxy(30, 12);
	printf("��\n");
	gotoxy(30, 13);
	printf("��\n");
	gotoxy(30, 14);
	printf("��\n");
	gotoxy(30, 15);
	printf("��\n");
	gotoxy(30, 16);
	printf("��\n");
	gotoxy(30, 17);
	printf("��\n");
	gotoxy(30, 18);
	printf("��\n");
	gotoxy(30, 19);
	printf("��\n");
	gotoxy(30, 20);
	printf("��\n");
	gotoxy(30, 21);
	printf("��\n");
	gotoxy(30, 22);
	printf("��\n");
	gotoxy(30, 23);
	printf("��\n");
	gotoxy(30, 24);
	printf("��\n");

	gotoxy(90, 11);
	printf("��\n");
	gotoxy(90, 12);
	printf("��\n");
	gotoxy(90, 13);
	printf("��\n");
	gotoxy(90, 14);
	printf("��\n");
	gotoxy(90, 15);
	printf("��\n");
	gotoxy(90, 16);
	printf("��\n");
	gotoxy(90, 17);
	printf("��\n");
	gotoxy(90, 18);
	printf("��\n");
	gotoxy(90, 19);
	printf("��\n");
	gotoxy(90, 20);
	printf("��\n");
	gotoxy(90, 21);
	printf("��\n");
	gotoxy(90, 22);
	printf("��\n");
	gotoxy(90, 23);
	printf("��\n");
	gotoxy(90, 24);
	printf("��\n");




	gotoxy(30, 11);
	printf("��");
	gotoxy(90, 11);
	printf("��");
	gotoxy(30, 25);
	printf("��");
	gotoxy(90, 25);
	printf("��");

	gotoxy(38, 15);
	printf("���ã�⿡ �߰��� ������ �Է��Ͻʽÿ� >>  ");
	_getch();

	gotoxy(38, 20);
	printf("���ã�⿡ ### ������ �߰��Ͽ����ϴ�. ");

	gotoxy(31, 24);
	printf("�������� �Ѿ�� Enter ");
	_getch();
}

void bookmark_UI_4_4() // ��ã ���� ���� ȭ��(�۰� ���)
{
	int i;

	gotoxy(30, 11);
	for (i = 0; i < 60; i++)
		printf("��");

	gotoxy(30, 25);
	for (i = 0; i < 60; i++)
		printf("��");

	gotoxy(30, 11);
	printf("��\n");
	gotoxy(30, 12);
	printf("��\n");
	gotoxy(30, 13);
	printf("��\n");
	gotoxy(30, 14);
	printf("��\n");
	gotoxy(30, 15);
	printf("��\n");
	gotoxy(30, 16);
	printf("��\n");
	gotoxy(30, 17);
	printf("��\n");
	gotoxy(30, 18);
	printf("��\n");
	gotoxy(30, 19);
	printf("��\n");
	gotoxy(30, 20);
	printf("��\n");
	gotoxy(30, 21);
	printf("��\n");
	gotoxy(30, 22);
	printf("��\n");
	gotoxy(30, 23);
	printf("��\n");
	gotoxy(30, 24);
	printf("��\n");

	gotoxy(90, 11);
	printf("��\n");
	gotoxy(90, 12);
	printf("��\n");
	gotoxy(90, 13);
	printf("��\n");
	gotoxy(90, 14);
	printf("��\n");
	gotoxy(90, 15);
	printf("��\n");
	gotoxy(90, 16);
	printf("��\n");
	gotoxy(90, 17);
	printf("��\n");
	gotoxy(90, 18);
	printf("��\n");
	gotoxy(90, 19);
	printf("��\n");
	gotoxy(90, 20);
	printf("��\n");
	gotoxy(90, 21);
	printf("��\n");
	gotoxy(90, 22);
	printf("��\n");
	gotoxy(90, 23);
	printf("��\n");
	gotoxy(90, 24);
	printf("��\n");




	gotoxy(30, 11);
	printf("��");
	gotoxy(90, 11);
	printf("��");
	gotoxy(30, 25);
	printf("��");
	gotoxy(90, 25);
	printf("��");

	gotoxy(38, 15);
	printf("���ã�⿡�� ������ ������ �Է��Ͻʽÿ� >>  ");
	_getch();

	gotoxy(38, 20);
	printf("���ã�⿡�� ### ������ �����Ͽ����ϴ�. ");

	gotoxy(31, 24);
	printf("�������� �Ѿ�� Enter ");
	_getch();
}