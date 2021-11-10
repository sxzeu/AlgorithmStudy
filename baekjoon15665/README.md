## 백준 15665 N과 M(11) (C++/brute force)

### 문제 [문제보기](https://www.acmicpc.net/problem/15665)
 - N개의 자연수와 자연수 M이 주어졌을 때, 아래 조건을 만족하는 길이가 M인 수열을 모두 구하는 프로그램을 작성하시오. 
 - N개의 자연수는 모두 다른 수이다.
 - N개의 자연수 중에서 M개를 고른 수열
 - 고른 수열은 오름차순이어야 한다.

### 입력
 - 첫째 줄에 N과 M이 주어진다. (1 ≤ M ≤ N ≤ 7)
 - 둘째 줄에 N개의 수가 주어진다. 
 - 입력으로 주어지는 수는 10,000보다 작거나 같은 자연수이다.
 
### 출력
 - 한 줄에 하나씩 문제의 조건을 만족하는 수열을 출력한다. 
 - 중복되는 수열을 여러 번 출력하면 안되며, 각 수열은 공백으로 구분해서 출력해야 한다.
 - 수열은 사전 순으로 증가하는 순서로 출력해야 한다.

### 풀이법
 - DFS 깊이 우선 탐색을 이용해서 문제를 풀 수 있다. 
 - vector를 통해 문자열을 입력받은 후 sort함수를 통해 정렬해준다. 
 - 이전에 체크했던 값과 현재 체크하고자 하는 값이 같지 않다면 기록한다.


### 코드
```
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int m, n;

vector <int>v;
int list[10];
bool visited[9] = { 0, };

void dfs(int x)
{
	if (x == n)
	{
		for (int i = 0; i < n; i++)
		{
			cout << list[i] << " ";
		}
		cout << "\n";
	}

	else
	{
		int before = -1;
		for (int i = 0; i < m; i++)
		{
			if (before!=v[i]) {
				list[x] = v[i];
				before = v[i];
				dfs(x + 1);
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
