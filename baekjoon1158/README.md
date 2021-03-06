## 백준 1158 요세푸스 문제 (C++)

### 문제 [문제보기](https://www.acmicpc.net/problem/1158)
- 요세푸스 문제는 다음과 같다.
- 1번부터 N번까지 N명의 사람이 원을 이루면서 앉아있고, 양의 정수 K(≤ N)가 주어진다. 
- 이제 순서대로 K번째 사람을 제거한다. 한 사람이 제거되면 남은 사람들로 이루어진 원을 따라 이 과정을 계속해 나간다. 
- 이 과정은 N명의 사람이 모두 제거될 때까지 계속된다. 원에서 사람들이 제거되는 순서를 (N, K)-요세푸스 순열이라고 한다. 
- 예를 들어 (7, 3)-요세푸스 순열은 <3, 6, 2, 7, 5, 1, 4>이다.
- N과 K가 주어지면 (N, K)-요세푸스 순열을 구하는 프로그램을 작성하시오.


### 입력
- 첫째 줄에 N과 K가 빈 칸을 사이에 두고 순서대로 주어진다. (1 ≤ K ≤ N ≤ 5,000)

### 출력
 - 예제와 같이 요세푸스 순열을 출력한다.


### 풀이법
 - 요세푸스 문제는 큐에서 입력된 K번째 배수의 원소를 출력하는 것이다.
 - 이는 원형 큐를 의미하는 것이라 할 수 있다. 하지만 원형 큐를 의미하는 STL이 존재하지 않는다.
 - 따라서 
 - 1번째, 2번째, ... ,K-1번째의 수를 pop했다가 push를 해주면, K번째 수가 가장 앞에 오게 되며, K번째 이전의 수는 모두 큐의 맨 뒤에 있게된다.
 - 따라서 맨 앞의 K번째 수만 pop을 할 수 있게 된다. 


### 코드
```
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <queue>

using namespace std;
int main()
{
	queue <int>q;
	int n, k;
	int temp;

	cin >> n >> k;
	
	for (int i = 1; i <= n; i++){
		q.push(i);
	}

	cout << "<";
	while (1){
    // K-1번째의 수까지만 pop한 후 push를 해야한다. (K번째 수는 다시 push해주지 않으므로)
		for (int i = 0; i < k - 1; i++) {
			temp = q.front();
			q.pop();
			q.push(temp);
		}
    // K번째 수를 pop 해준다. 이때 pop함수는 리턴 값이 없으므로 front함수를 이용해서 출력을 진행한 후 pop 연산을 진행한다.
		cout << q.front();
		q.pop();
    // 만약 큐 안에 있는 모든 원소가 출력되었으면 루프를 빠져나오도록 한다.
		if (!q.size()) break;
    // 다음 원소를 출력하기 위해서 , 을 출력해준다. 이때 ,만 있는 것이 아니고 공백 문자가 하나 더 있으므로 주의하도록 한다.
		cout << ", ";
	}
	cout << ">";

	return 0;
}
```
