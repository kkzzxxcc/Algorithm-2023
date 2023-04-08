
// 4�� 4�� �˰��� �ǽ�
// 201911079 �̵���
// ��Ŭ���� �˰����� �Լ��� ����

#include <stdio.h>
#include <stdlib.h>


// ����� �ִ����� �˰���
int euclidRecursive(int a, int b)
{
	// If(b = 0) return a // �������� of ���ȣ��!
	if (b == 0)
		return a;

	// return euclidRecursive(b, a mod b)
	else 
	    return euclidRecursive(b, a % b);
	
}

// �ݺ��� �ִ����� �˰���
int euclidRepeatitive(int a, int b)
{
	if (a < b) 
		return 0; // �Է�Ȯ��

	int bsav;    // �ӽ� ���

	while(b != 0)
	{
		bsav = b;

		b = a % b;
		a = bsav;
	}

	return a;
	
}
