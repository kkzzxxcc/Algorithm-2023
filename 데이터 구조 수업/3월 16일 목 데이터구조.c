// 3�� 16�� �����ͱ��� ����
// 19�й� 2�г� �̵���
// �迭�� ����ü, �Լ�
// ����ü ����

#define _CRT_SECURE_NO_WARNINGS  // ���־� ��Ʃ������� sacnf ���� �������ִ� ����

// ���α׷� 2.3 ���� �Լ��� �Ű������μ��� ����ü
/* 
#include <stdio.h>

typedef struct 
{
	double real;  // ���Ҽ��� �Ǽ���
	double imag;  // ���Ҽ��� �����

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
	printf("�ʱ�ȭ ���� : ");
	print_complex(a);         // ���Ҽ� ȭ�� ���
	reset_complex(a);         // �ʱ�ȭ�� ���� ����

	printf("�ʱ�ȭ ���� : ");
	print_complex(a);         // ���Ҽ� ȭ�� ���
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

void printf_student(Student s); // �Ű������� ����
Student Max_student(Student s[], int n); // ����ü�� �迭�� �Ѱܹ޴� �Լ�

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
	printf("�ִ� ������ ���� �л��� : \n");
	printf_student(s2);

	return 0;
}

void printf_student(Student s)
{
	printf(" ID = %d, Name = %s, scored = %lf\n", s.id, s.name, s.score);
}

Student Max_student(Student s[], int n) // ����ü���� �ƽ��� ���� �޾Ƽ� �ִ밪�� ���ϴ� �Լ�
{
	int i;
	Student Max;

	Max = s[0];

	for (i = 0; i < n; i++)
		if (Max.score < s[i].score)
			Max = s[i];

	return Max;

}