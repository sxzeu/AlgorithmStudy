## 백준 2667 단지번호붙이기

### 문제 [문제보기](https://www.acmicpc.net/problem/2667)
- <그림 1>과 같이 정사각형 모양의 지도가 있다. 1은 집이 있는 곳을, 0은 집이 없는 곳을 나타낸다. 
- 철수는 이 지도를 가지고 연결된 집의 모임인 단지를 정의하고, 단지에 번호를 붙이려 한다. 여기서 연결되었다는 것은 어떤 집이 좌우, 혹은 아래위로 다른 집이 있는 경우를 말한다. 
- 대각선상에 집이 있는 경우는 연결된 것이 아니다. 
- <그림 2>는 <그림 1>을 단지별로 번호를 붙인 것이다. 
- 지도를 입력하여 단지수를 출력하고, 각 단지에 속하는 집의 수를 오름차순으로 정렬하여 출력하는 프로그램을 작성하시오.

### 입력
- 첫 번째 줄에는 지도의 크기 N(정사각형이므로 가로와 세로의 크기는 같으며 5≤N≤25)이 입력되고, 그 다음 N줄에는 각각 N개의 자료(0혹은 1)가 입력된다.

### 출력
 - 첫 번째 줄에는 총 단지수를 출력하시오. 그리고 각 단지내 집의 수를 오름차순으로 정렬하여 한 줄에 하나씩 출력하시오.

### 풀이법
 - 이중 루프를 통해 지도 내 dfs를 실행가능한 모든 곳 (아직 방문 않음+ 1로 방문이 가능함)에 dfs를 실행한다.
 - 대각선 경로로는 이동이 불가능 하므로 상하좌우로 이동 가능하도록 dx배열과 dy배열을 만들어 준다. 
 - dx dy배열의 길이만큼 루프를 돌며 만약 입력한 지도의 크기 범위안에 있으며 탐색할 부분이 아직 방문되지 않았으며 1이라면 dfs를 실행한다.
 - 단지 수를 세서 벡터에 push_back해준다. 단지의 수는 dfs가 모두 끝난 후 이 벡터에 들어있는 내용물의 수를 출력해준다. 
 - 벡터를 오름차순으로 정렬해 벡터 안에 있는 것들을 출력한다

### 코드
```
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string map[25];
bool visited[25][25] = { false, };

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1,-1, 0,0 };

int num_h = 0; // 아파트 단지 내 가구의 수 
int n;

vector<int> num; // 단지 내 가구의 수 벡터로 관리(정렬 출력 위해)

void dfs(int x, int y)
{
	visited[x][y] = true; 
	//cout << "dfs 실행 " << x << " "<< y << "\n";

	for (int i = 0; i < 4; i++)
	{
		int next_x = x + dx[i];
		int next_y = y + dy[i];

		if (next_x < n && next_x>=0 && next_y < n && next_y>=0)
		{
			if (map[next_x][next_y] == '1' && !visited[next_x][next_y])
			{
				//cout << "if에 들어옴 " << next_x << " " << next_y << "\n";
				num_h++;
				dfs(next_x, next_y);
			}
		}
	}
}

int main()
{
	cin >> n;

	for (int i = 0; i < n; i++) cin >> map[i];

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (map[i][j] == '1' && visited[i][j] == 0)
			{
				num_h = 1; 
				dfs(i, j);
				//cout << "dfs 실행 완료 " << i << " " << j  << "\n";
				num.push_back(num_h);
			}
		}
	}

	sort(num.begin(), num.end());

	cout << num.size() << "\n";
	for (int i = 0; i < num.size(); i++)
	{
		cout <<num[i] << "\n";
	}
}
```
