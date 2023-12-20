#include <iostream>
#include <queue>

using namespace std;

int main() {

    int nTests;
    cin >> nTests;

    for (int i = 0; i < nTests; i++) {

        int nJobs, myPos;
        cin >> nJobs >> myPos;

        priority_queue <int> pq;
        int myJob; 
        for (int j = 0; j < nJobs; j++) {
            int x;
            cin >> x;
            if (j == myPos)
                myJob = x;
            pq.push(x);
        }

        int counter = 1;
        while (!pq.empty()) {
            int x = pq.top();
            if (x == myJob) {
                cout << counter << "\n";
                break;
            }
            pq.pop();
            counter++;
        }

    }

    return 0;
}