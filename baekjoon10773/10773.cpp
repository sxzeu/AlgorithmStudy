#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;

vector <int>v;

int main()
{
	int n;
	cin >> n;

	int input;
	for (int i = 0; i < n; i++)
	{
		cin >> input;
		if (input != 0)
		{
			v.push_back(input);
		}
		else if (input == 0)
		{
			v.pop_back();
		}
	}

	int sum = 0;
	for (int i = 0; i < v.size(); i++)
	{
		sum += v[i];
	}

	cout << sum;
}