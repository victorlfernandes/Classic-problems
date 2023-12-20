#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minOp(string str1, string str2) {
    
    int m = str1.length();
    int n = str2.length();

    vector<vector<int>> pd(m + 1, vector<int>(n + 1, 0));

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0) {
                pd[i][j] = j;
            } else if (j == 0) {
                pd[i][j] = i;
            } else if (str1[i - 1] == str2[j - 1]) {
                pd[i][j] = pd[i - 1][j - 1];
            } else {
                pd[i][j] = min({pd[i][j - 1], pd[i - 1][j], pd[i - 1][j - 1]}) + 1;
            }
        }
    }

    return pd[m][n];
}

int main() {

    string str1, str2;
    cin >> str1;
    cin >> str2;

    cout << minOp(str1, str2) << endl;

    return 0;
}
