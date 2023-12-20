#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    long long int from;
    long long int to;
    long long int cost;

    bool operator<(const Edge& other) const {
        return cost < other.cost;
    }
};

struct UnionFind {
    vector<long long int> parent;
    vector<long long int> rank;

    UnionFind(long long int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (long long int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    long long int find(long long int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unite(long long int x, long long int y) {
        long long int rootX = find(x);
        long long int rootY = find(y);

        if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        } else if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        } else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
    }
};


long long int minimumReparationCost(long long int n, vector<Edge>& edges) {
    sort(edges.begin(), edges.end());

    UnionFind uf(n);
    long long int totalCost = 0;

    for (const auto& edge : edges) {
        long long int from = edge.from;
        long long int to = edge.to;
        long long int cost = edge.cost;

        if (uf.find(from) != uf.find(to)) {
            uf.unite(from, to);
            totalCost += cost;
        }
    }

    // Check if all cities are in the same connected component
    long long int root = uf.find(0);
    for (long long int i = 1; i < n; ++i) {
        if (uf.find(i) != root) {
            return -1;  // IMPOSSIBLE
        }
    }

    return totalCost;
}

int main() {
    long long int n, m;
    cin >> n >> m;

    vector<Edge> edges(m);
    for (long long int i = 0; i < m; ++i) {
        cin >> edges[i].from >> edges[i].to >> edges[i].cost;
    }

    long long int result = minimumReparationCost(n, edges);
    if (result == -1)
        cout << "IMPOSSIBLE" << endl;
    else
        cout << result << endl;

    return 0;
}
