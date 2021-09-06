#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define intMax 2147483647
#define vi vector<int>
#define LSOne(S) (S & (-S))

const int mod = 1e9 + 7;
vector<string> powers;
void precalc() {
    for (ll i = 1; i <= 1e18; i *= 2) {
        powers.push_back(to_string(i));
    }
}
ll countDiff(string s, string x) {
    int idx1 = 0, idx2 = 0, common = 0;
    while (idx1 < s.size() && idx2 < x.size()) {
        if (s[idx1] == x[idx2]) {
            common++;
            idx2++;
        }
        idx1++;
    }
    return s.size() - common + x.size() - common;
}
void solve() {
    string s;
    cin >> s;
    ll ans = s.size() + 1;
    for (string x : powers) {
        ans = min(ans, countDiff(s, x));
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tc = 1;
    cin >> tc;
    precalc();
    while (tc--)
        solve();
}