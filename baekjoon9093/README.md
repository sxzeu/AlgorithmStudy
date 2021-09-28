##백준 9093 단어 뒤집기 문제 (C++)
[새 탭에서 문제보기](https://www.acmicpc.net/problem/9093)


###문제
- 문장이 주어졌을 때, 단어를 모두 뒤집어서 출력하는 프로그램을 작성하시오. 단, 단어의 순서는 바꿀 수 없다. 단어는 영어 알파벳으로만 이루어져 있다.

###입력
- 첫째 줄에 테스트 케이스의 개수 T가 주어진다. 각 테스트 케이스는 한 줄로 이루어져 있으며, 문장이 하나 주어진다. 
- 단어의 길이는 최대 20, 문장의 길이는 최대 1000이다. 단어와 단어 사이에는 공백이 하나 있다.

###출력
 - 각 테스트 케이스에 대해서, 입력으로 주어진 문장의 단어를 모두 뒤집어 출력한다.


###풀이법
 - 문자열을 입력받은 후, c++의 stack std를 이용한다.
 - 띄어쓰기가 나올 때 까지 stack에 push를 한 후, 띄어쓰기가 나오면 stack에 들어있는 것을 모두 pop한다.


###코드
```
#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
	int n = 0; 
	cin >> n;

  // 버퍼를 미리 비워둔다
	cin.ignore();

	for (int i = 0; i < n; i++)
	{
  
		string input = "";
		stack <char> st;
  
    // 뒤집을 문자열을 입력 받는다 
		getline(cin, input);
		input += ' ';

		for (int j = 0; j <= input.size(); j++)
		{
      // 순차적으로 문자열을 스택에 넣다가 띄어쓰기가 나왔을 경우
			if (input[j] == ' ') {
        // 스택이 빌때까지 스택에 들어있는 것을 pop한다.
				while (!st.empty())
				{
          // 이때 cout<<st.pop();을 사용할 수 없는 이유는 pop함수는 리턴값이 없기 때문이다.
					cout << st.top();
					st.pop();
				}
        // 마지막까지 리턴을 꼼꼼히 해주어야한다. 그렇지 않으면 두 번째 이후로 진행시에 스택이 제대로 비워지지 않아 출력에 지장이 생긴다.
				cout << input[j];
			}
      // 띄어쓰기가 아직 나오지 않았을 경우
			else 
        // 현재 탐색중인 배열의 값이 ' '이 아닌지 다시 한 번 체크를 하고 스택에 넣어준다
				if (input[j] != ' ') st.push(input[j]);
		}
    // 다음 진행을 위해 다음 줄로 넘어간다.
		cout << "\n";
	}

}
```
