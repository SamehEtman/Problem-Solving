#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define intMax 2147483647
#define vi vector<int>
#define LSOne(S) (S & (-S))

void solve() {
    ll n;
    cin >> n;
    string s;
    cin >> s;
    ll x = 0, y = 0, z = 0;
    ll t, i;
    for (i = 0; i < n; i++) {
        if (s[i] == 'T')
            x++;
        if (s[i] == 'M')
            y++;
        if (x < y || x - y > n / 3)
            z = 1;
    }
    if ((z == 0 && 2 * y == x))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
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