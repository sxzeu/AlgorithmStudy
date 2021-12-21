#define _CRT_SECURE_NO_WARNINGS 
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