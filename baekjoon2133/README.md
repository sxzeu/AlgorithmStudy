## 백준 2133 타일 채우기 (C/DP)

### 문제 [문제보기](https://www.acmicpc.net/problem/2133)
- 3×N 크기의 벽을 2×1, 1×2 크기의 타일로 채우는 경우의 수를 구해보자.

### 입력
- 첫째 줄에 N(1 ≤ N ≤ 30)이 주어진다.

### 출력
 - 첫째 줄에 경우의 수를 출력한다.

### 풀이법
 - 다이나믹 프로그래밍을 이용해 푸는 문제이다.
 - N=1일 경우에 주어진 크기의 타일로 채울 수 없다.
 - N=2일 경우에 주어진 크기의 타일로 채우는 경우의 수는 총 3가지이다.
 - N=3일 경우에 주어진 크기의 타일로 채울 수 없다.
 - N=4의 경우에 주어진 크기의 타일로 채우는 경우의 수 중 새로 만들 수 있는 케이스는 2가지이다. 
 - https://www.youtube.com/watch?v=kYoKLm8BZtI 이 영상을 참고하며 문제를 이해하고 풀이했다.


### 코드
```
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int d[1000001];

int dp(int x)
{
	if (x == 0) return 1;
	if (x == 1) return 0;
	if (x == 2) return 3;
	if (d[x] != 0) return d[x];
	
	int result = 3 * dp(x - 2);

	for (int i = 3; i <= x; i++)
	{
		if (i % 2 == 0) result += 2 * dp(x - i);
	}
	return d[x] = result;
}

int main()
{
	int x; 
	scanf("%d", &x);
	printf("%d", dp(x));
}
```
