#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int m, n;

vector <int>v;
int list[10];
bool visited[9] = { 0, };

void dfs(int x)
{
	if (x == n)
	{
		for (int i = 0; i < n; i++)
		{
			cout << list[i] << " ";
		}
		cout << "\n";
	}

	else
	{
		int before = -1;
		for (int i = 0; i < m; i++)
		{
			if (before!=v[i]) {
				list[x] = v[i];
				before = v[i];
				dfs(x + 1);
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
	dfs(0);
}