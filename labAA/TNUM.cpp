#include <iostream>
using namespace std;

const long long int MOD = 10000000;

int main() {
    long long int n;
    cin >> n;

    long long int numDivisors = 1;
    long long int sumDivisors = 1;
    long long int productDivisors = 1;

    for (long long int i = 0; i < n; i++) {
        long long int a, k;
        cin >> a >> k;

        // Calculate the number of divisors
        numDivisors = (numDivisors * (k + 1)) % MOD;

        // Calculate the sum of divisors
        long long int term = 1;
        long long int power = a;
        for (long long int j = 0; j < k; j++) {
            term = (term + power) % MOD;
            power = (power * a) % MOD;
        }
        sumDivisors = (sumDivisors * term) % MOD;

        // Calculate the product of divisors
        power = a;
        for (long long int j = 0; j < k; j++) {
            productDivisors = (productDivisors * power) % MOD;
            power = (power * a) % MOD;
        }
    }

    cout << numDivisors << " " << sumDivisors << " " << productDivisors << endl;

    return 0;
}
