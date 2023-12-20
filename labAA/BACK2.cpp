#include <bits/stdc++.h>

using namespace std;

string solve(string M, int K) {

    string unsortedM = M;
    string result = M;

    sort(M.begin(), M.end());
    
    for (int i = 0; i < K && i < int(M.length()); i++) {

        char max_value = *(max_element(M.begin(), M.end() - i));
       
        int max_index = 0;
        for (int j = M.length(); j >= 0; j--) {
            if (unsortedM[j] == max_value) {
                max_index = j;
                break;
            }
        }

        result[max_index] = unsortedM[i];
        result[i] = max_value;

    }

    return result;
}

int main() {
    
    string M;
    int K;
    while (cin >> M >> K) {
        cout << solve(M, K) << endl;
    }

    return 0;
}
