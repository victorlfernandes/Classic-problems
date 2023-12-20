#include <iostream>
#include <vector>
using namespace std;

string lcs(string s, string t) {
    int m = s.length();
    int n = t.length();

    vector<vector<string>> dp(m + 1, vector<string>(n + 1, ""));

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s[i - 1] == t[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + s[i - 1];
            } else {
                dp[i][j] = (dp[i - 1][j].length() > dp[i][j - 1].length()) ? dp[i - 1][j] : dp[i][j - 1];
            }
        }
    }

    return dp[m][n];
}

int main() {

    string s, t;
    cin >> s;
    cin >> t;

    string longestSubsequence = lcs(s, t);
    cout << longestSubsequence << endl;

    return 0;
}
