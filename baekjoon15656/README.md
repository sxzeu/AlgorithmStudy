## 백준 15656 N과 M(7) (C++/brute force)

### 문제 [문제보기](https://www.acmicpc.net/problem/15656)
 - N개의 자연수와 자연수 M이 주어졌을 때, 아래 조건을 만족하는 길이가 M인 수열을 모두 구하는 프로그램을 작성하시오. 
 - N개의 자연수는 모두 다른 수이다.
 - N개의 자연수 중에서 M개를 고른 수열같은 수를 여러 번 골라도 된다.

### 입력
 - 첫째 줄에 N과 M이 주어진다. (1 ≤ M ≤ N ≤ 7)
 - 둘째 줄에 N개의 수가 주어진다. 
 - 입력으로 주어지는 수는 10,000보다 작거나 같은 자연수이다.
 
### 출력
 - 한 줄에 하나씩 문제의 조건을 만족하는 수열을 출력한다. 
 - 중복되는 수열을 여러 번 출력하면 안되며, 각 수열은 공백으로 구분해서 출력해야 한다.
 - 수열은 사전 순으로 증가하는 순서로 출력해야 한다

### 풀이법
 - DFS 깊이 우선 탐색을 이용해서 문제를 풀 수 있다. 
 - vector를 통해 문자열을 입력받은 후 sort함수를 통해 정렬해준다. 
 - 출력배열과 방문을 체크하는 배열을 만든다. 
 - 방문여부를 체크할 필요 없이 for 루프를 통해 배열에 넣어주면 된다.

### 코드
```
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int list[8] = { 0, };
vector<int> v;
int m, n;

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
        for (int i = 0; i < m; i++)
        {
            list[num] = v[i];
            dfs(num + 1);
        }
    }
}

int main()
{
    cin >> m >> n;
    int temp; 
    
    for (int i = 0; i < m; i++)
    {
        cin >> temp;
        v.push_back(temp);
    }
    sort(v.begin(), v.end());
    dfs(0);
}

```
