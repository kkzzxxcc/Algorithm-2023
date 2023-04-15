#pragma warning(disable:4996) // 비주얼 스튜디오에서 sacnf 오류 무시해주는 정의
#define _CRT_SECURE_NO_WARNINGS
// 4월 11일 데이터구조 수업
// 19학번 2학년 이동근
// 5장 포인터와 연결리스트
// 동적 메모리 할당으로 변경

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

	ps = (Student*)malloc(sizeof(Student));   // 동적으로 메모리 할당

	*ps = s1;
	printf("ps -> id : %d, ps - > name : %s, ps -> dept : %s \n", ps->id, ps->name, ps->dept);

	test1(*ps);
	printf("ps -> id : %d, ps - > name : %s, ps -> dept : %s \n", ps->id, ps->name, ps->dept);

	test2(ps);
	printf("ps -> id : %d, ps - > name : %s, ps -> dept : %s \n", ps->id, ps->name, ps->dept);

	*ps = test3(*ps);    // s2 = test3(s2);   // *ps = test3(s2)
	printf("ps -> id : %d, ps - > name : %s, ps -> dept : %s \n", ps->id, ps->name, ps->dept);

	free(ps);              // 동적 메모리 할당 헤제

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