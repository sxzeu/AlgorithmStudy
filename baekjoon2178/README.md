## 백준 2178 미로탐색

### 문제 [문제보기](https://www.acmicpc.net/problem/2178)
- N×M크기의 배열로 표현되는 미로가 있다.

1	0	1	1	1	1
1	0	1	0	1	0
1	0	1	0	1	1
1	1	1	0	1	1
- 미로에서 1은 이동할 수 있는 칸을 나타내고, 0은 이동할 수 없는 칸을 나타낸다. 
- 이러한 미로가 주어졌을 때, (1, 1)에서 출발하여 (N, M)의 위치로 이동할 때 지나야 하는 최소의 칸 수를 구하는 프로그램을 작성하시오. 
- 한 칸에서 다른 칸으로 이동할 때, 서로 인접한 칸으로만 이동할 수 있다.
- 위의 예에서는 15칸을 지나야 (N, M)의 위치로 이동할 수 있다. 
- 칸을 셀 때에는 시작 위치와 도착 위치도 포함한다.

### 입력
- 첫째 줄에 두 정수 N, M(2 ≤ N, M ≤ 100)이 주어진다. 
- 다음 N개의 줄에는 M개의 정수로 미로가 주어진다. 
- 각각의 수들은 붙어서 입력으로 주어진다.

### 출력
 - 첫째 줄에 지나야 하는 최소의 칸 수를 출력한다. 
 - 항상 도착위치로 이동할 수 있는 경우만 입력으로 주어진다.

### 후기
 - [참고블로그 1](https://phil-baek.tistory.com/entry/%EB%B0%B1%EC%A4%80-2178-%EB%AF%B8%EB%A1%9C-%ED%83%90%EC%83%89-%ED%92%80%EC%9D%B4-C), [참고블로그 2](https://cocoon1787.tistory.com/115)
 - 위 두 개의 블로그 포스팅을 참조하며 문제를 풀어보았다. 
 - 미로찾기 문제를 단순 재귀로 푸는 것만 생각했었다. 하지만 bfs를 통해 문제를 풀면 더 간결하게 풀 수 있었다. 
 - dx,dy 리스트를 통해 이동 가능한 네가지의 위치를 쉽게 접근하는 발상을 배웠다.
 - pair 클래스를 이용해 인덱스를 쌍으로 관리하는 것을 배울 수 있었다.
 - 복잡하게 보일수록 오히려 기본개념에 충실하면 풀리는 문제인 것 같다.


### 코드
```
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
```
