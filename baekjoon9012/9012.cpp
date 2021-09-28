#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <stack>

#define TRUE 1
#define FALSE 0
using namespace std;

//입력된 문장이vps인지 체크
int vps_checker(string str)
{
	stack<char> stc;
	int len = str.length();

	for (int i = 0; i < len; i++)
	{
		if (str[i] == '(') stc.push(str[i]);
		else {
			if (!stc.empty()) stc.pop();
			else return false;
		}
	}
	if (stc.empty()) return true;
}

int main()
{
	int n = 0;
	cin >> n;
	cin.ignore();

	for (int i = 0; i < n; i++) {
		string inputStr;
		cin >> inputStr;
		if (vps_checker(inputStr) == 1) cout << "YES" << "\n";
		else cout << "NO" << "\n";
	}
}