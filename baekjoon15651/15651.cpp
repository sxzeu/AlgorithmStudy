#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>

using namespace std;

int m, n;

int list[9];
bool visited[9] = { 0, };

void dfs(int num)
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
	else
	{
		for (int j = 1; j <= m; j++)
		{
			visited[j] = true;
			list[num] = j;
			dfs(num + 1);
			visited[j] = false;
		}
	}
}
int main()
{
	cin >> m >> n;
	dfs(0);
}