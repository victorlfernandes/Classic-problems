#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

struct Edge {
    int to;
    int weight;
};

vector<int> dijkstra(int start, int n, vector<vector<Edge>>& graph) {
    vector<int> distance(n + 1, INF);
    distance[start] = 0;

    vector<bool> visited(n + 1, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        int u = pq.top().second;
        // int d = pq.top().first;
        pq.pop();

        if (visited[u]) {
            continue;
        }

        visited[u] = true;

        for (const auto& edge : graph[u]) {
            int v = edge.to;
            int w = edge.weight;

            if (!visited[v] && distance[u] + w < distance[v]) {
                distance[v] = distance[u] + w;
                pq.push({distance[v], v});
            }
        }
    }

    return distance;
}

int main() {
    int n, m, q;
    cin >> n >> m >> q;

    vector<vector<Edge>> graph(n + 1);

    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }

    for (int i = 0; i < q; ++i) {
        int a, b;
        cin >> a >> b;

        vector<int> distance = dijkstra(a, n, graph);
        int shortestRoute = distance[b];

        if (shortestRoute == INF) {
            cout << -1 << endl;
        } else {
            cout << shortestRoute << endl;
        }
    }

    return 0;
}
