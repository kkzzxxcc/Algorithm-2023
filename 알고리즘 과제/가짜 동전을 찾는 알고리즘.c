#define _CRT_SECURE_NO_WARNINGS  // 비주얼 스튜디오에서 sacnf 오류 무시해주는 정의
// 3주자 알고리즘 실습과제
// 알고리즘 송해상 교수님
// 20191179 이동근
// 가짜 동전을 찾는 알고리즘


#include <stdio.h>
#include <stdlib.h>
#include <math.h>


// 가짜 동전을 찾기 위한 함수
int findFakeCoin(int coins[], int low, int high) 
{
    
    int left, right, mid;  // 저울의 왼쪽 오른쪽 중앙 인덱스값

    // 더이상 쪼갤 수 없는 경우에는 low값이 가짜 동전의 위치
    if (low == high) 
    {
        return low;
    }

    else 
    {
        int length = high - low + 1;  // 저울에 올려진 동전들의 개수

        // 동전의 개수가 홀수개이면 중앙값을 나누어서 오른쪽 저울에 올려놓음
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

        // 양쪽 저울에 무게를 달아서 비교
        int left_sum = 0, right_sum = 0;

        for (int i = left; i < mid; i++) 
        {
            left_sum += coins[i];
        }

        for (int i = mid; i <= right; i++) 
        {
            right_sum += coins[i];
        }

        // 왼쪽 저울이 가벼운 경우
        if (left_sum < right_sum) 
        {
            return findFakeCoin(coins, left, mid - 1);
        }

        // 오른쪽 저울이 가벼운 경우
        else if (left_sum > right_sum) 
        {
            return findFakeCoin(coins, mid, right);
        }

        // 저울에 무게 차이가 없는 경우
        else 
            return low;
        
    }
}

// 메인 함수
int main() 
{
    int num_coins;    // 입력받는 동전의 개수

    printf("동전의 개수를 입력하세요: ");
    scanf("%d", &num_coins);


    // 처음에 int coins[num_coins] 라고 했으나 오류를 발견하고 검색해보니 정수형 배열을 동적으로 할당하여야 한다고 했다.
    // 정확히 어떤 뜻인지는 아직 잘 모르겠습니다만 오류 해결을 위해 사용하였습니다.
    // malloc 함수는 할당된 메모리의 주소를 반환하기 때문에 int*로 형변환하여 포인터 변수에 저장합니다.
    int* coins = (int*)malloc(num_coins * sizeof(int)); 
    

    for (int i = 0; i < num_coins; i++)
    {
        coins[i] = 1;
    }

    coins[num_coins - 1] = 0; // 가짜 동전은 가장 마지막에 위치

    // 가짜 동전 찾기 함수 호출
    int fake_coin_index = findFakeCoin(coins, 0, num_coins - 1);

    printf("가짜 동전의 위치: %d\n", fake_coin_index + 1);


    // 저울을 몇 번 사용했는지 출력
    printf("저울 사용 횟수: %d\n", (int)(2 * log(num_coins) / log(3)) + 1);

    free(coins); // 동적 메모리를 해제하기 위해 사용

    return 0;
}
