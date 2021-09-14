#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define intMax 2147483647
#define vi vector<int>
#define LSOne(S) (S & (-S))

const int mod = 1e9 + 7;

int n, e;
void solve() {
    cin >> n >> e;
    vector<int> bigger(n + 1, 0);
    int ans = n;
    for (int i = 0; i < e; i++) {
        int a, b;
        cin >> a >> b;
        int u = min(a, b);
        bigger[u]++;
        if (bigger[u] == 1)
            ans--;
    }
    int q;
    cin >> q;
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int a, b;
            cin >> a >> b;
            int u = min(a, b);
            bigger[u]++;
            if (bigger[u] == 1)
                ans--;
        } else if (type == 2) {
            int a, b;
            cin >> a >> b;
            int u = min(a, b);
            bigger[u]--;
            if (bigger[u] == 0)
                ans++;
        } else {
            cout << ans << endl;
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tc = 1;
    // cin >> tc;
    while (tc--) {
        solve();
    }
}