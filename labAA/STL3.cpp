#include <bits/stdc++.h>

using namespace std;

struct comp {
    bool operator()(const pair <string, int> &lhs, const pair <string, int> &rhs) {
        if (lhs.second < rhs.second)
            return true;
        else if (lhs.second == rhs.second && lhs.first.compare(rhs.first) > 0)
            return true;
        return false;
    }
};

bool uppercase(string s) {
    if (s[0] >= 'A' && s[0] <= 'Z')
        return true;
    return false;
}

int main() {

    while (true) {

        map <string, string> tab;
        map <string, int> cont;
        set <string> rm;
        string input;
        string project;

        getline(cin, input);

        if (input == "0") 
            break;

        while (input != "1") {

            if (uppercase(input)) {
                project = input;
                cont[project] = 0;
            }

            else if (rm.count(input) == 0) {
                if (tab.count(input) == 0) {
                    tab[input] = project;
                    cont[project]++;
                }
                else if (tab[input] != project) {
                    cont[tab[input]]--;
                    rm.insert(input);
                }
            }

            getline(cin, input);

        }

        priority_queue <pair <string, int>, vector <pair <string, int>>, comp> pq;

        for (auto i = cont.begin(); i != cont.end(); i++) 
            pq.emplace(i->first, i->second);

        while (pq.size()) {
            auto top = pq.top();
            pq.pop();
            cout << top.first << " " << top.second << endl;
        }

    }

    return 0;
}