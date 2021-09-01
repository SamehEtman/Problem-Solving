#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define intMax 2147483647
#define vi vector<int>
#define LSOne(S) (S & (-S))

void solve() {
    int n, u, v;
    cin >> n >> u >> v;
    vector<int> p(n + 1);
    int diff = 0;
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        if (i > 1)
            diff = max(diff, abs(p[i] - p[i - 1]));
    }

    if (diff > 1) {
        cout << 0 << endl;

    } else if (diff == 1) {
        cout << min(u, v) << endl;

    } else if (diff == 0) {
        cout << min(u + v, 2 * v) << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tc;
    cin >> tc;
    while (tc--)
        solve();
}