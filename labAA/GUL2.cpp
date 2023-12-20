#include <bits/stdc++.h>

using namespace std;

bool compare(pair <pair <int, int>, int> job1, pair <pair <int, int>, int> job2) {

    int a = job1.first.first * job2.first.second;
    int b = job2.first.first * job1.first.second;
    
    if (a == b) 
        return (job1.second < job2.second);
    else
        return (a < b);
}

int main() {

    int n_cases = 0;
    cin >> n_cases;

    for (int i = 0; i < n_cases; i++) {

        int n_jobs = 0;
        cin >> n_jobs;

        pair <pair <int, int>, int> jobs[1001]; // <<time, fine>, index>
        for (int j = 0; j < n_jobs; j++) {
            cin >> jobs[j].first.first >> jobs[j].first.second;
            jobs[j].second = j + 1;
        }

        sort(jobs, jobs + n_jobs, compare);

        for (int j = 0; j < n_jobs - 1; j++)
            cout << jobs[j].second << " ";
        cout << jobs[n_jobs - 1].second << endl;
        if (i != n_cases - 1) cout << "\n";

    }

    return 0;
}