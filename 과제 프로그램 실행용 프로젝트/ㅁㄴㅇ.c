#pragma warning(disable:4996) // ���־� ��Ʃ������� sacnf ���� �������ִ� ����
// ���� 3.3 ~ 3.5 �� ��ģ ���α׷�
// 19�й� 2�г� �̵��� 201911079


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STACK_SIZE 100

typedef double Element;

Element data[MAX_STACK_SIZE];

int top;

void error(char str[])
{
    printf("%s\n", str);
    exit(1);
}

void init_stack()
{
    top = -1;
}

int is_empty()
{
    return top == -1;
}

int is_full()
{
    return top == MAX_STACK_SIZE - 1;
}

int size()
{
    return top + 1;
}

void push(Element e)
{
    if (is_full())
        error("���� ��ȭ ����");
    data[++top] = e;
}

Element pop()
{
    if (is_empty())
        error("���� ���� ����");
    return data[top--];
}

Element peek()
{
    if (is_empty())
        error("���� ���� ����");
    return data[top];
}

int check_parentheses(char expr[])
{
    int i;
    int len = strlen(expr);
    char ch;
    init_stack();

    for (i = 0; i < len; i++)
    {
        ch = expr[i];
        if (ch == '(')
        {
            push(ch);
        }
        else if (ch == ')')
        {
            if (is_empty())
                return 0;
            else
                pop();
        }
    }

    if (is_empty())
        return 1;
    else
        return 0;
}

void infix_to_postfix(char expr[], char postfix[])
{
    int i = 0, j = 0;
    char ch;
    int len = strlen(expr);
    init_stack();

    for (i = 0; i < len; i++)
    {
        ch = expr[i];
        switch (ch)
        {
        case '+':
        case '-':
        case '*':
        case '/':
            while (!is_empty() && (peek() == '*' || peek() == '/'))
            {
                postfix[j++] = pop();
            }
            push(ch);
            break;
        case '(':
            push(ch);
            break;
        case ')':
            while (peek() != '(')
            {
                postfix[j++] = pop();
            }
            pop();
            break;
        default:
            while (ch >= '0' && ch <= '9')
            {
                postfix[j++] = ch;
                ch = expr[++i];
            }
            postfix[j++] = ' ';
            i--;
        }
    }

    while (!is_empty())
    {
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
}

double calc_postfix(char expr[])
{
    char c;
    int i = 0;
    double val, val1, val2;

    init_stack();

    while (expr[i] != '\0')
    {
        c = expr[i++];

        if (c >= '0' && c <= '9')
        {
            val = c - '0';
            push(val);
        }
        else if (c == '+' || c == '-' || c == '*' || c == '/')
        {
            val2 = pop();
            val1 = pop();

            switch (c)
            {
            case '+':
                push(val1 + val2);
                break;
            case '-':
                push(val1 - val2);
                break;
            case '*':
                push(val1 * val2);
                break;
            case '/':
                push(val1 / val2);
                break;
            }
        }
    }

    return pop();
}

int main()
{
    char expr[80], postfix[80];
    double result;

    printf("������ �Է��ϼ���: ");
    fgets(expr, 80, stdin);

    // ���� ���� ����
    if (expr[strlen(expr) - 1] == '\n') {
        expr[strlen(expr) - 1] = '\0';
    }
    while (getchar() != '\n');

    // ��ȣ �˻� �� ���� ǥ�� �������� ��ȯ
    if (check_parentheses(expr) == 1)
    {
        infix_to_postfix(expr, postfix);

        // ���� ǥ�� ���� ���
        result = calc_postfix(postfix);

        printf("��� ���: %lf\n", result);
    }
    else {
        printf("��ȣ ������ �ֽ��ϴ�.\n");
    }

    return 0;
}

