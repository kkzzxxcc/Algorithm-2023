// 3�� 15�� �����ͱ��� ����(����)
// 19�й� 2�г� �̵���
// �迭�� ����ü
// ���ڿ�

#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)

int main(void)
{

	char s1[60] = "C ���� ";
	char s2[60] = "���� ���α׷��� ����Դϴ�.";
	char s3[60];
	char s[4][50];

	int length, i;

	length = strlen(s1);
	printf("String ���̴� %d \n", length);  // ��Ʈ�� ���̴� 14

	strcpy(s3, s1);
	printf("s3 = %s \n", s3); // s3 = C ����

	if (strcmp(s1, s3) == 0) // string compare
		printf("s1 �� s3�� �����ϴ� \n"); // s1�� s3�� ����

	else
		printf("s1�� s3�� ���� �ʽ��ϴ�.\n");

	if (strcmp(s1, s2) == 0)
		printf("s1�� s2�� �����ϴ�\n");

	else
		printf("s1�� s2�� ���� �ʽ��ϴ�.\n"); // s1�� s2�� ���� �ʴ�.

	strcat(s1, s2);
	printf("s1 = %s \n", s1);

	for (i = 0; i < 4; i++) {
		printf("�̸��� �Է��ϼ��� ");
		scanf("%s", s[i]);
	}

	for (i = 0; i < 4; i++) {
		printf("\n �̸��� %s ", s[i]);

	}


	return 0;
}