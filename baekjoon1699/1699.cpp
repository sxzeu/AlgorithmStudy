#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int dp[100001];

int min(int a, int b)
{
	if (a > b) return b;
	else return a;
}

int main()
{
	int n = 0;
	scanf("%d", &n);

	for (int i = 0; i <= n; i++)
		dp[i] = i;

	for (int i = 2; i <= n; i++) {
		for (int j = 2; j * j <= i; j++) {

			dp[i] = min(dp[i], dp[i - j * j] + 1);
		}
	}

	printf("%d\n", dp[n]);
	return 0;
}