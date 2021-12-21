## 백준 1182 부분수열의 합(C++/brute force)

### 문제 [문제보기](https://www.acmicpc.net/problem/1182)
 - N개의 정수로 이루어진 수열이 있을 때, 크기가 양수인 부분수열 중에서 그 수열의 원소를 다 더한 값이 S가 되는 경우의 수를 구하는 프로그램을 작성하시오.

### 입력
 - 첫째 줄에 정수의 개수를 나타내는 N과 정수 S가 주어진다. 
 - (1 ≤ N ≤ 20, |S| ≤ 1,000,000) 둘째 줄에 N개의 정수가 빈 칸을 사이에 두고 주어진다. 
 - 주어지는 정수의 절댓값은 100,000을 넘지 않는다.

### 출력
 - 첫째 줄에 합이 S가 되는 부분수열의 개수를 출력한다.

### 풀이법
 - 배열에 숫자를 입력받아 재귀를 통해 문제를 푼다.
 - 끝까지 탐색을 마쳤을 경우 함수는 리턴을 한다.
 - 또한 원하는 값이 찾아졌을 경우 cnt 값을 추가시킨다.
 - 현재 탐색중인 값이 추가 되지 않았을 경우와, 추가되었을 경우의 수로 재귀함수의 매개변수를 넣어 재귀호출한다.


### 코드
```
#include <iostream>
using namespace std;

int n, s;
int arr[21];
int cnt = 0;

void dfs(int x, int sum)
{

	if (x == n) return;
	if (sum+arr[x] == s) cnt++;

	dfs(x + 1, sum);
	dfs(x + 1, sum + arr[x]);
}

int main()
{
	cin >> n >> s;
	for (int i = 0; i < n; i++) cin >> arr[i];

	dfs(0, 0);
	cout << cnt << "\n";
	return 0;
}
```
