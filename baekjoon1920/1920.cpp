#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main()
{
	// 입력
	vector<int> v1;
	// 체크
	vector<int>v2;

	int n, m;
	int input;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> input;
		v1.push_back(input);
	}
	sort(v1.begin(), v1.end());
	
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> input;
		v2.push_back(input);
	}

	for (int i = 0; i < m ; i++) 
	{
		if (binary_search(v1.begin(), v1.end(), v2[i]))
		{
			cout << "1" << "\n";
		}
		else cout << "0" << "\n";
	}
	
}