## 백준 10845 큐 (C++)

### 문제 [문제보기](https://www.acmicpc.net/problem/10845)
- 정수를 저장하는 큐를 구현한 다음, 입력으로 주어지는 명령을 처리하는 프로그램을 작성하시오.

- 명령은 총 여섯 가지이다.

- push X: 정수 X를 큐에 넣는 연산이다.
- pop: 큐에서 가장 앞에 있는 정수를 빼고, 그 수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
- size: 큐에 들어있는 정수의 개수를 출력한다.
- empty: 큐가 비어있으면 1, 아니면 0을 출력한다.
- front: 큐의 가장 앞에 있는 정수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
- back: 큐의 가장 뒤에 있는 정수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.


### 입력
- 첫째 줄에 주어지는 명령의 수 N (1 ≤ N ≤ 10,000)이 주어진다. 
- 둘째 줄부터 N개의 줄에는 명령이 하나씩 주어진다. 
- 주어지는 정수는 1보다 크거나 같고, 100,000보다 작거나 같다. 
- 문제에 나와있지 않은 명령이 주어지는 경우는 없다.

### 출력
 - 출력해야하는 명령이 주어질 때마다, 한 줄에 하나씩 출력한다.


### 풀이법
 - c++의 STL을 이용해 에러가 나는 조건을 막으며 문제를 푼다.
 - ex) 큐의 크기가 0인 상황에서 pop명령을 입력시 에러가 난다. 따라서 문제에서 주어진 출력값인 -1을 출력하도록 한다.


### 코드
```
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <queue>

using namespace std;


int main()
{
	int n;
	cin >> n;

	queue<int> q;
	int num;

	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;

		if (str == "push") {
			int data;
			cin >> data;
			q.push(data);
		}
		else if (str == "pop")
		{
			if(q.size() == 0) cout << "-1\n";
			else {
				cout << q.front() << "\n";
				q.pop();
			}
		}
		else if (str == "size")
		{
			cout << q.size() << "\n";
		}
		else if (str == "empty")
		{
			cout << q.empty() << "\n";
		}
		else if (str == "front")
		{
			if (q.size() == 0) cout << "-1\n";
			else cout << q.front() << "\n";
		}
		else if (str == "back")
		{
			if (q.size() == 0) cout << "-1\n";
			else cout << q.back() << "\n";
		}
	}
}
```
