#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define intMax 2147483647
#define vi vector<int>
#define LSOne(S) (S & (-S))

const int mod = 1e9 + 7;

void solve() {
    ll n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        int idx = (n - arr[i] - 1) / 2;
        mp[idx]++;
        mp[n - 1 - idx]++;
    }
    ll ans = 1;
    for (auto x : mp) {
        if (x.second > 2) {
            cout << 0 << endl;
            return;
        }
    }
    for (int i = 1; i <= n / 2; i++) {
        ans *= 2;
        ans %= mod;
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    solve();
}