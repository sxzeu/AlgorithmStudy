## 백준 1260 DFS와 BFS (C++)

### 문제 [문제보기](https://www.acmicpc.net/problem/1260)
- 그래프를 DFS로 탐색한 결과와 BFS로 탐색한 결과를 출력하는 프로그램을 작성하시오. 
- 단, 방문할 수 있는 정점이 여러 개인 경우에는 정점 번호가 작은 것을 먼저 방문하고, 더 이상 방문할 수 있는 점이 없는 경우 종료한다. 
- 정점 번호는 1번부터 N번까지이다.

### 입력
- 첫째 줄에 정점의 개수 N(1 ≤ N ≤ 1,000), 간선의 개수 M(1 ≤ M ≤ 10,000), 탐색을 시작할 정점의 번호 V가 주어진다. 
- 다음 M개의 줄에는 간선이 연결하는 두 정점의 번호가 주어진다. 
- 어떤 두 정점 사이에 여러 개의 간선이 있을 수 있다. 입력으로 주어지는 간선은 양방향이다.

### 출력
 - 첫째 줄에 DFS를 수행한 결과를, 그 다음 줄에는 BFS를 수행한 결과를 출력한다. V부터 방문된 점을 순서대로 출력하면 된다.

### 풀이
 - dfs와 bfs를 구현해 사용한다.
 - int형 이중배열 map을 이용해 연결관계를 체크했다.
 - visited[]배열을 통해 노드의 방문 여부를 체크했다.


### 코드
```
#include <iostream>
#include <queue>
using namespace std;

int map[1001][1001];
bool visited[1001];

int n, m, v;

void reset()
{
	for (int i = 0; i <= n; i++)
	{
		visited[i] = false;
	}
}
void dfs(int x)
{
	visited[x] = true;
	cout << x << " ";

	for (int i = 1; i <= n; i++) {
		if (map[x][i] == 1 && visited[i] == 0) dfs(i);
	}
}

void bfs(int x)
{
	queue <int>q;
	q.push(x);
	visited[x] = true;
	cout << q.front() << " ";

	while (!q.empty()) {
		x = q.front();
		q.pop();

		for (int i = 1; i <= n; i++) {
			if (map[x][i] == 1 && visited[i] == 0) 
			{ 
				q.push(i);
				visited[i] = true;
				cout << i << " ";
			}
		}
	}
}

int main()
{
	cin >> n >> m >> v;

	int a, b;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;
		map[a][b] = 1;
		map[b][a] = 1;
	}

	reset();
	dfs(v);
	cout << '\n';

	reset();
	bfs(v);
	return 0;
}
```
