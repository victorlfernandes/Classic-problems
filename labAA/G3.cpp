#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> graph;
vector<int> colors;
bool isPossible;

void dfs(int node, int color) {
    colors[node] = color;

    for (int neighbor : graph[node]) {
        if (colors[neighbor] == 0) {
            dfs(neighbor, 3 - color);
        } else if (colors[neighbor] == color) {
            isPossible = false;
            return;
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    graph.resize(n + 1);
    colors.resize(n + 1);

    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    isPossible = true;

    for (int i = 1; i <= n; ++i) {
        if (colors[i] == 0) {
            dfs(i, 1);
        }
    }

    if (!isPossible) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        for (int i = 1; i <= n; ++i) {
            cout << (colors[i] == 1 ? 1 : 2) << " ";
        }
        cout << endl;
    }

    return 0;
}
