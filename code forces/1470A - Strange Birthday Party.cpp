#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define intMax 2147483647
#define vi vector<int>
#define LSOne(S) (S & (-S))

const int mod = 1e9 + 7;

void solve() {
    int n, m;
    cin >> n >> m;
    int arr[n + 1];
    int gifts[m + 1];
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    for (int i = 1; i <= m; i++)
        cin >> gifts[i];
    sort(arr + 1, arr + n + 1);
    reverse(arr + 1, arr + n + 1);
    ll ans = 0;
    int idx = 1;

    for (int i = 1; i <= n; i++) {
        ll money = gifts[arr[i]];
        if (idx <= m) {
            if (money <= gifts[idx]) {
                ans += money;
            } else {
                ans += gifts[idx];
                idx++;
            }
        } else {
            ans += money;
        }
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