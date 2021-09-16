#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define intMax 2147483647
#define vi vector<int>
#define LSOne(S) (S & (-S))

const int mod = 1e9 + 7;
int d[100005];
long long ans;

void solve() {
    int n;
    cin >> n;
    ll arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    ll ans = arr[n - 1];
    for (ll i = 1; i < n; i++) {
        ans -= 1LL * (n - i) * (i) * (arr[i] - (i - 1 >= 0 ? arr[i - 1] : 0));
    }
    cout << ans << endl;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tc = 1;
    cin >> tc;
    while (tc--) {
        solve();
    }
}