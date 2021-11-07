## 백준 15663 N과 M(9) (C++/brute force)

### 문제 [문제보기](https://www.acmicpc.net/problem/15663)
 - N개의 자연수와 자연수 M이 주어졌을 때, 아래 조건을 만족하는 길이가 M인 수열을 모두 구하는 프로그램을 작성하시오.
 - N개의 자연수 중에서 M개를 고른 수열

### 입력
 - 첫째 줄에 N과 M이 주어진다. (1 ≤ M ≤ N ≤ 8)
 - 둘째 줄에 N개의 수가 주어진다. 
 - 입력으로 주어지는 수는 10,000보다 작거나 같은 자연수이다.
 
### 출력
 - 한 줄에 하나씩 문제의 조건을 만족하는 수열을 출력한다. 
 - 중복되는 수열을 여러 번 출력하면 안되며, 각 수열은 공백으로 구분해서 출력해야 한다.
 - 수열은 사전 순으로 증가하는 순서로 출력해야 한다.

### 풀이법
 - DFS 깊이 우선 탐색을 이용해서 문제를 풀 수 있다. 
 - vector를 통해 문자열을 입력받은 후 sort함수를 통해 정렬해준다. 
 - N과 M 문제의 이전 시리즈에 비해 정답률이 낮아서 긴장했는데 생각보다 쉽게 풀리는 문제이다.
 - 입력받은 벡터를 정렬 후 탐색을 진행하며, 이전에 방문했던 숫자와 현재 탐색하고자 하는 숫자가 같은 지 체크해주면 된다.

### 코드
```
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int m, n;

vector <int>v;
int list[9];
bool visited[9] = { 0, };

void dfs(int x)
{
	if (x == n)
	{
		for (int i = 0; i < n; i++)
		{
			cout << list[i] <<" ";
		}
		cout << "\n";
	}

	else
	{
		int before = -1;
		for (int i = 0; i < m; i++)
		{
			if (!visited[i]&& before!=v[i])
			{
				before = v[i];
				visited[i] = true;
				list[x] = v[i];
				dfs(x + 1);
				visited[i] = false;
			}
		}
	}
}
int main()
{
	cin >> m >> n;

	int input;
	for (int i = 0; i < m ; i++)
	{
		cin >> input;
		v.push_back(input);
	}
	sort(v.begin(), v.end());

	dfs(0);
}
```
