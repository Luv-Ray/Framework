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
    int a, b;
    int n, m;
    cin >> a >> b >> n >> m;

    int aa = a * m;
    int bb = b * (m + 1);
    
    int t = std::min(a, b);
    int tt = std::min(aa, bb);

    cout << tt * (n / (m + 1)) + t * (n % (m + 1)) << endl;
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