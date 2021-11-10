## 백준 13023 ABCDE (C++/DFS)

### 문제 [문제보기](https://www.acmicpc.net/problem/13023)
- BOJ 알고리즘 캠프에는 총 N명이 참가하고 있다. 
- 사람들은 0번부터 N-1번으로 번호가 매겨져 있고, 일부 사람들은 친구이다.
- 오늘은 다음과 같은 친구 관계를 가진 사람 A, B, C, D, E가 존재하는지 구해보려고 한다.
- A는 B와 친구다.
- B는 C와 친구다.
- C는 D와 친구다.
- D는 E와 친구다.
- 위와 같은 친구 관계가 존재하는지 안하는지 구하는 프로그램을 작성하시오.

### 입력
- 첫째 줄에 사람의 수 N (5 ≤ N ≤ 2000)과 친구 관계의 수 M (1 ≤ M ≤ 2000)이 주어진다.
- 둘째 줄부터 M개의 줄에는 정수 a와 b가 주어지며, a와 b가 친구라는 뜻이다. 
- (0 ≤ a, b ≤ N-1, a ≠ b) 같은 친구 관계가 두 번 이상 주어지는 경우는 없다.

### 출력
 - 문제의 조건에 맞는 A, B, C, D, E가 존재하면 1을 없으면 0을 출력한다.

### 풀이
 - 2차원 벡터를 통해 노드와 노드사이의 관계성을 표현한다.
 - dfs를 통해 연결된 노드의 방문을 체크하며 탐색을 진행한다.
 - 탐색을 시작하는 노드의 경우에도 방문을 체크하고 해제하는 과정을 반드시 진행해야한다.


### 코드
```
include <iostream>
#include <vector>

using namespace std;

#define MAX 2001

vector <int>v[MAX];
bool visited[MAX] = { 0, };
bool check = false;

void dfs(int idx, int count)
{
	visited[idx] = true;
	if (count == 4)
	{
		cout << 1;
		exit(0);
	}

	int next;
	for (int i = 0; i < v[idx].size(); i++)
	{
		next = v[idx][i];
		if (!visited[next]) {
			visited[next] = true;
			dfs(next, count + 1);
			visited[next] = false;
		}
	}
	visited[idx] = false;
}

int main()
{
	int n, m;
	cin >> m >> n;

	int a, b;
	for (int i = 0; i < n; i++)
	{
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	for (int i = 0; i < m; i++)
	{
		dfs(i, 0);
	}

	cout << 0;
	return 0;
}
```
