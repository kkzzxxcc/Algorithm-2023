// 3월 21일 데이터구조 수업
// 19학번 2학년 이동근 201911079
// 
// 스택
// 배열을 이용한 int 스택의 구현
// 배열을 이용한 Student 스택의 구현
// 포인터로 변경
// 

#pragma warning(disable:4996) // 비주얼 스튜디오에서 sacnf 오류 무시해주는 정의

#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100          // 스택 요소 저장을 위한 배열의 크기

// typedef int Element;                // 스택 요소의 자료형 정의

typedef struct Student
{
	int id;                     // 이름
	char name[32];              // 학번
	char dept[32];              // 학과

} Student;                      // 스택 요소 저장을 위한 배열의 크기

typedef Student Element;        // 스택 요소의 자료형 정의

// Element data[MAX_STACK_SIZE];       // 실제 스택 요소의 배열

// int top;                            // 실제 스택의 top

typedef struct stack                   // 포인터 구조체 정의
{
	Element data[MAX_STACK_SIZE];
	int top;
} Stack;

void init_stack(Stack* s);
int is_empty(Stack* s);
int is_full(Stack* s);
int size(Stack* s);
void push(Stack* s, Element e);
Element pop(Stack* s);
Element peek(Stack* s);
void print_stack(Stack s, char msg[]);


// 오류 상황 처리를 위한 함수. 메시지를 출력 후 프로그램 종료.
void error(char str[])
{
	printf("%s \n", str);
	exit(1);
}

// 스택의 주요 연산
void init_stack(Stack *s) { s -> top = -1; }
int size(Stack *s) { return s -> top + 1; }
int is_empty(Stack *s) { return s -> top == -1; }
int is_full(Stack *s) { return s -> top == MAX_STACK_SIZE - 1; }


void push(Stack *s, Element e)
{
	if (is_full(s))
		error("스택 포화 에러");
	s -> data[++s -> top ]= e;
}


Element pop(Stack *s)
{
	if (is_empty(s))
		error("스택 공백 에러");
	return s -> data[s -> top--];
}

Element peek(Stack *s)
{
	if (is_empty(s))
		error("스택 공백 에러");
	return s -> data[s -> top];
}


// 스택 테스트를 위한 코드 : 요소 종류마다 수정
void print_stack(Stack s, char msg[]) 
{
	int i;

	printf("%s[%1d]= ", msg, size(&s));

	for (i = 0; i < size(&s); i++)
		printf("\n\t %-15d  %-10s  %-20s", s.data[i].id, s.data[i].name, s.data[i].dept);

	printf("\n");

}

Student get_student(int id, char name[], char dept[])
{

	Student s;
	s.id = id;
	strcpy(s.name, name);  // 문자열 복사. s.name = name은 오류
	strcpy(s.dept, dept);  // 문자열 복사. s.dept = dept는 오류

	return s;

}

void main()
{
	Stack s;
	Element e;
	init_stack(&s);

	push(&s, get_student(201911079, "홍길동", "컴퓨터공학과"));
	push(&s, get_student(201231107, "이순신", "기계공학과"));
	push(&s, get_student(201494789, "김연아", "체육과"));
	push(&s, get_student(209472079, "황희", "법학과"));

	print_stack(s, " 친구 4명 삽입 후 ");
	pop(&s);
	print_stack(s, " 친구 1명 삭제 후 ");
	e = peek(&s);

	printf("ID = %d, Name = %s, Dept.Name = %s \n", e.id, e.name, e.dept);
	print_stack(s, "After peek()");

	return 0;

}

/* void main()
{
	int i;
	init_stack();

	for (i = 1; i < 10; i++)
		push(i);

	print_stack("스택 push 9회");
	printf("\tpop() --> %d\n", pop());
	printf("\tpop() --> %d\n", pop());
	printf("\tpop() --> %d\n", pop());
	print_stack("스택 pop 3회");

}

*/