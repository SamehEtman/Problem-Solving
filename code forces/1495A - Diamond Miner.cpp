#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define intMax 2147483647
#define vi vector<int>
#define LSOne(S) (S & (-S))

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> miners, diamonds;
    for (int i = 0; i < 2 * n; i++) {
        int a, b;
        cin >> a >> b;
        if (a == 0)
            miners.push_back({a, abs(b)});
        else
            diamonds.push_back({abs(a), b});
    }
    sort(miners.begin(), miners.end());
    sort(diamonds.begin(), diamonds.end());
    long double ans = 0;
    for (int i = 0; i < n; i++) {
        ans += sqrt(pow((miners[i].first - diamonds[i].first), 2) +
                    pow((miners[i].second - diamonds[i].second), 2));
    }
    cout << fixed << setprecision(15) << ans << endl;
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