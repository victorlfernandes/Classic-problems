#include <bits/stdc++.h>

using namespace std;

int n, k;
int a[1000];

int solve(int l, int r) {

    int answer; 

    while (l <= r) {

        int mid = (l + r) / 2;
        int num = 0;
        int now = 0;

        for (int i = 0; i <= n; i++) {

            if (now + a[i] <= mid) 
                now += a[i];
            else {
                num++;
                now = a[i];
            }

        }

        num++;

        if (num <= k + 1) {
            r = mid - 1;
            answer = mid;
        }
        else 
            l = mid + 1;

    }

    return answer;
}

int main() {

    while (cin >> n >> k) {

        int total = 0;
        int maxi = 0;

        for (int i = 0; i < n + 1; i++) {
            cin >> a[i];
            total += a[i];
            maxi = max(maxi, a[i]);
        }

        int answer = solve(maxi, total);
        cout << answer << endl;

    }

    return 0;
}
