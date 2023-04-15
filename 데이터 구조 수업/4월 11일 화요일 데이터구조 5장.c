#pragma warning(disable:4996) // ���־� ��Ʃ������� sacnf ���� �������ִ� ����
#define _CRT_SECURE_NO_WARNINGS
// 4�� 11�� �����ͱ��� ����
// 19�й� 2�г� �̵���
// 5�� �����Ϳ� ���Ḯ��Ʈ
// ���� �޸� �Ҵ����� ����

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student
{
	int id;
	char name[20];
	char dept[32];
} Student;

void test1(Student s);
void test2(Student *s);
Student test3(Student s);

int main(void)
{

	Student s1, s2;
	// Student* ps = &s2;
	Student* ps;

	s1.id = 10;

	strcpy(s1.name, "Park");
	strcpy(s1.dept, "Computer Eng");

	ps = (Student*)malloc(sizeof(Student));   // �������� �޸� �Ҵ�

	*ps = s1;
	printf("ps -> id : %d, ps - > name : %s, ps -> dept : %s \n", ps->id, ps->name, ps->dept);

	test1(*ps);
	printf("ps -> id : %d, ps - > name : %s, ps -> dept : %s \n", ps->id, ps->name, ps->dept);

	test2(ps);
	printf("ps -> id : %d, ps - > name : %s, ps -> dept : %s \n", ps->id, ps->name, ps->dept);

	*ps = test3(*ps);    // s2 = test3(s2);   // *ps = test3(s2)
	printf("ps -> id : %d, ps - > name : %s, ps -> dept : %s \n", ps->id, ps->name, ps->dept);

	free(ps);              // ���� �޸� �Ҵ� ����

	return 0;

}

void test1(Student s)
{
	s.id = 20;
}

void test2(Student* s)
{
	s->id = 20;
}

Student test3(Student s)
{
	s.id = 30;
	return s;
}