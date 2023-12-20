#include <bits/stdc++.h>
#define llu long long int
using namespace std;
 
struct Point {
    llu x, y;
    bool operator<(Point p) {
        return x < p.x || (x == p.x && y < p.y);
    }
};
 
llu cross_product(Point O, Point A, Point B) {
    return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}
 
vector<Point> convex_hull(vector<Point> A) {
    
    int n = A.size(), k = 0;
 
    if (n <= 3)
        return A;
 
    vector<Point> ans(2 * n);
 
    sort(A.begin(), A.end());
 
    for (int i = 0; i < n; ++i) {
        while (k >= 2 && cross_product(ans[k - 2], ans[k - 1], A[i]) <= 0)
            k--;
        ans[k++] = A[i];
    }
 
    int t = k + 1;
    for (size_t i = n - 1; i > 0; --i) {
        while (k >= t && cross_product(ans[k - 2], ans[k - 1], A[i - 1]) <= 0)
            k--;
        ans[k++] = A[i - 1];
    }
 
    ans.resize(k - 1);
 
    return ans;
}
 
double dist(Point a, Point b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
 
double perimeter(vector<Point> ans) {

    double perimeter = 0.0;
    int n = ans.size();
 
    for (int i = 0; i < n - 1; i++) {
        perimeter += dist(ans[i], ans[i + 1]);
    }
 
    perimeter += dist(ans[0], ans[ans.size() - 1]);
 
    return perimeter;
}
 
int main()
{
    vector<Point> points;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        llu x, y;
        cin >> x >> y;
        points.push_back({x, y});
    }
 
    vector<Point> ans = convex_hull(points);
 
    cout << fixed << setprecision(6) << perimeter(ans) << "\n";
    return 0;
}