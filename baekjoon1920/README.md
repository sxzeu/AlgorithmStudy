## 백준 1920 수찾기

### 문제 [문제보기](https://www.acmicpc.net/problem/1920)
- N개의 정수 A[1], A[2], …, A[N]이 주어져 있을 때, 이 안에 X라는 정수가 존재하는지 알아내는 프로그램을 작성하시오.

### 입력
- 첫째 줄에 자연수 N(1 ≤ N ≤ 100,000)이 주어진다. 다음 줄에는 N개의 정수 A[1], A[2], …, A[N]이 주어진다. 
 - 다음 줄에는 M(1 ≤ M ≤ 100,000)이 주어진다. 
 - 다음 줄에는 M개의 수들이 주어지는데, 이 수들이 A안에 존재하는지 알아내면 된다. 
 - 모든 정수의 범위는 -231 보다 크거나 같고 231보다 작다.
 
### 출력
 - M개의 줄에 답을 출력한다. 존재하면 1을, 존재하지 않으면 0을 출력한다.

### 풀이
 -  첫 번째로 입력받은 배열에서 두 번째로 입력받은 배열의 원소들이 있는 지 체크하는 문제이다.
 -  첫 번째에서 입력받은 배열은 계속 참조가 되고 순서가 중요하지 않으므로 sort()함수를 이용해 정렬한다.
 -  STL에서 이분탐색을 지원하는 함수인 bineary_search()함수를 이용해 첫 번째 문자열에 탐색하고자 하는 값이 있는 지 결과를 출력한다. 

### 코드
```
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main()
{

	vector<int> v1;
	vector<int>v2;

	int n, m;
	int input;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> input;
		v1.push_back(input);
	}
	sort(v1.begin(), v1.end());
	
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> input;
		v2.push_back(input);
	}

	for (int i = 0; i < m ; i++) 
	{
		if (binary_search(v1.begin(), v1.end(), v2[i]))
		{
			cout << "1" << "\n";
		}
		else cout << "0" << "\n";
	}
	
}

```
