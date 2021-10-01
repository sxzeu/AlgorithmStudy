#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <queue>

using namespace std;
int main()
{
	queue <int>q;
	int n, k;
	int temp;

	cin >> n >> k;
	
	for (int i = 1; i <= n; i++){
		q.push(i);
	}

	cout << "<";
	while (1)
	{
		for (int i = 0; i < k - 1; i++)
		{
			temp = q.front();
			q.pop();
			q.push(temp);
		}
		cout << q.front();
		q.pop();
		if (!q.size()) break;
		cout << ", ";
	}
	cout << ">";

	return 0;
}