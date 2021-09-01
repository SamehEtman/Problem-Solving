#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define intMax 2147483647
#define vi vector<int>
#define LSOne(S) (S & (-S))

void solve() {
    int n, m;
    cin >> n >> m;
    int arr[n];
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        mp[arr[i] % m]++;
    }
    int ans = 0;
    if (mp[0] >= 1) {
        ans++;
    }
    for (int i = 1; i < m; i++) {
        if (mp[i]) {
            if (abs(mp[i] - mp[m - i]) <= 1)
                ans++;
            else {
                ans += abs(mp[i] - mp[m - i]);
            }
            mp[m - i] = 0;
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