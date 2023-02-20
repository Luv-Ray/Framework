#include <bits/stdc++.h>
#define int long long
#define endl '\n'
typedef long long LL;
typedef unsigned long long ULL;
using std::cin, std::cout;
constexpr double EPS = 1e-8;
constexpr int INF = 0x3f3f3f3f;

constexpr int N = 1e6 + 10;

void solve() {
    // solve
    int x, y;
    cin >> x >> y;

    cout << (x - y) * 2 << endl;
    for (int i = x; i >= y; i--) cout << i << ' ';
    for (int i = y + 1; i < x; i++) cout << i << ' ';
    cout << endl;
}

signed main() {
    std::iostream::sync_with_stdio(false); cin.tie(nullptr);
    int t = 1;
    cin >> t;

    for (int i = 1; i <= t; i++) {
        // cout << "Case " << i << ":" << endl;
        solve();
    }
    return 0;
}