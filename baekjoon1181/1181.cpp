#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool compare(string a, string b) {
    if (a.size() == b.size()) return a < b;
    else return a.size() < b.size();
}

int main() {

    vector <string> input;

    string str;
    string tmp;

    int n;
    cin >> n;


    for (int i = 0; i < n; i++) {
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