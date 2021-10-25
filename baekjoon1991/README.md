## 백준 1991 트리 순회(C++/트리)

### 문제 [문제보기](https://www.acmicpc.net/problem/1991)
 - 이진 트리를 입력받아 전위 순회(preorder traversal), 중위 순회(inorder traversal), 후위 순회(postorder traversal)한 결과를 출력하는 프로그램을 작성하시오.
 - 예를 들어 위와 같은 이진 트리가 입력되면, 
 - 전위 순회한 결과 : ABDCEFG // (루트) (왼쪽 자식) (오른쪽 자식)
 - 중위 순회한 결과 : DBAECFG // (왼쪽 자식) (루트) (오른쪽 자식)
 - 후위 순회한 결과 : DBEGFCA // (왼쪽 자식) (오른쪽 자식) (루트)가 된다.

### 입력 
 - 첫째 줄에는 이진 트리의 노드의 개수 N(1 ≤ N ≤ 26)이 주어진다. 
 - 둘째 줄부터 N개의 줄에 걸쳐 각 노드와 그의 왼쪽 자식 노드, 오른쪽 자식 노드가 주어진다. 
 - 노드의 이름은 A부터 차례대로 알파벳 대문자로 매겨지며, 항상 A가 루트 노드가 된다.
 - 자식 노드가 없는 경우에는 .으로 표현한다.

### 출력
 - 첫째 줄에 전위 순회, 둘째 줄에 중위 순회, 셋째 줄에 후위 순회한 결과를 출력한다. 각 줄에 N개의 알파벳을 공백 없이 출력하면 된다.

### 풀이법
 - 구조체를 만들어 노드를 표현한다. 또한 노드의 최대 갯수는 26개이므로 길이가 26인 구조체 배열을 만든다.
 - 전위, 중위, 후위 탐색에 대한 함수를 각각 만들어 재귀를 진행시킨다.


### 코드

```
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

struct _node {
	int left, right;
}node[26];

void preorder(int start)
{
	cout << (char)(start + 'A');
	if (node[start].left != -1)
		preorder(node[start].left);
	if (node[start].right != -1)
		preorder(node[start].right);
	return;
}

void inorder(int start)
{
	if (node[start].left != -1)
		inorder(node[start].left);
	cout << (char)(start + 'A');
	if (node[start].right != -1)
		inorder(node[start].right);
	return;
}

void postorder(int start)
{
	if (node[start].left != -1)
		postorder(node[start].left);
	if (node[start].right != -1)
		postorder(node[start].right);
	cout << (char)(start + 'A');
	return;
}

int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < 26; ++i)
		node[i].left = node[i].right = -1;

	for (int i = 0; i < n; ++i) {
		char p, l, r;
		cin >> p >> l >> r;
		if (l != '.')
			node[p - 'A'].left = l - 'A';
		if (r != '.')
			node[p - 'A'].right = r - 'A';
	}
	preorder(0);
	cout << '\n';
	inorder(0);
	cout << '\n';
	postorder(0);

	return 0;
}
```
