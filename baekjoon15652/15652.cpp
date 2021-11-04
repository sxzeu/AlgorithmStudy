#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>

using namespace std;

int m, n;

int list[9];


void dfs(int num,int start)
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
	
	for (int i = start; i <= m; i++)
	{
		list[num] = i;
		dfs(num + 1, i);
	}
}
int main()
{
	cin >> m >> n;
	dfs(0,1);
}