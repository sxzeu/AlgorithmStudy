#include <iostream>
#include <string>
#include <stack>
using namespace std;

void stack_pop(stack<char> s)
{
	while (!s.empty())
	{
		cout << s.top();
		s.pop();
	}
}

int main()
{
	stack <char> st;
	string input;
	cin >> input;

	int len = input.size();
	bool istag = false;

	for (int i = 0; i < len; i++)
	{

		if (input[i] == '<')
		{
			istag = true;
			if (!st.empty()) stack_pop(st);
			else cout << input[i];
		}
		else if (input[i] == '>') istag = false;
		else if (input[i] == ' ' && istag == false)
		{
			stack_pop(st);
			cout << " ";
		}
		else if (input[i] != ' ' && istag == false) st.push(input[i]);
	}

	return 0;
}