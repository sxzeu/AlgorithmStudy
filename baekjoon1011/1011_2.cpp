#include <iostream>
#include <cmath>
using namespace std;


int main()
{
	int n; 
	long long a, b;

	cin >> n; 
	for (int i = 0; i < n; i++)
	{
		cin >> a >> b;
		double num = b - a;
		double numpow = sqrt(num);
		int pow = round(sqrt(num));

		if (numpow <= pow) cout << pow * 2 - 1 << "\n";
		else cout << pow * 2 << "\n";
	}
}