#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n; 

int input[21][21] = { -1, };
bool visited[21]= { 0, };

int count = 0;
int ans = 1000000;

void dfs(int x, int start)
{
	if (x == n / 2)
	{
		int start = 0, link = 0;
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= n; j++){
				if (visited[i]&& visited[j]) start += input[i][j];
				if (!visited[i]&& !visited[j]) link += input[i][j];
			}
		}
		int num = abs(start - link);
		if (ans > num) ans = num; //ÃÖ¼Ú°ª ±â·Ï
	}

	for (int i = start; i < n; i++){
		if (!visited[i]) {
			visited[i] = 1;
			dfs(x + 1, i + 1);
			visited[i] = 0;
		}
	}
}

int main()
{
	cin >> n; 
	
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) cin >> input[i][j];

	dfs(0, 1);

	cout << ans;
}