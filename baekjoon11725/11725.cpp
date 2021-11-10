#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#define MAX 100001

using namespace std;

vector <int> v[MAX];
bool visited[MAX];
int parent[MAX];

void find(int num)
{
	visited[num] = true;

	for (int i = 0; i < v[num].size(); i++)
	{
		int next = v[num][i];

		if (!visited[next]) {
			parent[next] = num; 
			find(next);
		}
	}
}
int main()
{
	int n;
	cin >> n;

	int a, b;
	for (int i = 1; i < n; i++)
	{
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	find(1);
	for (int i = 2; i <= n; i++)
	{
		cout << parent[i] << "\n";
	}
	return 0;
}