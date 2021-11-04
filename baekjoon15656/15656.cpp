#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int list[8] = { 0, };
vector<int> v;
int m, n;

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
		for (int i = 0; i < m; i++)
		{
			list[num] = v[i];
			dfs(num + 1);
		}
	}
}


int main()
{
	cin >> m >> n;
	
	int temp; 
	for (int i = 0; i < m; i++)
	{
		cin >> temp;
		v.push_back(temp);
	}
	sort(v.begin(), v.end());
	dfs(0);
}