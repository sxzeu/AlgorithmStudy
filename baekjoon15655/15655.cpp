#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int m, n;

vector <int>v;
int list[9];
bool visited[9] = { 0, };

void dfs(int num, int startidx)
{
	if (num == n)
	{
		for (int i = 0; i < n; i++)
		{
			cout << list[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = startidx; i < m; i++)
	{
		visited[i] = true;
		list[num] = v[i];
		dfs(num + 1, i + 1);
		visited[i] = false;

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

	dfs(0, 0);
}