// 3�� 20�� �˰��� �ǽ�
// 201911079 �̵���
// ��Ŭ������ �ִ����� �˰��� ¥����

#include <stdio.h>

// int main(int argc, char *argv[])


int eUclid(int a, int b)
{
	
	// If(b = 0) return a // �������� of ���ȣ��!
	if (b == 0)
		return a;

    // return Euclid(b, a mod b)
	return eUclid(b, a % b);


}

int test_eUclid()
{

	int gcd = 0;

	gcd = eUclid(34, 48);

	printf("Hello World %d \n", gcd);

	return 0;
}


int main()

{
	test_eUclid();
	
}