#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {

    vector <int> v;
    int x = 0;
    int n = 0;

    while (cin >> x) {

        v.push_back(x);
        n++;

        if (n == 1)
            cout << x << endl;

        else if (n % 2 != 0) {

            nth_element(v.begin(), v.begin() + (n / 2), v.end());
            cout << v[n / 2] << endl;

        }

        else {

            nth_element(v.begin(), v.begin() + (n / 2) - 1, v.end());
            long long int n1 = v[n / 2 - 1];
            nth_element(v.begin(), v.begin() + (n / 2), v.end());
            long long int n2 = v[n / 2];
            long long int s = (n1 + n2) / 2; 
            cout << s << endl;

        }

    }        

    return 0;
}
