#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define intMax 2147483647
#define vi vector<int>
#define LSOne(S) (S & (-S))

const int mod = 1e9 + 7;

map<int, int> mp;
void calc(int n) {
    for (int i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            n /= i;
            mp[i]++;
        }
    }
    if (n != 1)
        mp[n]++;
}
void solve() {
    ll n;
    cin >> n;
    for (int i = 2; i <= n; i++) {
        calc(i);
    }
    ll ans = 1;
    for (auto x : mp) {
        ans *= (x.second + 1);
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