#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int d[12];


int dp(int n)
{
	if (n == 1) return 1;
	if (n == 2) return 2;
	if (n == 3) return 4;
	if (d[n] != 0) return d[n];
	return d[n] = dp(n - 1) + dp(n - 2) + dp(n - 3);
}

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		printf("%d\n", dp(x));
	}
	return 0;
}