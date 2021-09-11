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
    vector<pair<ll, ll>> primes;

    for (ll f = 2; f * f <= n; f++) {
        int count = 0;
        while (n % f == 0) {
            count++;
            n /= f;
        }
        primes.push_back({count, f});
    }
    if (n > 1)
        primes.push_back({1, n});
    sort(primes.rbegin(), primes.rend());

    vector<ll> ans(primes[0].first, primes[0].second);
    for (int i = 1; i < primes.size(); i++) {
        for (int j = 0; j < primes[i].first; j++) {
            ans.back() *= primes[i].second;
        }
    }
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
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