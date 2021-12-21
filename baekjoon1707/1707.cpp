#define _CRT_SECURE_NO_WARNINGS 

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