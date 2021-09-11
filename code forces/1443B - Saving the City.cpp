#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define intMax 2147483647
#define vi vector<int>
#define LSOne(S) (S & (-S))

const int mod = 1e9 + 7;

void solve() {
    int a, b, last = -1e5;
    cin >> a >> b;
    string s;
    cin >> s;
    ll ans = 0;
    for (int i = 0; i < (int)s.size(); i++) {
        if (s[i] == '1') {
            ans += min(a, (i - last - 1) * b);
            last = i;
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