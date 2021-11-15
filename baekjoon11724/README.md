## 백준 11723 연결 요소의 개수 (C++)

### 문제 [문제보기](https://www.acmicpc.net/problem/11723)
- 방향 없는 그래프가 주어졌을 때, 연결 요소 (Connected Component)의 개수를 구하는 프로그램을 작성하시오.

### 입력
- 첫째 줄에 정점의 개수 N과 간선의 개수 M이 주어진다. 
- (1 ≤ N ≤ 1,000, 0 ≤ M ≤ N×(N-1)/2) 둘째 줄부터 M개의 줄에 간선의 양 끝점 u와 v가 주어진다. 
- (1 ≤ u, v ≤ N, u ≠ v) 같은 간선은 한 번만 주어진다.

### 출력
 - 첫째 줄에 연결 요소의 개수를 출력한다.

### 풀이법
 - 2차원 배열에 연결관계를 표시하고, 방문 여부를 체크하는 배열을 만들어 방문을 체크한다.
 - 만약 현재 탐색하는 노드와 연결되어있다면 모두 방문이 체크될 예정이다. 현재 탐색중인 노드와 연결되지 않았다면 현재 노드와 분리되어 있는 것이므로 갯수를 세준다.


### 코드
```
#include <iostream>
using namespace std;

#define MAX 1001

int n, m, result = 0;
bool board[MAX][MAX] = { 0, };
bool visited[MAX] = { 0, };

void solution(int x)
{
	visited[x] = true;
	for (int i = 1; i <= n; i++)
	{
		if (board[x][i] && !visited[i]) solution(i);
	}
}

int main()
{
	cin >> n >> m;

	int a, b;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;
		board[a][b] = true;
		board[b][a] = true;
	}

	for (int i = 1; i <= n; i++)
	{
		if (!visited[i])
		{
			result++;
			solution(i);
		}
	}

	cout << result;
	return 0;
}
```
