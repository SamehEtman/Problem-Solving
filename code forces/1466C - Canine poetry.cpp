#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define intMax 2147483647
#define vi vector<int>
#define LSOne(S) (S & (-S))

const int mod = 1e9 + 7;

void solve() {
    string s;
    cin >> s;
    bool visited[s.size()] = {};
    ll ans = 0;
    for (int i = 2; i < (int)s.size(); i++) {
        if (s[i] == s[i - 1] && !visited[i - 1]) {
            visited[i] = 1;
        }
        if (i > 2 && s[i] == s[i - 2] && !visited[i - 2]) {
            visited[i] = 1;
        }
        ans += visited[i];
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