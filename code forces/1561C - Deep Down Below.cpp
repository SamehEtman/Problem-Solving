#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define intMax 2147483647
#define vi vector<int>
#define LSOne(S) (S & (-S))

const int mod = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<pair<ll, ll>> v;
    for (int z = 0; z < n; z++) {
        ll x = 0, s;
        cin >> s;
        for (int i = 0; i < s; i++) {
            ll temp;
            cin >> temp;
            x = max(x, temp - i + 1);
        }
        v.push_back({x, s});
    }
    sort(v.begin(), v.end());
    ll x = 0, sum = 0;
    for (int i = 0; i < n; i++) {
        x = max(x, v[i].first - sum);
        sum += v[i].second;
    }
    cout << x << endl;
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