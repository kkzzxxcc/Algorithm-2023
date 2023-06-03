#define _CRT_SECURE_NO_WARNINGS  // ���־� ��Ʃ������� sacnf ���� �������ִ� ����
// �˰��� ��������
// �˰��� ���ػ� ������
// 20191179 �̵���
// ���� ��ȹ �˰��� �賶 ����

/* 
�ؽ�Ʈ ������ �Է¹޾Ƽ� �ڵ带 �����Ͽ��� ������
���� ������� ���� �� �����ھ �������� �Է¹ް� ����ϵ��� �ڵ带 �����Ͽ����ϴ�. �Ф�
�迭�μ� �����ؾ� ������ ����� ������ �ȵǾ �׳� �ִ밡ġ�� ����ϵ��� �Ͽ����ϴ�.
*/

#include <stdio.h>
#include <stdlib.h>

int maxx(int a, int b) 
{
    return (a > b) ? a : b;
}

int knapSack(int maxW, int weights[], int values[], int N) 
{
    int i, w;
    int** K = (int**)malloc((N + 1) * sizeof(int*));

    for (i = 0; i <= N; i++) 
    {
        K[i] = (int*)malloc((maxW + 1) * sizeof(int));
    }

    for (i = 0; i <= N; i++) 
    {
        for (w = 0; w <= maxW; w++) 
        {
            if (i == 0 || w == 0)
                K[i][w] = 0;

            else if (weights[i - 1] <= w)
                K[i][w] = max(values[i - 1] + K[i - 1][w - weights[i - 1]], K[i - 1][w]);

            else
                K[i][w] = K[i - 1][w];
        }
    }

    int maxValue = K[N][maxW];

    for (i = 0; i <= N; i++) 
    {
        free(K[i]);
    }

    free(K);

    return maxValue;
}

int main() 
{
    int N, maxW;

    printf("������ ������ �Է��ϼ���: ");
    scanf("%d", &N);

    int* values = (int*)malloc(N * sizeof(int));
    int* weights = (int*)malloc(N * sizeof(int));

    printf("�� ������ ��ġ�� ���Ը� �Է��ϼ���>> \n");

    for (int i = 0; i < N; i++) 
    {
        printf("���� %d�� ��ġ: ", i + 1);
        scanf("%d", &values[i]);

        printf("���� %d�� ����: ", i + 1);
        scanf("%d", &weights[i]);
    }

    printf("�賶�� �뷮�� �Է��ϼ���: ");
    scanf("%d", &maxW);

    int maxValue = knapSack(maxW, weights, values, N);

    printf("�ִ� ��ġ: %d\n", maxValue);

    free(values);
    free(weights);

    return 0;
}