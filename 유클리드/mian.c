// ���α׷��� �����ϴ� ���� �Լ�

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "euclid.h"


int testEuclid();     // ����� �˰��� �Լ�
int testEuclid_2();   // �ݺ��� �˰��� �Լ�


int main(void)
{
	int ret = 0;      // ����� �˰��� �����
	int ret_2 = 0;    // �ݺ��� �˰��� �����
	int ret_3 = 0;    // �� �˰����� ����ð� �����

	printf("Hello World\n");

	ret = testEuclid();
	ret_2 = testEuclid_2();
	ret_3 = check_time();

    return 0;
}
	
