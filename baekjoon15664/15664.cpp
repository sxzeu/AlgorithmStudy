#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int m, n;

vector <int>v;
int list[10];
bool visited[9] = { 0, };

void dfs(int x, int start)
{
	if (x == n + 1)
	{
		for (int i = 1; i < n + 1; i++)
		{
			cout << list[i] << " ";
		}
		cout << "\n";
	}

	else
	{
		int before = -1;
		for (int i = start; i < m; i++)
		{
			if (!visited[i] && v[i] >= list[x - 1] && before < v[i])
			{
				before = v[i];
				visited[i] = true;
				list[x] = v[i];
				dfs(x + 1, start + 1);
				visited[i] = false;
			}
		}
	}
}
int main()
{
	cin >> m >> n;

	int input;
	for (int i = 0; i < m ; i++)
	{
		cin >> input;
		v.push_back(input);
	}
	sort(v.begin(), v.end());
	list[0] = -1;
	dfs(1, 0);
}