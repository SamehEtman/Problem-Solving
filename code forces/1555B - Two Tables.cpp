#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define intMax 2147483647
#define vi vector<int>
#define LSOne(S) (S & (-S))

const int mod = 1e9 + 7;

void solve() {
    int W, H;
    cin >> W >> H;
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int maxWidth = W - (c - a), maxHeight = H - (d - b);
    int w, h;  // 3 2 // 2 2
    cin >> w >> h;
    if (w > maxWidth && h > maxHeight) {
        cout << -1 << endl;
        return;
    }
    ll ans = intMax;
    if (w <= maxWidth) {
        ans = min(ans, (ll)max(0, w - a));
        ans = min(ans, (ll)max(0, c - (W - w)));
    }
    if (h <= maxHeight) {
        ans = min(ans, (ll)max(0, h - b));
        ans = min(ans, (ll)max(0, d - (H - h)));
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