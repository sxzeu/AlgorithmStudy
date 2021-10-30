## 백준 15650 N과 M(2) (C++/brute force)

### 문제 [문제보기](https://www.acmicpc.net/problem/15650)
 - 자연수 N과 M이 주어졌을 때, 아래 조건을 만족하는 길이가 M인 수열을 모두 구하는 프로그램을 작성하시오.
 - 1부터 N까지 자연수 중에서 중복 없이 M개를 고른 수열
 - 고른 수열은 오름차순이어야 한다.

### 입력
 - 첫째 줄에 자연수 N과 M이 주어진다. (1 ≤ M ≤ N ≤ 8)

### 출력
 - 한 줄에 하나씩 문제의 조건을 만족하는 수열을 출력한다. 
 - 중복되는 수열을 여러 번 출력하면 안되며, 각 수열은 공백으로 구분해서 출력해야 한다.
 - 수열은 사전 순으로 증가하는 순서로 출력해야 한다.


### 풀이법
 - DFS 깊이 우선 탐색을 이용해서 문제를 풀 수 있다. 
 - 방문 여부를 기록할 배열과 내용을 출력하기 위한 배열이 필요하다.
 - void dfs(int num)함수를 구현해 num번째에 들어갈 것을 구할 수 있다.
 - 이때 dfs(0)을 넣으면 list[0]번째에 들어갈 값들을 else 블록의 for 구문을 통해 1부터 m까지 모두 구하게 된다.


### m=3, n=2가 입력되었다고 가정한 후 dfs(0)의 실행 순서에 대해 생각하자면
1. num !=n 이므로 else 블록의 for 구문으로 간다.
2. j=1이고, visited배열을 false로 초기화 해두었으므로 if블록이 실행된다.
3. visited[1] = true가 되고, list[0] = 1이 된다.(0번째로 방문한 숫자는 1이 된다.)
4. 그리고 dfs(0+1)을 호출한다.
5. dfs(1)의 경우에도 num!=n이므로 else블록의 for구문으로 간다.
6. visited[1]은 현재 true이므로 for 구문이 하나 넘어가, j=2가 된다.
7. visited[2]는 false이므로 if블록이 실행된다.
8. visted[2]가 true, list[1]이 2가 된다. 그리고 dfs(2)이 호출된다.
9. dfs(2)을 호출 시 num==n이므로 if 블록이 실행되어 값이 출력된 후, 리턴된다.
10. 리턴이 되면 다시 dfs(1)의 j=2인 for블록으로 돌아가 visited[2]가 false가 된다.
11. 그리고 10번의 for블록에서 j=3이 되어 visited[3]= true, list[1]=3 , dfs(2)가 호출되어 값이 출력된 후 리턴된다.
12. dfs(1)의 for루프가 모두 끝났으므로 dfs(0)으로 돌아간다. 
13. dfs(0)에서 visited[1]이 false가 되고, j=2가 된다.
14. visited[2]는 true, list[0]=2가 된 후 dfs(1)을 호출하며 반복된다. 
 
 - dfs의 개념에 대해서는 이해하고 있었으나 dfs에 대한 문제를 많이 풀어보지 않아서 어떻게 해결해야할 지에 대해 고민이 많았다. 
 - 가장 중요한 것은 dfs()함수가 계속 호출되도록 재귀를 구현하는 것과 dfs() 함수의 탈출 조건을 정하는 것이라는 생각을 할 수 있는 문제였다.



### 코드
```
#include <iostream>

using namespace std;

int m, n;

int list[9];
bool visited[9] = { 0, };

void dfs(int num)
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
	else
	{
		for (int j = 1; j <= m; j++)
		{
			if (!visited[j]) {
				visited[j] = true;
				list[num] = j;
				dfs(num + 1);
				visited[j] = false;
			}
		}
	}
}
int main()
{
	cin >> m >> n;
	dfs(0);
}
```
