#define _CRT_SECURE_NO_WARNINGS  // ���־� ��Ʃ������� sacnf ���� �������ִ� ����
// 3���� �˰��� �ǽ�����
// �˰��� ���ػ� ������
// 20191179 �̵���
// ��¥ ������ ã�� �˰���


#include <stdio.h>
#include <stdlib.h>
#include <math.h>


// ��¥ ������ ã�� ���� �Լ�
int findFakeCoin(int coins[], int low, int high) 
{
    
    int left, right, mid;  // ������ ���� ������ �߾� �ε�����

    // ���̻� �ɰ� �� ���� ��쿡�� low���� ��¥ ������ ��ġ
    if (low == high) 
    {
        return low;
    }

    else 
    {
        int length = high - low + 1;  // ���￡ �÷��� �������� ����

        // ������ ������ Ȧ�����̸� �߾Ӱ��� ����� ������ ���￡ �÷�����
        if (length % 2 == 0) 
        {
            left = low;
            right = low + length / 2;
            mid = right;
        }

        else 
        {
            left = low;
            right = low + length / 2;
            mid = right + 1;
        }

        // ���� ���￡ ���Ը� �޾Ƽ� ��
        int left_sum = 0, right_sum = 0;

        for (int i = left; i < mid; i++) 
        {
            left_sum += coins[i];
        }

        for (int i = mid; i <= right; i++) 
        {
            right_sum += coins[i];
        }

        // ���� ������ ������ ���
        if (left_sum < right_sum) 
        {
            return findFakeCoin(coins, left, mid - 1);
        }

        // ������ ������ ������ ���
        else if (left_sum > right_sum) 
        {
            return findFakeCoin(coins, mid, right);
        }

        // ���￡ ���� ���̰� ���� ���
        else 
            return low;
        
    }
}

// ���� �Լ�
int main() 
{
    int num_coins;    // �Է¹޴� ������ ����

    printf("������ ������ �Է��ϼ���: ");
    scanf("%d", &num_coins);


    // ó���� int coins[num_coins] ��� ������ ������ �߰��ϰ� �˻��غ��� ������ �迭�� �������� �Ҵ��Ͽ��� �Ѵٰ� �ߴ�.
    // ��Ȯ�� � �������� ���� �� �𸣰ڽ��ϴٸ� ���� �ذ��� ���� ����Ͽ����ϴ�.
    // malloc �Լ��� �Ҵ�� �޸��� �ּҸ� ��ȯ�ϱ� ������ int*�� ����ȯ�Ͽ� ������ ������ �����մϴ�.
    int* coins = (int*)malloc(num_coins * sizeof(int)); 
    

    for (int i = 0; i < num_coins; i++)
    {
        coins[i] = 1;
    }

    coins[num_coins - 1] = 0; // ��¥ ������ ���� �������� ��ġ

    // ��¥ ���� ã�� �Լ� ȣ��
    int fake_coin_index = findFakeCoin(coins, 0, num_coins - 1);

    printf("��¥ ������ ��ġ: %d\n", fake_coin_index + 1);


    // ������ �� �� ����ߴ��� ���
    printf("���� ��� Ƚ��: %d\n", (int)(2 * log(num_coins) / log(3)) + 1);

    free(coins); // ���� �޸𸮸� �����ϱ� ���� ���

    return 0;
}
