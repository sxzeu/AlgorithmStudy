## 백준 15649 N과 M(1) (C/brute force)

### 문제 [문제보기](https://www.acmicpc.net/problem/15649)
 - 자연수 N과 M이 주어졌을 때, 아래 조건을 만족하는 길이가 M인 수열을 모두 구하는 프로그램을 작성하시오.
 - 1부터 N까지 자연수 중에서 중복 없이 M개를 고른 수열

### 입력
 - 첫째 줄에 자연수 N과 M이 주어진다. (1 ≤ M ≤ N ≤ 8)

### 출력
 - 한 줄에 하나씩 문제의 조건을 만족하는 수열을 출력한다. 
 - 중복되는 수열을 여러 번 출력하면 안되며, 각 수열은 공백으로 구분해서 출력해야 한다.
 - 수열은 사전 순으로 증가하는 순서로 출력해야 한다.


### 풀이법
 - DFS 깊이 우선 탐색을 이용해서 문제를 풀 수 있다. 
 - DFS의 경우 재귀를 통해 문제를 해결할 수 있는 규칙을 먼저 찾는 것이 중요하다.
 - 첫 번째로 dfs함수를 만들어 x는 현재 채우는 중인 자릿수, idx는 호출된 수, 그리고 입력한 m과 n을 매개변수로 받아 처리하도록 하였다.
 - 만약 현재 호출된 수가 이미 탐색이 되어 방문이 된 숫자라면 dfs함수가 리턴된다. 그리고 현재 호출된 수를 호출한 dfs함수로 다시 되돌아 간다.
 - 탐색이 끝났다면(list에 채워진 수와 출력하고자 하는 배열의 길이가 같다면) 리스트를 출력한다.
 

### 코드
```
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

bool visited[9] = { 0, };
int list[9] = { 0, };

void dfs(int x, int idx, int m, int n)
{
	if (x == n)
	{
		for (int i = 0; i < n; i++)
		{
			printf("%d ", list[i]);
		}
		printf("\n");
		return;
	}

	else {
		for (int i = 1; i <= m; i++)
		{
			if (!visited[i])
			{
				visited[i] = true;
				list[x] = i;
				dfs(x + 1, i + 1, m, n);
				visited[i] = false;
			}
		}
	}
}

int main()
{
	int m, n;
	scanf("%d %d", &m, &n);
	dfs(0, 0, m, n);
}
```
