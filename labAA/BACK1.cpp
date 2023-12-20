#include <bits/stdc++.h>

using namespace std;

void print_result(vector<string>& strings) {
    reverse(strings.begin(), strings.end());
    for (auto s : strings) {
        cout << s << endl;
    }
}

void backtracking(string str, vector<string>& strings, int pos) {

    if (pos == int(str.length() - 1)) {
        strings.push_back(str);
        return;
    }
    
    str.insert(pos + 1, " ");
    backtracking(str, strings, pos + 2);
    
    str.erase(pos + 1, 1);
    backtracking(str, strings, pos + 1);
}

int main() {

    string s;

    while (cin >> s) {

        vector<string> result;
        backtracking(s, result, 0);
        print_result(result);
        cout << "\n";

    }

    return 0;
}