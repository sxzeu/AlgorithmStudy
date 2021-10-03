#include <iostream>
#include <string>
#include <stack>

using namespace std;

void stack_pop(stack<char> &s)
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
	getline(cin, input);

	int len = input.size();

	for (int i = 0; i < len; i++)
	{

		if (input[i] == '<')
		{
			stack_pop(st);
			while (1)
			{
				cout << input[i];
				if (input[i] == '>') break;
				i++;
			}
		}
		else if (input[i] == ' ')
		{
			stack_pop(st);
			cout << " ";
		}
		else { st.push(input[i]); }

	}
	stack_pop(st);
	return 0;
}