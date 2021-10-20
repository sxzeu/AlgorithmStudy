#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
using namespace std;

int in[100001];
int d[100001];

int main() {
	int n;
	int sum;

	cin >> n;
	for (int i = 0; i < n; i++) {

		cin >> in[i];
		d[i] = in[i];
	}

	sum = in[0];

	for (int i = 0; i < n; i++) {

		d[i] = in[i];
		if (i == 0) continue;
		if (d[i] < d[i -1] + in[i]) {
			d[i] = d[i - 1] + in[i];
		}

		if (d[i] > sum) sum = d[i];
	}
	cout << sum << '\n';
}