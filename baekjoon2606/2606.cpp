#include <iostream>
#include <vector>

using namespace std;

vector <int> v[100];
bool visited[100];
int cnt = 0;

void dfs(int x)
{
	visited[x] = true;
	for (int i = 0; i < v[x].size(); i++)
	{
		int next = v[x][i];
		if (!visited[next]) {
			dfs(next);
			cnt++;
		}
	}
}

int main()
{
	int n, m;
	cin >> n;
	cin >> m;

	int a, b;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	dfs(1);
	cout << cnt << '\n';
	
}