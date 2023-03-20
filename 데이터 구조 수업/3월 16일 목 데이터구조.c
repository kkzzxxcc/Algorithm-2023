// 3월 16일 데이터구조 수업
// 19학번 2학년 이동근
// 배열과 구조체, 함수
// 구조체 응용

#define _CRT_SECURE_NO_WARNINGS  // 비주얼 스튜디오에서 sacnf 오류 무시해주는 정의

// 프로그램 2.3 예제 함수의 매개변수로서의 구조체
/* 
#include <stdio.h>

typedef struct 
{
	double real;  // 복소수의 실수부
	double imag;  // 복소수의 허수부

}Complex;

void print_complex(Complex c) 
{
	printf(" %4.1f + %4.1fi \n", c.real, c.imag);

}

void reset_complex(Complex c) 
{
	c.real = c.imag = 0.0;
}

void main() 
{
	Complex a = { 1.0, 2.0 };
	printf("초기화 이전 : ");
	print_complex(a);         // 복소수 화면 출력
	reset_complex(a);         // 초기화가 되지 않음

	printf("초기화 이후 : ");
	print_complex(a);         // 복소수 화면 출력
}
*/


#include <stdio.h>
#include <string.h>

struct student {
	int id;
	char name[20];
	double score;

};

typedef struct student Student;

void printf_student(Student s); // 매개변수로 받음
Student Max_student(Student s[], int n); // 구조체에 배열로 넘겨받는 함수

int main(void)
{

	struct student s1 = { 1, "park", 80.5 }, s2;
	Student s[3];
	int i;

	s2.id = 2;
	strcpy(s2.name, "kim"); // s2.name != "kim"
	printf_student(s1);

	for (i = 0; i < 3; i++)
	{
		printf(" ID, name, score >> ");
		scanf("%d %s %lf", &s[i].id, &s[i].name, &s[i].score);

	}

	for (i = 0; i < 3; i++)
		printf_student(s[i]);
	
	s2 = Max_student(s, 3);
	printf("최대 점수를 가진 학생은 : \n");
	printf_student(s2);

	return 0;
}

void printf_student(Student s)
{
	printf(" ID = %d, Name = %s, scored = %lf\n", s.id, s.name, s.score);
}

Student Max_student(Student s[], int n) // 구조체에서 맥스로 값을 받아서 최대값을 구하는 함수
{
	int i;
	Student Max;

	Max = s[0];

	for (i = 0; i < n; i++)
		if (Max.score < s[i].score)
			Max = s[i];

	return Max;

}