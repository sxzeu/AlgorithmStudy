## 백준 1699 제곱수의 합 (C/DP)

### 문제 [문제보기](https://www.acmicpc.net/problem/1699)
 - 어떤 자연수 N은 그보다 작거나 같은 제곱수들의 합으로 나타낼 수 있다. 
 - 예를 들어 11=32+12+12(3개 항)이다. 
 - 이런 표현방법은 여러 가지가 될 수 있는데, 11의 경우 11=22+22+12+12+12(5개 항)도 가능하다. 
 - 이 경우, 수학자 숌크라테스는 “11은 3개 항의 제곱수 합으로 표현할 수 있다.”라고 말한다. 
 - 또한 11은 그보다 적은 항의 제곱수 합으로 표현할 수 없으므로, 11을 그 합으로써 표현할 수 있는 제곱수 항의 최소 개수는 3이다.
 - 주어진 자연수 N을 이렇게 제곱수들의 합으로 표현할 때에 그 항의 최소개수를 구하는 프로그램을 작성하시오.

### 입력
 - 첫째 줄에 자연수 N이 주어진다. (1 ≤ N ≤ 100,000)

### 출력
 - 주어진 자연수를 제곱수의 합으로 나타낼 때에 그 제곱수 항의 최소 개수를 출력한다.

### 풀이법
 - 다이나믹 프로그래밍을 이용해 풀 수 있는 문제이다.
 - 초기의 메모이제이션 배열 값을 모두 인덱스와 같이 설정한다. 
 - 1,2,3은 1의 합으로만 구성하는 것만 가능하므로 4부터 탐색을 시작한다.
 - 탐색시에는 현재의 값에서 제곱수를 뺀 숫자의 배열값에 1을 더한 것과 현재 배열 값을 비교한다.
 - 현재 탐색하고 있는 숫자(i)에서 현재 빼고 있는 숫자(jxj)을 빼고나면 dp[i-jxj]번째 값이 나오므로 1을 더해주는 것이다.

### 코드
```
#include <stdio.h>

int dp[100001];

int min(int a, int b)
{
	if (a > b) return b;
	else return a;
}

int main()
{
	int n = 0;
	scanf("%d", &n);

	for (int i = 0; i <= n; i++) dp[i] = i;

	for (int i = 4; i <= n; i++) {
		for (int j = 2; j * j <= i; j++) {
      dp[i] = min(dp[i], dp[i - j * j] + 1);
		}
	}

	printf("%d\n", dp[n]);
	return 0;
}
```
