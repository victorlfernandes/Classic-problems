#include <iostream>
#include <vector>

using namespace std;

// Function to determine the winner of the game
string findWinner(vector<int>& heaps) {
    int n = heaps.size();
    int xorSum = 0;
    int maxHeap = 0;

    // Calculating the XOR sum of all heap sizes and finding the maximum heap size
    for (int i = 0; i < n; i++) {
        xorSum ^= heaps[i];
        maxHeap = max(maxHeap, heaps[i]);
    }

    // If XOR sum is 0 and the maximum heap size is greater than 1,
    // the second player wins. Otherwise, the first player wins.
    // cout << xorSum;
    // cout << maxHeap;
    if (xorSum >= 0) {
        if (maxHeap > 1) {
            return "second";
        } else {
            return "first";
        }
    } else {
        return "first";
    }
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> heaps(n);
        for (int i = 0; i < n; i++) {
            cin >> heaps[i];
        }

        string result = findWinner(heaps);
        cout << result << endl;
    }

    return 0;
}
