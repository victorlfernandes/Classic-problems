#include <iostream>
#include <cstdio>
#include <queue>
#include <string>

using namespace std;

struct reg {

	int id;
	int tempo;
	int ogVal;

	bool operator<(const reg &r) const {
		if (tempo > r.tempo)
			return true;
		if (tempo == r.tempo && id > r.id)
			return true;
		return false;	
	}

};

void printQ(priority_queue <reg> q, int k) {

    priority_queue <reg> aux = q;
    reg r;
	reg n;
	int cont = 0;
    while (cont < k && !aux.empty()) {

        r = aux.top();
        cout << r.id << endl;
        aux.pop();
		
		n.id = r.id;
		n.tempo = r.tempo + r.ogVal;
		n.ogVal = r.ogVal;
		aux.push(n);

		cont++;

    }

}

int main() {

	priority_queue <reg> q;
	reg r;
	string word;

	while (true) {
	
		cin >> word;
		if (word == "#")
			break;

		else {
			cin >> r.id >> r.tempo;
			r.ogVal = r.tempo;
			q.push(r);
		}
	
	}

	int k = 0;
	cin >> k;

    printQ(q, k);

	return 0;
}