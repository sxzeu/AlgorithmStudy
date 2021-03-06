## 백준 15990 1,2,3 더하기5 (C/DP)

### 문제 [문제보기](https://www.acmicpc.net/problem/15990)
- 정수 4를 1, 2, 3의 합으로 나타내는 방법은 총 3가지가 있다. 
- 합을 나타낼 때는 수를 1개 이상 사용해야 한다. 
- 단, 같은 수를 두 번 이상 연속해서 사용하면 안 된다.
- 1+2+1
- 1+3
- 3+1
- 정수 n이 주어졌을 때, n을 1, 2, 3의 합으로 나타내는 방법의 수를 구하는 프로그램을 작성하시오.

### 입력
- 첫째 줄에 테스트 케이스의 개수 T가 주어진다. 
- 각 테스트 케이스는 한 줄로 이루어져 있고, 정수 n이 주어진다. n은 양수이며 100,000보다 작거나 같다.


### 출력
 - 각 테스트 케이스마다, n을 1, 2, 3의 합으로 나타내는 방법의 수를 1,000,000,009로 나눈 나머지를 출력한다.

### 풀이법
 - 2차원 다이나믹 프로그래밍을 이용해 푸는 문제이다.
 - n이 입력값으로 주어졌을때의 경우에 대해서 생각을 해보자면,
 - 1과 n-1로 나누어 생각할 수 있다. 이때 1이 이미 나왔으므로 n-1은 2와 3이 나오는 경우에 대해 생각할 수 있다.
 - 따라서 d[n][1] = d[n-1][2]+ d[n-1][3] 으로 나타낼 수 있다.
 - 그리고 2가 가장 먼저 나오는 경우에 대해 생각을 해보자면 d[n][2] = d[n-1][1] + d[n-1][3] 으로 나타낼 수 있다.
 - 무작정 해당 케이스를 적는 것 보다, 조건을 맞추며 설계하며 문제를 푸는 것이 좋을 것 같다. 


### 코드
```
#include <stdio.h>

long long d[100001][4];
const int MAX = 100001;
const int mod = 1000000009;


void dp()
{
	d[1][1] = 1;
	d[2][2] = 1;
	d[3][3] = 1;
	d[3][2] = 1;
	d[3][1] = 1;

	for (int i = 4; i < MAX; i++)
	{
		if (i - 1 >= 0) {
			d[i][1] = (d[i - 1][2] + d[i - 1][3]) % mod;
		}
		if (i - 2 >= 0) {
			d[i][2] = (d[i - 2][1] + d[i - 2][3]) % mod;
		}
		if (i - 3 >= 0) {
			d[i][3] = (d[i - 3][1] + d[i - 3][2]) % mod;
		}
	}
}

int main()
{
	int n;
	scanf("%d", &n);

	dp();
	for (int i = 0; i < n; i++)
	{
		int num;
		scanf("%d", &num);
		printf("%d\n", (d[num][1] + d[num][2] + d[num][3]) % mod);

	}
	return 0;
}
```
