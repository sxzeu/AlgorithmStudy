#include <iostream>
#include <queue>

using namespace std;

char board[100][100];
bool visited[101][101];
int length[101][101];

int n, m;

int dx[4] = { 0,0,1,-1 }; // x축 이동(열 이동)
int dy[4] = { 1,-1,0,0 }; // y축 이동(행 이동)

void bfs(int x, int y)
{
	visited[x][y] = true;

	queue<pair<int, int>> q;
	q.push(make_pair(x, y));

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;

		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int x_next = x + dx[i];
			int y_next = y + dy[i];

			if (0 <= x_next && x_next < n && 0 <= y_next && y_next < m)
			{
				if (board[x_next][y_next] == '1' && visited[x_next][y_next] == false)
				{
					length[x_next][y_next] = length[x][y] + 1;
					visited[x_next][y_next] = true;
					q.push(make_pair(x_next, y_next));
				}
			}
		}
	}

}



int main()
{
	cin >> n >> m;

	for (int i = 0; i < n; i++) cin >> board[i];

	bfs(0, 0);
	cout << (length[n - 1][m - 1])+1;
}