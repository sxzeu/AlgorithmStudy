## 백준 1707 이분 그래프 (C++)

### 문제 [문제보기](https://www.acmicpc.net/problem/1707)
- 그래프의 정점의 집합을 둘로 분할하여, 각 집합에 속한 정점끼리는 서로 인접하지 않도록 분할할 수 있을 때, 그러한 그래프를 특별히 이분 그래프 (Bipartite Graph) 라 부른다.
- 그래프가 입력으로 주어졌을 때, 이 그래프가 이분 그래프인지 아닌지 판별하는 프로그램을 작성하시오.


### 입력
- 입력은 여러 개의 테스트 케이스로 구성되어 있는데, 첫째 줄에 테스트 케이스의 개수 K가 주어진다. 
- 각 테스트 케이스의 첫째 줄에는 그래프의 정점의 개수 V와 간선의 개수 E가 빈 칸을 사이에 두고 순서대로 주어진다. 
- 각 정점에는 1부터 V까지 차례로 번호가 붙어 있다. 
- 이어서 둘째 줄부터 E개의 줄에 걸쳐 간선에 대한 정보가 주어지는데, 각 줄에 인접한 두 정점의 번호 u, v (u ≠ v)가 빈 칸을 사이에 두고 주어진다. 

### 출력
 - K개의 줄에 걸쳐 입력으로 주어진 그래프가 이분 그래프이면 YES, 아니면 NO를 순서대로 출력한다.


### 풀이법
 - 현재 vector push_back에서 에러가 나는데 왜 나는지 모르겠다... 다른 문제도 다 이렇게 풀었는데 어디가 문제인지 파악이 안되니 추후 수정예정


### 코드
```
#include <iostream>
#include <vector>

using namespace std;

#define MAX 20001
#define BLUE 1
#define RED 2

vector<int> g[MAX];
int visited[MAX] = { 0, };
int k, v, e; 

void dfs(int x)
{
	if (!visited[x]) visited[x] = RED;

	int len = g[x].size();
	for (int i = 0; i < len; i++)
	{
		int num = g[x][i];
		if (!visited[num])
		{
			if (visited[x] == RED) visited[num] = BLUE;
			else if (visited[x] == BLUE) visited[num] = RED;
		}
		dfs(num);
	}
}

void printresult()
{
	int result = -1;
	for (int i = 1; i <= v; i++)
	{
		int len = g[i].size();
		for (int j = 0; j < len; i++)
		{
			int num = g[i][j];
			if (visited[i] == visited[num]) result = 0;
		}
	}
	if (result != 0) result = 1;

	if (result == 1) cout << "NO" << "\n";
	else if (result == 0) cout << "YES" << "\n";
}

void solution(int x)
{
	for (int i = 1; i <= x; i++) if (!visited[i]) dfs(i);
}

void clear(int x)
{
	for (int i = 1; i <= x; i++) {
		g[i].clear();
		visited[i] = 0;
	}
}

int main()
{
	cin >> k;

	for (int i = 0; i < k; i++)
	{
		cin >> v >> e;

		for (int j = 0; j < e; j++)
		{
			int a, b;
			cin >> a >> b;
			g[a].push_back(b);
			g[b].push_back(a);
		}

		solution(v);
		printresult();
		clear(v);
	}
	return 0;
}
```
