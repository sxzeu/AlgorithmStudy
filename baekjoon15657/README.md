## 백준 15657 N과 M(8) (C++/brute force)

### 문제 [문제보기](https://www.acmicpc.net/problem/15657)
 - N개의 자연수와 자연수 M이 주어졌을 때, 아래 조건을 만족하는 길이가 M인 수열을 모두 구하는 프로그램을 작성하시오. 
 - N개의 자연수는 모두 다른 수이다.
 - N개의 자연수 중에서 M개를 고른 수열
 - 같은 수를 여러 번 골라도 된다.
 - 고른 수열은 비내림차순이어야 한다.
 - 길이가 K인 수열 A가 A1 ≤ A2 ≤ ... ≤ AK-1 ≤ AK를 만족하면, 비내림차순이라고 한다.

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
 - 탐색을 할 때 시작할 숫자를 정해주면 된다.

### 코드
```
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int list[8] = { 0, };
vector<int> v;
int m, n;

void dfs(int num, int start)
{
	if (num == n)
	{
		for (int i = 0; i < n; i++)
		{
			cout << list[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = start ; i < m; i++)
	{
		list[num] = v[i];
		dfs(num + 1, i);
	}
}


int main()
{
	cin >> m >> n;
	
	int temp; 
	for (int i = 0; i < m; i++)
	{
		cin >> temp;
		v.push_back(temp);
	}
	sort(v.begin(), v.end());
	dfs(0,0);
  return 0;
}
```
