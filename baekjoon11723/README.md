## 백준 11723 집합 (C++/BitMask)

### 문제 [문제보기](https://www.acmicpc.net/problem/11723)
- 비어있는 공집합 S가 주어졌을 때, 아래 연산을 수행하는 프로그램을 작성하시오.
- add x: S에 x를 추가한다. (1 ≤ x ≤ 20) S에 x가 이미 있는 경우에는 연산을 무시한다.
- remove x: S에서 x를 제거한다. (1 ≤ x ≤ 20) S에 x가 없는 경우에는 연산을 무시한다.
- check x: S에 x가 있으면 1을, 없으면 0을 출력한다. (1 ≤ x ≤ 20)
- toggle x: S에 x가 있으면 x를 제거하고, 없으면 x를 추가한다. (1 ≤ x ≤ 20)
- all: S를 {1, 2, ..., 20} 으로 바꾼다.
- empty: S를 공집합으로 바꾼다. 

### 입력
- 첫째 줄에 수행해야 하는 연산의 수 M (1 ≤ M ≤ 3,000,000)이 주어진다.
- 둘째 줄부터 M개의 줄에 수행해야 하는 연산이 한 줄에 하나씩 주어진다.

### 출력
 - check 연산이 주어질때마다, 결과를 출력한다.

### 풀이
 - '비트마스크'라는 개념을 처음 들어봤다. 그래서 비트마스크에 대해서 찾아보며 공부했다.
 - 집합의 max값이 20이므로 충분히 32비트인 int형으로 비트를 표현할 수 있다.
 - 비트마스크 연산을 적용하는 간단한 문제이다.
 - 중요한 점은 속도를 높여주기 위한 연산들을 미리 진행하지 않으면 시간초과가 뜬다.
 - 반드시 C언어와 C++의 버퍼를 분리해야하며 입출력 버퍼를 비우는 연산을 진행해야한다.

### 코드
```
#include <iostream>
#include <string>
using namespace std;

int main()
{
	  ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int m, num, BIT = 0;
	string order;
	cin >> m;


	while(m--)
	{
		cin >> order;
		if (order == "add")
		{
			cin >> num;
			BIT |= (1 << num);
		}
		else if (order == "remove")
		{
			cin >> num;
			BIT &= ~(1 << num);
		}
		else if (order == "check")
		{
			cin >> num;
			if (BIT & (1 << num)) cout << 1 << '\n';
			else cout << 0 << '\n';

		}
		else if (order == "toggle")
		{
			cin >> num;
			BIT ^= (1 << num);
		}
		else if (order == "all")
		{
			BIT = (1 << 21) - 1;
		}
		else if (order == "empty")
		{
			BIT = 0;
		}
	}
	return 0;
}
```
