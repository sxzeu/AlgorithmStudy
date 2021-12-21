#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
using namespace std;

#define MAX 1001

int n, m, result = 0;
bool board[MAX][MAX] = { 0, };
bool visited[MAX] = { 0, };

void solution(int x)
{
	visited[x] = true;
	for (int i = 1; i <= n; i++)
	{
		if (board[x][i] && !visited[i]) solution(i);
	}
}

int main()
{
	cin >> n >> m;

	int a, b;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;
		board[a][b] = true;
		board[b][a] = true;
	}

	for (int i = 1; i <= n; i++)
	{
		if (!visited[i])
		{
			result++;
			solution(i);
		}
	}

	cout << result;
	return 0;
}