#define _CRT_SECURE_NO_WARNINGS 

#include <iostream>
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