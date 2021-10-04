#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(){

	stack <char>st;
	string str;
	cin >> str;

	int len = str.length();
	int output = 0;

	for (int i = 0; i < len; i++)
	{
		if (str[i] == '(') st.push(str[i]);
		else if (str[i] == ')')
		{
			st.pop();
			if (str[i - 1] == '(') output += st.size();
			else output++;
		}
	}
	cout << output;
	return 0;
}

