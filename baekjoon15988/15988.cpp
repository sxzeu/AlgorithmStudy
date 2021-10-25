#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

long long d[1000001];

void dp()
{
	for (int i = 4; i <= 1000000; i++)
	{
		d[i] = (d[i - 1] + d[i - 2] + d[i - 3]) % 1000000009;
	}
}

int main()
{
	int n;
	scanf("%d", &n);

	d[1] = 1;
	d[2] = 2;
	d[3] = 4;

	dp();
	int num;
	for (int j = 0; j < n; j++)
	{
		scanf("%d", &num);
		printf("%lld\n", d[num]);
	}

	return 0;
}