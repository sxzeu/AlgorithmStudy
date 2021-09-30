#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <queue>

using namespace std;


int main()
{
	int n;
	cin >> n;

	queue<int> q;
	int num;

	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;

		if (str == "push") {
			int data;
			cin >> data;
			q.push(data);
		}
		else if (str == "pop")
		{
			if(q.size() == 0) cout << "-1\n";
			else {
				cout << q.front() << "\n";
				q.pop();
			}
		}
		else if (str == "size")
		{
			cout << q.size() << "\n";
		}
		else if (str == "empty")
		{
			cout << q.empty() << "\n";
		}
		else if (str == "front")
		{
			if (q.size() == 0) cout << "-1\n";
			else cout << q.front() << "\n";
		}
		else if (str == "back")
		{
			if (q.size() == 0) cout << "-1\n";
			else cout << q.back() << "\n";
		}
	}
}