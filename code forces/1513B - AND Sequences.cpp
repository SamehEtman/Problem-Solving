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
    int arr[n];
    int mini = intMax;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        mini = min(mini, arr[i]);
    }
    ll count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == mini)
            count++;
        if ((arr[i] & mini) != mini) {
            cout << 0 << endl;
            return;
        }
    }
    ll fact = 1;
    for (int i = 1; i <= n - 2; i++)
        fact = (fact * i) % mod;
    count = (count * (count - 1)) % mod;
    ll ans = ((count) * (fact)) % mod;
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