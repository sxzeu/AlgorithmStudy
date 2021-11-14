#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <algorithm>
using namespace std;

char arr[16];
bool visited[16] = { 0, };
bool aeiou[16] = { 0, };
char list[16];
int l, c;

void dfs(int x, int prev, int ja, int mo)
{
	if (x == l)
	{
		if (mo >= 1 && ja >= 2) {
			for (int i = 0; i < l; i++) cout << list[i];
			cout << "\n";
			return;
		}
	}

	for (int i = prev + 1; i < c; i++)
	{
		list[x] = arr[i];
		if (aeiou[i]) dfs(x + 1, i, ja, mo + 1);
		else dfs(x + 1, i, ja + 1, mo);
	}
}


int main()
{
	cin >> l >> c;
	for (int i = 0; i < c; i++) cin >> arr[i];
	sort(arr, arr + c);

	for (int i = 0; i < c; ++i) {
		if (arr[i] == 'a' || arr[i] == 'e' || arr[i] == 'i' || arr[i] == 'o' || arr[i] == 'u')
			aeiou[i] = true;
	}
	dfs(0, -1, 0, 0);
	return 0;
}