## 백준 1181 단어정렬(C++)

### 문제 [문제보기](https://www.acmicpc.net/problem/1181)
 - 알파벳 소문자로 이루어진 N개의 단어가 들어오면 아래와 같은 조건에 따라 정렬하는 프로그램을 작성하시오.
 - 길이가 짧은 것부터
 - 길이가 같으면 사전 순으로

### 입력
 - 첫째 줄에 단어의 개수 N이 주어진다. 
 - (1 ≤ N ≤ 20,000) 둘째 줄부터 N개의 줄에 걸쳐 알파벳 소문자로 이루어진 단어가 한 줄에 하나씩 주어진다. 
 - 주어지는 문자열의 길이는 50을 넘지 않는다.

### 출력
 - 조건에 따라 정렬하여 단어들을 출력한다. 
 - 단, 같은 단어가 여러 번 입력된 경우에는 한 번씩만 출력한다.

### 풀이법
 - vector 컨테이너를 통해 단어를 입력하고자 하는 수 만큼 입력받는다.
 - algorithm 헤더에 내장된 함수인 sort()함수를 이용해 단어를 정렬해 출력한다.
 - 이때 sort()함수를 사용하며, compare함수를 만들고 이용해 문제에서 제시된 출력기준을 충족시키며 단어들을 정렬한다.


### 코드
```
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(string a, string b) {
    if (a.size() == b.size()) return a < b;
    else return a.size() < b.size();
}

int main() {

    vector <string> input;
    int n;
    cin >> n;
    string tmp;

    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        input.push_back(str);
    }

    sort(input.begin(), input.end(), compare);

    for (int i = 0; i < n; i++) {
        if (tmp == input[i]) continue;
        tmp = input[i];
        cout << input[i] << '\n';
    }
    return 0;
}
```
