#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
	stack <char> st;
	string input;
	cin >> input;

	int len = input.length();
	bool istag = false;

	for (int i = 0; i < len; i++)
	{

		if (input[i] == '<')
		{
			if (!st.empty()) {
				while (st.empty())
				{
					cout << st.top();
					st.pop();
				}
			}
			istag = true;
		}
		if (input[i] == '>') istag = false;
		if (input[i] == ' ' && istag == false)
		{
			while (st.empty())
			{
				cout << st.top();
				st.pop();
			}
			cout << " ";
		}
		else if (input[i] != ' ' && istag == false) st.push(input[i]);
	}

	return 0;
}