#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

bool visited[9] = { 0, };
int list[9] = { 0, };

void dfs(int x, int idx, int m, int n)
{
	if (x == n)
	{
		for (int i = 0; i < n; i++)
		{
			printf("%d ", list[i]);
		}
		printf("\n");
		return;
	}

	else {
		for (int i = 1; i <= m; i++)
		{
			if (!visited[i])
			{
				visited[i] = true;
				list[x] = i;
				dfs(x + 1, i + 1, m, n);
				visited[i] = false;
			}
		}
	}
}

int main()
{
	int m, n;
	scanf("%d %d", &m, &n);
	dfs(0, 0, m, n);
}