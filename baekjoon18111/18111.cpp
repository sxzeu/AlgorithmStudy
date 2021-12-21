#define _CRT_SECURE_NO_WARNINGS 

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX 502

int board[MAX][MAX];
int cnt[MAX];

int select_num()
{
	int num[2] = { 0, }; // 0에는 숫자, 1에는 갯수 기록
	for (int i = 0; i < MAX; i++)
	{
		if (num[1] < cnt[i])
		{
			num[0] = i;
			num[1] = cnt[i];
		}

	}
	return num[0];
}

int main()
{
	int n, m, b;
	cin >> n >> m >> b;


	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> board[i][j];
			cnt[board[i][j]]++;
		}
	}

	int select = select_num();
	
	int result = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			int num = board[i][j] - select;
			if (num != 0)
			{
				if (num > 0) result += num * 2;
				else result -= num * 1;
			}
		}
	}
	cout << result << " " << select;
}