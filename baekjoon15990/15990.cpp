#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

long long d[100001][4];
const int MAX = 100001;
const int mod = 1000000009;


void dp()
{
	d[1][1] = 1;
	d[2][2] = 1;
	d[3][3] = 1;
	d[3][2] = 1;
	d[3][1] = 1;

	for (int i = 4; i < MAX; i++)
	{
		if (i - 1 >= 0) {
			d[i][1] = (d[i - 1][2] + d[i - 1][3]) % mod;
		}
		if (i - 2 >= 0) {
			d[i][2] = (d[i - 2][1] + d[i - 2][3]) % mod;
		}
		if (i - 3 >= 0) {
			d[i][3] = (d[i - 3][1] + d[i - 3][2]) % mod;
		}
	}
}

int main()
{
	int n;
	scanf("%d", &n);

	dp();
	for (int i = 0; i < n; i++)
	{
		int num;
		scanf("%d", &num);
		printf("%d\n", (d[num][1] + d[num][2] + d[num][3]) % mod);

	}
	return 0;
}