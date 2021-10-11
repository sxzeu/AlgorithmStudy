#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(string a, string b) {
    if (a.size() == b.size()) {
        return a < b;
    }
    else {
        return a.size() < b.size();
    }
}
int main() {

    vector <string> input;
    string temp;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string word;
        cin >> word;
        input.push_back(word);
    }

    sort(input.begin(), input.end(), compare);

    for (int i = 0; i < n; i++) {
        if (temp == input[i])continue;
        cout << input[i] << '\n';
        temp = input[i];
    }
    return 0;
}