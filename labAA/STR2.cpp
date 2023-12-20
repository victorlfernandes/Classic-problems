#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

vector<int> countDistinctSubstrings(const string& str) {
    int n = str.length();
    vector<int> result(n);

    unordered_set<string> substrings;

    for (int len = 1; len <= n; len++) {
        substrings.clear();

        for (int i = 0; i <= n - len; i++) {
            string substring = str.substr(i, len);
            substrings.insert(substring);
        }

        result[len - 1] = substrings.size();
    }

    return result;
}

int main() {
    string str;
    cin >> str;

    vector<int> distinctSubstrings = countDistinctSubstrings(str);

    for (int count : distinctSubstrings) {
        cout << count << " ";
    }

    cout << endl;

    return 0;
}
