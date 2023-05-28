#define _CRT_SECURE_NO_WARNINGS  // 비주얼 스튜디오에서 sacnf 오류 무시해주는 정의
// 알고리즘 쪽지시험
// 알고리즘 송해상 교수님
// 20191179 이동근
// 동적 계획 알고리즘 배낭 문제

/* 
텍스트 파일을 입력받아서 코드를 실행하여야 하지만
파일 입출력을 아직 잘 못쓰겠어서 수동으로 입력받고 출력하도록 코드를 수정하였습니다. ㅠㅠ
배열로서 구현해야 하지만 제대로 구현이 안되어서 그냥 최대가치만 출력하도록 하였습니다.
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

    printf("물건의 개수를 입력하세요: ");
    scanf("%d", &N);

    int* values = (int*)malloc(N * sizeof(int));
    int* weights = (int*)malloc(N * sizeof(int));

    printf("각 물건의 가치와 무게를 입력하세요>> \n");

    for (int i = 0; i < N; i++) 
    {
        printf("물건 %d의 가치: ", i + 1);
        scanf("%d", &values[i]);

        printf("물건 %d의 무게: ", i + 1);
        scanf("%d", &weights[i]);
    }

    printf("배낭의 용량을 입력하세요: ");
    scanf("%d", &maxW);

    int maxValue = knapSack(maxW, weights, values, N);

    printf("최대 가치: %d\n", maxValue);

    free(values);
    free(weights);

    return 0;
}