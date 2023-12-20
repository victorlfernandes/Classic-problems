#include <bits/stdc++.h>
using namespace std;

const int MAXM = 500;
const int MAXV = 1000;

int m, v;
int coins[MAXM];
int dp[MAXV+1];

int main() {

    int t;
    cin >> t;
    
    while (t--) {

        cin >> v >> m;
        for (int i = 0; i < m; i++) 
            cin >> coins[i];

        for (int i = 1; i <= v; i++) 
            dp[i] = INT_MAX;
        dp[0] = 0;

        for (int i = 0; i < m; i++) {
            for (int j = coins[i]; j <= v; j++) {
                dp[j] = min(dp[j], dp[j - coins[i]] + 1);
            }
        }

        cout << dp[v] << "\n";
    }

    return 0;
}
