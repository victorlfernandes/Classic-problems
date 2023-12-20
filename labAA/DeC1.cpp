#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5+5; 
int n, a[MAXN], segtree[4*MAXN];

void build(int node, int left, int right) {
    if (left == right) {
        segtree[node] = a[left];
    } else {
        int mid = (left + right) / 2;
        build(node*2, left, mid);
        build(node*2+1, mid+1, right);
        segtree[node] = min(segtree[node*2], segtree[node*2+1]);
    }
}

int query(int node, int left, int right, int l, int r) {
    if (l > right || r < left) {
        return INT_MAX;
    }
    if (l <= left && right <= r) {
        return segtree[node];
    }
    int mid = (left + right) / 2;
    int left_min = query(node*2, left, mid, l, r);
    int right_min = query(node*2+1, mid+1, right, l, r);
    return min(left_min, right_min);
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    build(1, 0, n-1);
    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        int min_val = query(1, 0, n-1, l, r);
        cout << min_val << endl;
    }
    return 0;
}
