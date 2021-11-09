#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>

using namespace std;

// 전체 합 - 두 개의 합 = 100, 아닌 값은 -1로 돌리기
int find(int v[],int sum)
{
    int num = sum;
    int output = 0;

    for (int i = 0; i < 8; i++)
    {
        for (int j = i + 1; j < 9; j++)
        {
            if (num - (v[i] + v[j]) == 100)
            {
                v[i] = -1;
                v[j] = -1;
                return 0;
            }
        }
    }
}

int main()
{
    int v[9] = { 0, };
    int sum = 0;

    // 난쟁이를 입력받고 정렬하기 
    for (int i = 0; i < 9; i++) {
        cin >> v[i];
        sum += v[i];
    }
    sort(v, v + 9);

    // 찾기
    find(v, sum);

    // 출력하기
    for (int i = 0; i < 9; i++) {
        if (v[i] != -1) cout << v[i] << "\n";
    }
    return 0;
}