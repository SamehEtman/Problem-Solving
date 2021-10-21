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
    ll sum = 0;
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        sum += arr[i];
        mp[arr[i]]++;
    }
    if (2 * sum % n != 0) {
        cout << 0 << endl;
        return;
    }
    ll ans = 0;
    int toFind = 2 * sum / n;
    for (int i = 0; i < n; i++) {
        int count = 2 * sum / n - arr[i];
        if (mp.count(count))
            ans += mp[count];
        if (count == arr[i])
            ans--;
    }
    cout << ans / 2 << endl;
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