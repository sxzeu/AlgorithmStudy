#include <stdio.h>

int memo[1001];


int dp(int n)
{
	if (n == 1) return 1;
	if (n == 2) return 3;
	if (memo[n] != 0)return memo[n];
	return memo[n] = (dp(n - 1) + 2 * (dp(n - 2))) % 10007;
}

int main()
{
	int x;
	scanf("%d", &x);
	printf("%d", dp(x));
	return 0;
}