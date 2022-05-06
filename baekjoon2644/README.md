## 백준 2644 촌수계산

### 문제 [문제보기](https://www.acmicpc.net/problem/2644)
 - 우리 나라는 가족 혹은 친척들 사이의 관계를 촌수라는 단위로 표현하는 독특한 문화를 가지고 있다. 
 - 이러한 촌수는 다음과 같은 방식으로 계산된다. 
 - 기본적으로 부모와 자식 사이를 1촌으로 정의하고 이로부터 사람들 간의 촌수를 계산한다. 
 - 예를 들면 나와 아버지, 아버지와 할아버지는 각각 1촌으로 나와 할아버지는 2촌이 되고, 아버지 형제들과 할아버지는 1촌, 나와 아버지 형제들과는 3촌이 된다.
 - 여러 사람들에 대한 부모 자식들 간의 관계가 주어졌을 때, 주어진 두 사람의 촌수를 계산하는 프로그램을 작성하시오.

### 입력
 - 사람들은 1, 2, 3, …, n (1 ≤ n ≤ 100)의 연속된 번호로 각각 표시된다. 
 - 입력 파일의 첫째 줄에는 전체 사람의 수 n이 주어지고, 둘째 줄에는 촌수를 계산해야 하는 서로 다른 두 사람의 번호가 주어진다. 
 - 그리고 셋째 줄에는 부모 자식들 간의 관계의 개수 m이 주어진다. 넷째 줄부터는 부모 자식간의 관계를 나타내는 두 번호 x,y가 각 줄에 나온다. 
 - 이때 앞에 나오는 번호 x는 뒤에 나오는 정수 y의 부모 번호를 나타낸다.
 - 각 사람의 부모는 최대 한 명만 주어진다.

### 출력
 - 입력에서 요구한 두 사람의 촌수를 나타내는 정수를 출력한다. 
 - 어떤 경우에는 두 사람의 친척 관계가 전혀 없어 촌수를 계산할 수 없을 때가 있다. 이때에는 -1을 출력해야 한다.

### 풀이
 - 입력을 받아 벡터배열에 넣어준다. 
 - dfs를 통해 현재 탐색하고 있는 벡터배열의 모든 요소들을 dfs로 탐색한다. 
 - 목표 노드가 나오면 탐색을 종료하고 dfs 함수가 호출되었던 수를 출력해준다.
 - 만약 연결된 모든 요소들을 탐색해도 목표 노드에 도달할 수 없을 경우 -1을 출력해준다

### 코드
```
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, x, y;
vector<int> v[101];
int visited[101];
int result;

void dfs(int x, int y, int num)
{
	visited[x] = true;
	if (x == y) result = num;
	for (int i = 0; i < v[x].size(); i++)
	{
		int next = v[x][i];
		if (!visited[next]) dfs(next, y, num + 1);
	}
}

int main()
{
	cin >> n;
	cin >> x >> y;
	cin >> m;

	int a, b;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	dfs(x, y, 0);
	if (result != 0) cout << result;
	else cout << "-1";
}
```