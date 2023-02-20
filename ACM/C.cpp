#include <bits/stdc++.h>
// #define int long long
#define endl '\n'
typedef long long LL;
typedef unsigned long long ULL;
using std::cin, std::cout;
constexpr double EPS = 1e-8;
constexpr int INF = 0x3f3f3f3f;

constexpr int N = 1e6 + 10;

int a[N];

void solve() {
    // solve
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    int l = 1, r = n;
    int mi = 1, ma = n;
    while (l < r) {
        if (a[l] == mi) {
            mi++;
            l++;
        } 
        else if (a[l] == ma) {
            l++;
            ma--;
        }
        else if (a[r] == mi) {
            r--;
            mi++;
        }
        else if (a[r] == ma) {
            r--;
            ma--;
        }
        else break;
    }

    if (l < r) cout << l << ' ' << r << endl;
    else cout << -1 << endl;
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