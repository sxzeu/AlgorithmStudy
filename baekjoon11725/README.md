## 백준 11725 트리의 부모 찾기(C++/tree)

### 문제 [문제보기](https://www.acmicpc.net/problem/11725)
- 루트 없는 트리가 주어진다. 
- 이때, 트리의 루트를 1이라고 정했을 때, 각 노드의 부모를 구하는 프로그램을 작성하시오.

### 입력
- 첫째 줄에 노드의 개수 N (2 ≤ N ≤ 100,000)이 주어진다.
- 둘째 줄부터 N-1개의 줄에 트리 상에서 연결된 두 정점이 주어진다.

### 출력
 - 첫째 줄부터 N-1개의 줄에 각 노드의 부모 노드 번호를 2번 노드부터 순서대로 출력한다.


### 풀이법
 - 벡터 리스트를 만들어 트리를 관리하도록 했다.
 - 또한 방문을 체크하는 레스트와, 찾은 부모를 기록하는 리스트를 만들었다.
 - 두 값을 입력받으면, 입력 받은 값 두 개는 서로 연결되어 있다고 할 수 있으므로 각자의 벡터 리스트를 인덱스로 접근해 서로 push_back() 연산을 진행해 트리를 구성한다.
 - find()함수를 통해 부모를 찾게 했으며, 이 함수는 찾고자하는 인덱스의 값을 매개변수로 입력받는다.
 - 방문 여부를 체크한다. 현재 탐색중인 노드의 값에 연결된 노드들의 벡터리스트를 탐색한다.
 - 만약 방문되지 않았던 노드라면 부모리스트에 기록한 후, 이 노드를 매개변수로 부모를 찾는 노드를 실행한다.


### 코드
```
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
```
