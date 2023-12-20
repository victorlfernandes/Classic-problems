#include <iostream>

using namespace std;

int main() {

	int n_bachelors = 0;
	int n_spinsters = 0;

	int counter = 1;

	while (cin >> n_bachelors >> n_spinsters) {

		if (n_bachelors == 0 && n_spinsters == 0) break;

		int youngest_bachelor = 10000;
		int x = 0;
		for (int i = 0; i < n_bachelors; i++) {
			cin >> x;
			youngest_bachelor = min(x, youngest_bachelor);
		}

		for (int i = 0; i < n_spinsters; i++)
			cin >> x;

		if (n_bachelors <= n_spinsters) 
			cout << "Case " << counter++ << ": " << 0 << endl;
		else
			cout << "Case " << counter++ << ": " << n_bachelors - n_spinsters << " " << youngest_bachelor << endl;

	}

	return 0;
}