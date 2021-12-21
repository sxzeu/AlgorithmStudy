#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
using namespace std;

int n, s;
int arr[21];
int cnt = 0;

void dfs(int x, int sum)
{

	if (x == n) return;
	if (sum + arr[x] == s) cnt++;

	dfs(x + 1, sum);
	dfs(x + 1, sum + arr[x]);
}

int main()
{
	cin >> n >> s;
	for (int i = 0; i < n; i++) cin >> arr[i];

	dfs(0, 0);
	cout << cnt << "\n";
	return 0;
}