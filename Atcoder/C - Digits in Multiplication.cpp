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
    ll ans = intMax;
    for (ll i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            string a = to_string(i);
            string b = to_string(n / i);
            ans = min(ans, max((ll)a.size(), (ll)b.size()));
        }
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    solve();
}