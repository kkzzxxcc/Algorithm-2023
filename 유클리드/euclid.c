#pragma warning(disable:4996) // ���־� ��Ʃ������� sacnf ���� �������ִ� ����

// 4�� 4�� �˰��� �ǽ�
// 201911079 �̵���
// ��Ŭ���� �˰����� �Լ��� ����

#include <stdio.h>


// ����� �ִ����� �˰���
int euclidRecursive(int a, int b)
{
	// If(b = 0) return a // �������� of ���ȣ��!
	if (b == 0)
		return a;

	// return euclidRecursive(b, a mod b)
	return euclidRecursive(b, a % b);
	
}

// �ݺ��� �ִ����� �˰���
int euclidRepeatitive(int a, int b)
{
	return 0;
}