#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(string a, string b) {
	if (a.size() == b.size()) return a < b;
	else return a.size() < b.size();
}

int main() {

	vector <string> input;
	int n;
	cin >> n;
	string tmp;

	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		input.push_back(str);
	}

	sort(input.begin(), input.end(), compare);

	for (int i = 0; i < n; i++) {
		if (tmp == input[i]) continue;
		tmp = input[i];
		cout << input[i] << '\n';
	}
	return 0;
}