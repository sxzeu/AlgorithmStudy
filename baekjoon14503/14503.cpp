#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int map[51][51] = { -1, };
bool visited[51][51] = { 0, };

int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };

int m, n;
int r, c, d;
int sum = 0;

int turn(int d)
{
	if (d == 0) return 3;
	else if (d == 1) return 0;
	else if (d == 2) return 1;
	else if (d == 3) return 2;
}

void dfs(int x, int y, int d, int sum)
{
	for (int i = 0; i < 4; i++)
	{
		int nd = turn(d);
		int nx = x + dx[nd];
		int ny = y + dy[nd];

		if(map[nx][ny]==0) 
	}
	if (!visited[x][y])
	{

	}
}

int main()
{
	cin >> m >> n;
	cin >> r >> c >> d;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> map[i][j];
		}
	}

	dfs(r, c, d, sum);

}