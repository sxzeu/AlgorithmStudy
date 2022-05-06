#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, x, y;
vector<int> v[101];
int visited[101];
int result;

void dfs(int x, int y, int num)
{
	visited[x] = true;
	if (x == y) result = num;
	for (int i = 0; i < v[x].size(); i++)
	{
		int next = v[x][i];
		if (!visited[next]) dfs(next, y, num + 1);
	}
}

int main()
{
	cin >> n;
	cin >> x >> y;
	cin >> m;

	int a, b;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	dfs(x, y, 0);
	if (result != 0) cout << result;
	else cout << "-1";
}