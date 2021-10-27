#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;

int a[5000001];
int b[5000001];


int main()
{

	int n, m;

	cin >> n; 
	int temp;
	for(int i=0; i< n; i++)
	{
		cin >> temp;
		a[i] = temp;
	}
	sort(a, a + n);
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> temp;
		b[i] = temp;
	}

	int find;
	for (int i = 0; i < m; i++)
	{
		find = 0;
		for (int j = 0; j < n; j++)
		{
			if (b[i] < a[j]) break;
			if (b[i] == a[j]) {
				cout << "1 ";
				find = 1;
				break;
			}
		}
		if (find == 0)cout << "0 ";
	}
}
