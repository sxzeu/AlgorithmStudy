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