## 백준 15988 1,2,3 더하기 3 (C/DP)

### 문제 [문제보기](https://www.acmicpc.net/problem/15988)
- 정수 4를 1, 2, 3의 합으로 나타내는 방법은 총 7가지가 있다. 합을 나타낼 때는 수를 1개 이상 사용해야 한다.
- 1+1+1+1
- 1+1+2
- 1+2+1
- 2+1+1
- 2+2
- 1+3
- 3+1
- 정수 n이 주어졌을 때, n을 1, 2, 3의 합으로 나타내는 방법의 수를 구하는 프로그램을 작성하시오.

### 입력
- 첫째 줄에 테스트 케이스의 개수 T가 주어진다. 
- 각 테스트 케이스는 한 줄로 이루어져 있고, 정수 n이 주어진다. 
- n은 양수이며 1,000,000보다 작거나 같다.


### 출력
 - 각 테스트 케이스마다, n을 1, 2, 3의 합으로 나타내는 방법의 수를 1,000,000,009로 나눈 나머지를 출력한다.


### 풀이법
 - 다이나믹 프로그래밍을 이용해 풀 수 있다.
 - 숫자 4의 경우 1과 3을 더하는 것, 2와 2를 더하는 것, 3과 1을 더하는 것으로 쪼갤 수 있다.
 - 1,2,3을 이용해서만 더해야 하므로, (i-1)+1 , (i-2)+2, (i-3)+3으로만 분류가 가능하다.
 - 따라서 점화식은 d[n] =d[n-1]+d[n-2]+d[n-3]이다. 

### 코드
```
#include <stdio.h>

long long d[1000001];

void dp()
{
	for (int i = 4; i <= 1000000; i++)
	{
		d[i] = (d[i - 1] + d[i - 2] + d[i - 3]) % 1000000009;
	}
}

int main()
{
	int n;
	scanf("%d", &n);

	d[1] = 1;
	d[2] = 2;
	d[3] = 4;

	dp();
	int num;
	for (int j = 0; j < n; j++)
	{
		scanf("%d", &num);
		printf("%lld\n", d[num]);
	}

	return 0;
}
```
