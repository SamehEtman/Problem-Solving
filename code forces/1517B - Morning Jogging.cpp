#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define intMax 2147483647
#define vi vector<int>
#define LSOne(S) (S & (-S))

void solve() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> v(m);
    for (int i = 0; i < m; i++) {
        v[i].first = intMax;
        v[i].second = i;
    }
    for (int i = 0; i < n; i++) {
        vector<int> u(m);
        for (int j = 0; j < m; j++)
            cin >> u[j];

        sort(u.rbegin(), u.rend());
        sort(v.begin(), v.end());

        vector<int> ans(m);

        for (int j = 0; j < m; j++) {
            ans[v[j].second] = u[j];
            v[j].first = min(u[j], v[j].first);
        }

        for (int j = 0; j < m; j++)
            cout << ans[j] << " ";
        cout << endl;
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