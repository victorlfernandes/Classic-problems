#include <iostream>
#include <vector>

using namespace std;

vector<int> computeFailureFunction(const string& pattern) {
    
    int m = pattern.length();
    vector<int> failure(m, 0);
    int j = 0;

    for (int i = 1; i < m; i++) {
        if (pattern[i] == pattern[j]) {
            j++;
            failure[i] = j;
        } else {
            if (j != 0) {
                j = failure[j - 1];
                i--;
            } else {
                failure[i] = 0;
            }
        }
    }

    return failure;
}

int countPatternOccurrences(const string& text, const string& pattern) {
    int n = text.length();
    int m = pattern.length();
    vector<int> failure = computeFailureFunction(pattern);

    int i = 0, j = 0;
    int count = 0;

    while (i < n) {
        if (pattern[j] == text[i]) {
            j++;
            i++;
        }

        if (j == m) {
            count++;
            j = failure[j - 1];
        } else if (i < n && pattern[j] != text[i]) {
            if (j != 0) {
                j = failure[j - 1];
            } else {
                i++;
            }
        }
    }

    return count;
}

int main() {
    string text, pattern;
    cin >> text >> pattern;

    int occurrences = countPatternOccurrences(text, pattern);
    cout << occurrences << endl;

    return 0;
}
