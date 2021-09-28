#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
	int n = 0; 
	cin >> n;

	cin.ignore();

	for (int i = 0; i < n; i++)
	{
		string input = "";
		stack <char> st;

		getline(cin, input);
		input += ' ';

		for (int j = 0; j <= input.size(); j++)
		{
			if (input[j] == ' ') {
				while (!st.empty())
				{
					cout << st.top();
					st.pop();
				}
				cout << input[j];
			}
			else 
				if (input[j] != ' ') {
				st.push(input[j]);
			}
		}
		cout << "\n";
	}

}


