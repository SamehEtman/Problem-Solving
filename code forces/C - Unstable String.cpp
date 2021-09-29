#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define intMax 2147483647
#define vi vector<int>
#define LSOne(S) (S & (-S))

const int mod = 1e9 + 7;
int d[100005];
long long ans;

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    int dp[n][2] = {};

    if (s[0] == '1')
        dp[0][1] = 1;
    else if (s[0] == '0')
        dp[0][0] = 1;
    else {
        dp[0][1] = 1;
        dp[0][0] = 1;
    }

    ll ans = 1;

    for (int i = 1; i < n; i++) {
        if (s[i] == '0')
            dp[i][0] = 1 + dp[i - 1][1];
        else if (s[i] == '1')
            dp[i][1] = 1 + dp[i - 1][0];
        else {
            dp[i][0] = 1 + dp[i - 1][1];
            dp[i][1] = 1 + dp[i - 1][0];
        }
        ans += max(dp[i][0], dp[i][1]);
    }

    cout << ans << endl;
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