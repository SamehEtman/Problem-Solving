#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define intMax 2147483647
#define vi vector<int>
#define LSOne(S) (S & (-S))

const int mod = 1e9 + 7;

void solve() {
    int n, l, r;
    cin >> n >> l >> r;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    ll ans = 0;

    for (int i = 0; i < n; i++) {
        int idx1 =
            lower_bound(v.begin() + i + 1, v.end(), l - v[i]) - v.begin();
        int idx2 =
            upper_bound(v.begin() + i + 1, v.end(), r - v[i]) - v.begin();

        int pairs = idx2 - idx1;
        ans += pairs;
    }
    cout << ans << endl;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tc = 1;
    cin >> tc;
    while (tc--)
        solve();
}