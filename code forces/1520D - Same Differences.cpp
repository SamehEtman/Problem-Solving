#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define intMax 2147483647
#define vi vector<int>
#define LSOne(S) (S & (-S))

void solve() {
    ll n;
    cin >> n;
    ll arr[n + 1];
    unordered_map<ll, ll> mp;
    for (int i = 1; i <= n; i++) {
        ll temp;
        cin >> temp;
        arr[i] = temp - i;
        mp[arr[i]]++;
    }
    ll ans = 0;
    for (auto i : mp) {
        if (i.second > 1) {
            ans += (ll)(i.second * (i.second - 1) / 2);
        }
    }
    cout << ans << endl;
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