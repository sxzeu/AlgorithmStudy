#define _CRT_SECURE_NO_WARNINGS 
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