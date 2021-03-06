## 백준 11727 2xN 타일링 2 (C/DP)

### 문제 [문제보기](https://www.acmicpc.net/problem/11727)
- 2×n 직사각형을 1×2, 2×1과 2×2 타일로 채우는 방법의 수를 구하는 프로그램을 작성하시오.
아래 그림은 2×17 직사각형을 채운 한가지 예이다.


### 입력
- 첫째 줄에 n이 주어진다. (1 ≤ n ≤ 1,000)

### 출력
 - 첫째 줄에 2×n 크기의 직사각형을 채우는 방법의 수를 10,007로 나눈 나머지를 출력한다.


### 풀이법
 - 다이나믹 프로그래밍을 통해 푼다.
 - 문제가 처음 읽었을 때 복잡해보이지만, n번째 = (n-1)번째+2x(n-2)번째로 점화식을 세워 구할 수 있는 문제이다.
 - https://www.acmicpc.net/problem/11726 문제와 다른 점은 2x2 블록이 추가되었다는 점이다.
 - 추가된 블록의 처리에 유의하도록 한다. 
 - 예를 들어 2x2의 공간을 채우는 경우의 수에 대하여 생각을 해보자면, 2x1 블록 두 개를 이용해 공간을 채우는 것과, 2x2 블록 한 개를 이용해 공간을 채우는 방법이 있다. 
 - 그러므로 n-2의 공간을 채우는 케이스에는 점화식에서 2를 곱해주도록 한다.
 - 이때 1x2 블록 두개를 사용할 수 없는 이유는, 이 경우에는 (n-1)x2 과 1x2공간을 채우는 것에 포함되는 케이스이므로 유의한다.
 - 이때 다이나믹 프로그래밍의 메모이제이션을 이용하기 위해 정수형 배열을 선언하고 그 배열에 값을 메모한다. 
 - https://www.youtube.com/watch?v=YHZiWaL49HY 이 영상을 참고하며 DP를 공부하고 문제를 풀기 위해 도움을 받았다. 


### 코드
```
#include <stdio.h>

int memo[1001];


int dp(int n)
{
	if (n == 1) return 1;
	if (n == 2) return 3;
	if (memo[n] != 0)return memo[n];
	return memo[n] = (dp(n - 1) + 2 * (dp(n - 2))) % 10007;
}

int main()
{
	int x;
	scanf("%d", &x);
	printf("%d", dp(x));
	return 0;
}
```
