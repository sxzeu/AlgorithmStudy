#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

long d[101][11];

void dp(int n)
{
	for (int i = 1; i <= 9; i++) {
		d[1][i] = 1;
	}

	for (int i = 2; i <= n; i++) {
		d[i][0] = d[i - 1][1];
		for (int j = 1; j <= 9; j++) {
			d[i][j] = (d[i - 1][j - 1] + d[i - 1][j + 1]) % 1000000000;
		}
	}
}



int main()
{
	int n;
	scanf("%d", &n);

	dp(n);
	long output = 0;
	for (int i = 0; i <= 9; i++)
	{
		output += d[n][i];
	}
	printf("%ld", output % 1000000000);

}