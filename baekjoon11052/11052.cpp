#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int d[1001];
int card[1001];

int max(int a, int b)
{
	if (a > b) return a;
	else return b;
}
int dp(int x)
{
	d[1] = card[1];

	for (int i = 2; i <= x; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			d[i] = max(d[i], d[i - j] + card[j]);
		}
	}
	return d[x];
}

int main()
{
	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &card[i]);
	}

	printf("%d", dp(n));
}