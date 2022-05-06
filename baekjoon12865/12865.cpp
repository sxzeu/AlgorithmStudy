#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int d[101][100001];
int w[101];
int v[101];

int main()
{
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		cin >> w[i] >> v[i];
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (j >= w[i]) d[i][j] = max(d[i - 1][j], d[i - 1][j - w[i]] + v[i]);
			else d[i][j] = d[i - 1][j];
		}
	}
	cout << d[n][m];
}