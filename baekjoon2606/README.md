## 백준 2606 바이러스(C++/DFS)

### 문제 [문제보기](https://www.acmicpc.net/problem/2606)
 - 신종 바이러스인 웜 바이러스는 네트워크를 통해 전파된다. 한 컴퓨터가 웜 바이러스에 걸리면 그 컴퓨터와 네트워크 상에서 연결되어 있는 모든 컴퓨터는 웜 바이러스에 걸리게 된다.
 - 예를 들어 7대의 컴퓨터가 <그림 1>과 같이 네트워크 상에서 연결되어 있다고 하자. 
 - 1번 컴퓨터가 웜 바이러스에 걸리면 웜 바이러스는 2번과 5번 컴퓨터를 거쳐 3번과 6번 컴퓨터까지 전파되어 2, 3, 5, 6 네 대의 컴퓨터는 웜 바이러스에 걸리게 된다. 
 - 하지만 4번과 7번 컴퓨터는 1번 컴퓨터와 네트워크상에서 연결되어 있지 않기 때문에 영향을 받지 않는다.
 - 어느 날 1번 컴퓨터가 웜 바이러스에 걸렸다. 
 - 컴퓨터의 수와 네트워크 상에서 서로 연결되어 있는 정보가 주어질 때, 1번 컴퓨터를 통해 웜 바이러스에 걸리게 되는 컴퓨터의 수를 출력하는 프로그램을 작성하시오.

### 입력
 - 첫째 줄에는 컴퓨터의 수가 주어진다. 컴퓨터의 수는 100 이하이고 각 컴퓨터에는 1번 부터 차례대로 번호가 매겨진다. 
 - 둘째 줄에는 네트워크 상에서 직접 연결되어 있는 컴퓨터 쌍의 수가 주어진다. 
 - 이어서 그 수만큼 한 줄에 한 쌍씩 네트워크 상에서 직접 연결되어 있는 컴퓨터의 번호 쌍이 주어진다.

### 출력
 - 1번 컴퓨터가 웜 바이러스에 걸렸을 때, 1번 컴퓨터를 통해 웜 바이러스에 걸리게 되는 컴퓨터의 수를 첫째 줄에 출력한다.

### 풀이법
 - 인접리스트를 입력받으므로 인접리스트를 만들고, 예시 그림에 사이클이 존재하므로 방문을 체크하는 리스트를 따로 만들어준다. 
 - 인접한 두 노드를 입력받으며, 두 노드의 인접리스트에 서로를 추가해준다. 
 - 1번 컴퓨터가 감염이 된 상황을 가정하고 있으므로, dfs를 이용해 1번 노드와 연결되어있는 노드의 갯수를 센다.


### 코드
```
#include <iostream>
#include <vector>

using namespace std;

vector <int> v[100];
bool visited[100];
int cnt = 0;

void dfs(int x)
{
	visited[x] = true;
	for (int i = 0; i < v[x].size(); i++)
	{
		int next = v[x][i];
		if (!visited[next]) {
			dfs(next);
			cnt++;
		}
	}
}

int main()
{
	int n, m;
	cin >> n;
	cin >> m;

	int a, b;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	dfs(1);
	cout << cnt << '\n';
	
}
```