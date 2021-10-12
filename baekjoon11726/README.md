## 백준 111726 2xN 타일링 (C++/DP)

### 문제 [문제보기](https://www.acmicpc.net/problem/11726)
- 2×n 크기의 직사각형을 1×2, 2×1 타일로 채우는 방법의 수를 구하는 프로그램을 작성하시오.
- 아래 그림은 2×5 크기의 직사각형을 채운 한 가지 방법의 예이다.


### 입력
- 첫째 줄에 n이 주어진다. (1 ≤ n ≤ 1,000)

### 출력
 - 첫째 줄에 2×n 크기의 직사각형을 채우는 방법의 수를 10,007로 나눈 나머지를 출력한다.


### 풀이법
 - 다이나믹 프로그래밍을 통해 푼다.
 - 문제가 처음 읽었을 때 복잡해보이지만, n번째 = (n-1)번째+(n-2)번째로 점화식을 세워 구할 수 있는 문제이다.
 - 이때 다이나믹 프로그래밍의 메모이제이션을 이용하기 위해 정수형 배열을 선언하고 그 배열에 값을 메모한다. 
 - https://www.youtube.com/watch?v=YHZiWaL49HY 이 영상을 참고하며 DP를 공부하고 문제를 풀기 위해 도움을 받았다. 


### 코드
```
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int memo[1001];


int dp(int n)
{
	if (n == 1) return 1;
	if (n == 2) return 2;
	if (memo[n] != 0)return memo[n];
	return memo[n] = (dp(n - 1) + dp(n - 2)) % 10007;
}

int main()
{
	int x;
	scanf("%d", &x);
	printf("%d", dp(x));
	return 0;
}
```
